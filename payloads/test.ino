#include "DigiKeyboard.h"

void setup() {
  // Empty setup
}

void loop() {
  // 1. Wait for Windows to mount the USB device
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(0);

  // 2. Maximize Volume (Optional but funny)
  // This loop presses the "Volume Up" key 50 times
  for (int i = 0; i < 50; i++) {
    DigiKeyboard.sendKeyStroke(0xED); // HID code for Volume Up
    DigiKeyboard.delay(10);
  }

  // 3. Open the "Run" dialog
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);

  // 4. Type the Rickroll URL and press Enter
  // This command opens the link in the default browser
  DigiKeyboard.print("https://www.youtube.com/watch?v=hhvW8qB-W3M");
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // 5. Wait a moment and then make the video full screen (Press 'f')
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_F);

  // Stop the script from repeating
  for(;;){ /* empty */ }
}
