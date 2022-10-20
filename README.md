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
6. Open .vscode folder and specify path to gcc-arm-none-eabi and openocd in c_cpp_prroperties.json and settings.json. Also edit paths to config files in launch.json. 
7. Press Shift+Cmd+B, then select "Make Build".
8. Press F5 to debug.
9. Profit!

The repo contains both examples for STM32F103C8T6 chip (almost all bluepills assembled with it) and for STM32F103C6T6 (this chip has much more available price).
The differrence between them is that C6T6 have 32K flash (vs 64K on C8T6) and 10K RAM (vs 20K on C8T6). So with C6T6 you shall use a bit different bit linker script and asm startup file. Examples do have correct ones for each other, so both of them must work out of the box.

