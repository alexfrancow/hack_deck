# hack_deck

<p align="center"><img src="https://raw.githubusercontent.com/alexfrancow/hack_deck/main/bg/1_2.png" height="320" width="480" /></p>

Create the following layout in photoshop:
```
Width: 320px
Height: 480px
```
Export to .png

Open Nextion Editor, select model ```NX4832K035_011```.

Nextion Enhanced NX4832K035 3.5 Inch HMI Intelligent Smart USART UART Serial Touch Screen TFT LCD Module
https://www.banggood.com/Nextion-Enhanced-NX4832K035-3_5-Inch-HMI-Intelligent-Smart-USART-UART-Serial-Touch-Screen-TFT-LCD-Module-p-1188732.html?rmmds=myorder


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
> Very important select "Touch Release Event"!

* Clone the button
* ```Debug``` to show the simulator return
* Compile
<p align="center"><img src="https://github.com/alexfrancow/hack_deck/blob/main/images/debugger.png" height="480" width="720" /></p>

Copy the ```C:\Users\alexfrancow\AppData\Roaming\Nextion Editor\work\a-2021211914282\output\test.tft``` to the SD card. Make sure that you only have that file in the SD card.

### Export TFT from nextion IDE

File -> TFT File Output -> Output

## Arduino

### Nextion library

Modify the SoftwareSerial:

```c
1. In your libraries folder (C:\Users\alexfrancow\Documents\Arduino\libraries\ITEADLIB_Arduino_Nextion-master), find the Nextion library.
2. Find the file called NexConfig.h and right click on it and click edit.
3. Find line 37 that says   #define nexSerial Serial2 
4. Delete or comment out that line and replace it with the following: 
#include <SoftwareSerial.h>
extern SoftwareSerial HMISerial;
#define nexSerial HMISerial
```

Board: "Arduino Micro"

### Connections

|Arduino|Display|
|---|---|
|9|RX|
|8|TX|
|VCC|+5V|
|GND|GND|
