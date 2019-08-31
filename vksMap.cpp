#include <unordered_map>
#include <windows.h>

std::unordered_map<std::string, DWORD> vksMap;

void emplaceVKsMap() {

	vksMap["back"] = 0x08;
	vksMap["backspace"] = 0x08;

	vksMap["tab"] = 0x09;
	vksMap["clear"] = 0x0C;

	vksMap["return"] = 0x0D;
	vksMap["enter"] = 0x0D;

	vksMap["shift"] = 0x10;

	vksMap["control"] = 0x11;
	vksMap["ctrl"] = 0x11;

	vksMap["menu"] = 0x12;
	vksMap["alt"] = 0x12;

	vksMap["pause"] = 0x13;

	vksMap["capital"] = 0x14;
	vksMap["capslock"] = 0x14;

	vksMap["kana"] = 0x15;
	vksMap["hanguel"] = 0x15;
	vksMap["hangul"] = 0x15;
	vksMap["junja"] = 0x17;
	vksMap["final"] = 0x18;
	vksMap["hanja"] = 0x19;
	vksMap["kanji"] = 0x19;

	vksMap["escape"] = 0x1B;
	vksMap["esc"] = 0x1B;

	vksMap["convert"] = 0x1C;
	vksMap["nonconvert"] = 0x1D;
	vksMap["accept"] = 0x1E;
	vksMap["modechange"] = 0x1F;

	vksMap["space"] = 0x20;
	vksMap["spacebar"] = 0x20;

	vksMap["prior"] = 0x21;
	vksMap["pageup"] = 0x21;

	vksMap["next"] = 0x22;
	vksMap["pagedown"] = 0x22;

	vksMap["end"] = 0x23;
	vksMap["home"] = 0x24;
	vksMap["left"] = 0x25;
	vksMap["up"] = 0x26;
	vksMap["right"] = 0x27;
	vksMap["down"] = 0x28;
	vksMap["select"] = 0x29;
	vksMap["print"] = 0x2A;
	vksMap["execute"] = 0x2B;

	vksMap["snapshot"] = 0x2C;
	vksMap["printscreen"] = 0x2C;

	vksMap["insert"] = 0x2D;
	vksMap["ins"] = 0x2D;

	vksMap["delete"] = 0x2E;
	vksMap["del"] = 0x2E;

	vksMap["help"] = 0x2F;
	vksMap["0"] = 0x30;
	vksMap["1"] = 0x31;
	vksMap["2"] = 0x32;
	vksMap["3"] = 0x33;
	vksMap["4"] = 0x34;
	vksMap["5"] = 0x35;
	vksMap["6"] = 0x36;
	vksMap["7"] = 0x37;
	vksMap["8"] = 0x38;
	vksMap["9"] = 0x39;
	vksMap["a"] = 0x41;
	vksMap["b"] = 0x42;
	vksMap["c"] = 0x43;
	vksMap["d"] = 0x44;
	vksMap["e"] = 0x45;
	vksMap["f"] = 0x46;
	vksMap["g"] = 0x47;
	vksMap["h"] = 0x48;
	vksMap["i"] = 0x49;
	vksMap["j"] = 0x4A;
	vksMap["k"] = 0x4B;
	vksMap["l"] = 0x4C;
	vksMap["m"] = 0x4D;
	vksMap["n"] = 0x4E;
	vksMap["o"] = 0x4F;
	vksMap["p"] = 0x50;
	vksMap["q"] = 0x51;
	vksMap["r"] = 0x52;
	vksMap["s"] = 0x53;
	vksMap["t"] = 0x54;
	vksMap["u"] = 0x55;
	vksMap["v"] = 0x56;
	vksMap["w"] = 0x57;
	vksMap["x"] = 0x58;
	vksMap["y"] = 0x59;
	vksMap["z"] = 0x5A;

	// TODO make this check both keys
	vksMap["win"] = 0x5B; 
	vksMap["windows"] = 0x5B;

	vksMap["lwin"] = 0x5B;
	vksMap["lwindows"] = 0x5B;

	vksMap["rwin"] = 0x5C;
	vksMap["rwindows"] = 0x5C;

	vksMap["apps"] = 0x5D;
	vksMap["sleep"] = 0x5F;
	vksMap["numpad0"] = 0x60;
	vksMap["numpad1"] = 0x61;
	vksMap["numpad2"] = 0x62;
	vksMap["numpad3"] = 0x63;
	vksMap["numpad4"] = 0x64;
	vksMap["numpad5"] = 0x65;
	vksMap["numpad6"] = 0x66;
	vksMap["numpad7"] = 0x67;
	vksMap["numpad8"] = 0x68;
	vksMap["numpad9"] = 0x69;
	vksMap["multiply"] = 0x6A;
	vksMap["add"] = 0x6B;
	vksMap["separator"] = 0x6C;
	vksMap["subtract"] = 0x6D;
	vksMap["decimal"] = 0x6E;
	vksMap["divide"] = 0x6F;
	vksMap["f1"] = 0x70;
	vksMap["f2"] = 0x71;
	vksMap["f3"] = 0x72;
	vksMap["f4"] = 0x73;
	vksMap["f5"] = 0x74;
	vksMap["f6"] = 0x75;
	vksMap["f7"] = 0x76;
	vksMap["f8"] = 0x77;
	vksMap["f9"] = 0x78;
	vksMap["f10"] = 0x79;
	vksMap["f11"] = 0x7A;
	vksMap["f12"] = 0x7B;
	vksMap["f13"] = 0x7C;
	vksMap["f14"] = 0x7D;
	vksMap["f15"] = 0x7E;
	vksMap["f16"] = 0x7F;
	vksMap["f17"] = 0x80;
	vksMap["f18"] = 0x81;
	vksMap["f19"] = 0x82;
	vksMap["f20"] = 0x83;
	vksMap["f21"] = 0x84;
	vksMap["f22"] = 0x85;
	vksMap["f23"] = 0x86;
	vksMap["f24"] = 0x87;
	vksMap["numlock"] = 0x90;
	vksMap["scroll"] = 0x91;
	vksMap["scrolllock"] = 0x91;

	vksMap["lshift"] = 0xA0;
	vksMap["rshift"] = 0xA1;

	vksMap["lcontrol"] = 0xA2;
	vksMap["lctrl"] = 0xA2;

	vksMap["rcontrol"] = 0xA3;
	vksMap["rctrl"] = 0xA3;

	vksMap["lmenu"] = 0xA4;
	vksMap["lalt"] = 0xA4;

	vksMap["rmenu"] = 0xA5;
	vksMap["ralt"] = 0xA5;

	vksMap["browser_back"] = 0xA6;
	vksMap["browser_forward"] = 0xA7;
	vksMap["browser_refresh"] = 0xA8;
	vksMap["browser_stop"] = 0xA9;
	vksMap["browser_search"] = 0xAA;
	vksMap["browser_favorites"] = 0xAB;
	vksMap["browser_home"] = 0xAC;
	vksMap["volume_mute"] = 0xAD;
	vksMap["volume_down"] = 0xAE;
	vksMap["volume_up"] = 0xAF;
	vksMap["media_next_track"] = 0xB0;
	vksMap["media_prev_track"] = 0xB1;
	vksMap["media_stop"] = 0xB2;
	vksMap["media_play_pause"] = 0xB3;
	vksMap["launch_mail"] = 0xB4;
	vksMap["launch_media_select"] = 0xB5;
	vksMap["launch_app1"] = 0xB6;
	vksMap["launch_app2"] = 0xB7;
	vksMap["oem_1"] = 0xBA;
	vksMap["oem_plus"] = 0xBB;
	vksMap["oem_comma"] = 0xBC;
	vksMap["oem_minus"] = 0xBD;
	vksMap["oem_period"] = 0xBE;
	vksMap["oem_2"] = 0xBF;
	vksMap["oem_3"] = 0xC0;
	vksMap["oem_4"] = 0xDB;
	vksMap["oem_5"] = 0xDC;
	vksMap["oem_6"] = 0xDD;
	vksMap["oem_7"] = 0xDE;
	vksMap["oem_8"] = 0xDF;
	vksMap["oem_102"] = 0xE2;
	vksMap["processkey"] = 0xE5;
	// vksMap["packet"] = 0xE7;
	vksMap["attn"] = 0xF6;
	vksMap["crsel"] = 0xF7;
	vksMap["exsel"] = 0xF8;
	vksMap["ereof"] = 0xF9;
	vksMap["play"] = 0xFA;
	vksMap["zoom"] = 0xFB;
	// vksMap["noname"] = 0xFC;
	vksMap["pa1"] = 0xFD;
	vksMap["oem_clear"] = 0xFE;

}

void clearVKsMap() {
	vksMap.clear();
}