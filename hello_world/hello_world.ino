#include <Keyboard.h>

//A simple hello world payload

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
  Keyboard.print(" ");
  Keyboard.releaseAll();
  delay(500);

  Keyboard.print("textedit");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1000);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.print("n");
  Keyboard.releaseAll();

  delay(500);
  
  Keyboard.print("Hello world");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.end();
}

void loop() {
}
