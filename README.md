
# keyshort.exe
Executes commands when keys are pressed.

Download Windows binary: https://github.com/luizeldorado/keyshort/raw/master/keyshort.exe

Usage: `keyshort <file>`

Format of file:
  `<key 1>,<key 2>,<...>,<final key>=<command>`
  `<...>`

`<key>` can be a hex number (e.g. 0x2C) or a name described in [keynames.txt](https://github.com/luizeldorado/keyshort/raw/master/keynames.txt)

`-` (minus sign) before the final key means that the key must be released, instead of pressed.
