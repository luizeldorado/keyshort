#include <vector>
#include <string>
#include <algorithm>

#include <windows.h>
#include <stdio.h>

#include "vksMap.cpp"

// Definition loading

struct KeyShortDef {
	std::vector<DWORD> heldKeys;
	DWORD mainKey;
	std::string command;
};

std::vector<KeyShortDef> defs;

enum DefLoadingSections { NONE, KEYS, COMMAND };

DWORD getKeyFromString(std::string str) {

    str.erase(0, str.find_first_not_of(" "));
    str.erase(str.find_last_not_of(" ") + 1);

	std::transform(str.begin(), str.end(), str.begin(), ::tolower);

	if (vksMap.count(str)) {

		DWORD key = vksMap.at(str);
		printf("[%s] %lu ", str.c_str(), key);
		return key;

	} else {

		DWORD key = strtoul(str.c_str(), NULL, 16);
		if (key == 0) {
			printf("NaN ");
		} else {
			printf("%lu ", key);
		}
		return key;
	}
	
}

void loadDefs(char * fileName) {

	emplaceVKsMap();

	FILE * file = fopen(fileName, "r");

	if (file == NULL) {
		printf("Failed to open %s!\n", fileName);
		exit(1);
	}

	KeyShortDef * currentDef;

	enum DefLoadingSections section = NONE;
	std::string token;
	char c;

	while ((c = fgetc(file)) != EOF) {

		if (section == NONE) {
			printf("\ndefinition:");
			printf("\n\theld keys: ");

			currentDef = new KeyShortDef;
			section = KEYS;
		}

		if (section == KEYS) {
			if (c == ',') {
				DWORD key = getKeyFromString(token);

				currentDef -> heldKeys.push_back(key);
				token = "";
				continue;
			} else if (c == '=') {
				printf("\n\tmain key: ");

				DWORD key = getKeyFromString(token);

				currentDef -> mainKey = key;
				token = "";
				section = COMMAND;
				continue;
			}
		}

		if (section == COMMAND) {
			if (c == '\n') {
				printf("\n\tcommand: %s", token.c_str());

				currentDef -> command = token;
				defs.push_back(*currentDef);

				token = "";
				section = NONE;
				continue;
			}
		}

		token += c;

	}

	fclose(file);
	clearVKsMap();

	if (section == KEYS) {
		printf("\nWARNING: file ended before finishing definition\n", token.c_str());

		delete currentDef;
	}
	if (section == COMMAND) {
		printf("\n\tcommand: %s", token.c_str());

		currentDef -> command = token;
		defs.push_back(*currentDef);
	}

	printf("\n%i defs loaded\n", defs.size());

}

// Keyboard hooking

HHOOK keyboardHook;

LRESULT keyboardHookProc(int code, WPARAM wParam, LPARAM lParam) {

	if (code == HC_ACTION) {
		if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {

			KBDLLHOOKSTRUCT hookStruct = *((KBDLLHOOKSTRUCT*) lParam);

			// printf("%u\n", hookStruct.vkCode);

			for (std::vector<KeyShortDef>::iterator def = defs.begin();
				def != defs.end(); ++def) {

				if (def -> mainKey == hookStruct.vkCode) {
					bool allHeld = true;

					for (std::vector<DWORD>::iterator heldKey = def -> heldKeys.begin();
						heldKey != def -> heldKeys.end(); ++heldKey) {

						if (!(GetKeyState(*heldKey) & 0x8000)) {
							allHeld = false;
							break;
						}
					}

					if (allHeld) {
						printf("Executing '%s'...\n", def -> command.c_str());

						system(def -> command.c_str());
					}
				}
			}

		}
	} else {
		printf("code = %i\n", code);
	}

	return CallNextHookEx(keyboardHook, code, wParam, lParam);
}

DWORD WINAPI keyboardHookThreadProc(LPVOID lpParameter) {

	keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC) keyboardHookProc, NULL, 0);

	MSG message;
	while (GetMessage(&message, NULL, 0, 0)) {
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	UnhookWindowsHookEx(keyboardHook);

	return 0;
}

void hookKeyboard() {
	HANDLE hThread = CreateThread(NULL, 0, keyboardHookThreadProc, NULL, 0, NULL);

	if (hThread) {
		WaitForSingleObject(hThread, INFINITE);
	}
}

// Main
int main(int argc, char * argv[]) {
	
	if (argc >= 2) {
		loadDefs(argv[1]);
		hookKeyboard();
	} else {
		printf(
			"Executes commands when keys are pressed.\n"
			"Usage: %s <file>\n"
			"Format of file:\n"
			"  <key 1>,<key 2>,<...>,<final key>=<command>\n"
			"  <...>\n"
			"<key> can be a hex number (e.g. 0x2C) or a name described in keynames.txt\n"
		, argv[0]);
	}

	return 0;
}