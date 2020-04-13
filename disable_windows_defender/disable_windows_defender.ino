#include <Keyboard.h>

#define SHORT_DELAY 600
#define LONG_DELAY 1000

//Very finicky, navigates the settings and disables Windows Defender, you're
//probably better off just doing it manually

void setup() {
  Serial.begin(9600);

  pinMode(3, INPUT_PULLUP);
  if (digitalRead(3) == LOW) {
    Serial.print("aborting\n");
    abort();
  }

  Keyboard.begin();
  delay(3000);

  //Open settings
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();
  delay(LONG_DELAY);
  Keyboard.print("Virus & threat protection");
  delay(LONG_DELAY);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(LONG_DELAY);

  //navigate to the protection settings
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
  delay(SHORT_DELAY);
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
  delay(SHORT_DELAY);
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
  delay(SHORT_DELAY);
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
  delay(SHORT_DELAY);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(LONG_DELAY);

  //disable a radio button
  Keyboard.print(" ");
  Keyboard.releaseAll();
  delay(SHORT_DELAY);
  Keyboard.press(KEY_LEFT_ARROW);
  Keyboard.releaseAll();
  delay(SHORT_DELAY);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(LONG_DELAY);

  //close everything
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  Keyboard.releaseAll();
              
  Keyboard.end();
}

void loop() {
}
