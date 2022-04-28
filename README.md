# stm32-vscode-blinky
 Minimalistic CMSIS blinky example for VSCode just to check that everything is fine.
 Works fine with MacOS, but you can easily port it to Linux or Windows by editing paths.
 I used ST-Link as debug hardware, but you can try using J-Link and other stuff. It might request some conf files editing.
 Setup:
1. Install openocd. 
If you are using Mac, open Terminal app and type "brew install openocd".
2. Install gcc-arm toolchain. I recommend you to download it as archive and unpack any place you like (for example, usr/local).
3. Add both to path.
4. Install Microsoft C/C++ and Cortex-Debug by marus25 extensions for VSCode.
5. Drag'n'drop project folder to VSCode.
6. Open .vscode folder and specify path to gcc-arm-none-eabi and openocd in c_cpp_prroperties.json annd settings.json.
7. Press Shift+Cmd+B, then select "Make Build".
8. Press F5 to debug.
9. Profit!

