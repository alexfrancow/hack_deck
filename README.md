# hack_deck
# badusb_botnetv2

<p align="center"><img src="https://raw.githubusercontent.com/alexfrancow/hack_deck/main/bg/1_2.png" height="500" width="825" /></p>

Gimp new project:
```
Width: 320px
Height: 480px
```
Export to .png

Open Nextion Editor, select model

Nextion Enhanced NX4832K035 3.5 Inch HMI Intelligent Smart USART UART Serial Touch Screen TFT LCD Module
https://www.banggood.com/Nextion-Enhanced-NX4832K035-3_5-Inch-HMI-Intelligent-Smart-USART-UART-Serial-Touch-Screen-TFT-LCD-Module-p-1188732.html?rmmds=myorder

NX4832K035_011

Preinitialize event

```
dims=50
```

Configure the button:
```
Add the picture
Add button --> Atribute --> sta = crop image
           |-> picc = black.png
           |-> picc2 = white.png
           |-> txt = ""
           |-> Event -> Touch Release Event -> [x] Send component ID
```
*Clone the button
*Debug to show the simulator return
*Compile

Copy the ```C:\Users\alexfrancow\AppData\Roaming\Nextion Editor\work\a-2021211914282\output\numPad.tft``` to the SD card. Make sure that you only have that file in the SD card.


## Arduino

```
1. In your libraries folder, find the Nextion library.
2. Find the file called NexConfig.h and right click on it and click edit.
3. Find line 37 that says   #define nexSerial Serial2 
4. Delete or comment out that line and replace it with the following: 
#include <SoftwareSerial.h>
extern SoftwareSerial HMISerial;
#define nexSerial HMISerial
```
