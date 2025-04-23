
#  Windows Defender Bypass & Reverse Shell Dropper

This script is designed to run on a Digispark/Arduino Leonardo-style USB device that emulates a keyboard. It disables Windows Defender, elevates privileges via PowerShell, downloads a remote shell payload, and establishes a reverse shell connection to a remote host.

---

##  Features

- Opens Windows Defender threat settings and attempts to disable protection
- Elevates to admin PowerShell via UAC bypass
- Downloads a reverse shell payload (`nc64.exe`)
- Executes the shell in a hidden/minimized command prompt
- Connects back to a remote listener

---

## ⚙️ Requirements

- Digispark or Arduino Leonardo/Micro with USB HID support
- Arduino IDE
- `Keyboard.h` library
- Local reverse shell listener (e.g., `nc -lvnp 4444` on attacker's machine)
- HTTP server hosting `nc64.exe` at `http://<IP>/nc64.exe`

---

## 🧪 Usage

1. Flash the code onto a compatible Digispark or HID-enabled Arduino board.
2. Plug the device into the target system.
3. Reverse shell will be attempted and connected to the IP `<IP>` on port `4444`.

---

## ⚠️ Legal Disclaimer

This tool is meant for **authorized** penetration testing, red teaming, or educational purposes only. Using this code against machines you do not own or have explicit written permission to test may violate laws and regulations.

---

## 🛠️ Potential Improvements

Here are a few enhancements or changes you could implement:

1. **Error Handling / Checkpoints:**
   - Use `timeout`/`try`/`catch` logic in the PowerShell script to detect if a command fails or is blocked.

2. **Stealth Enhancements:**
   - Obfuscate the PowerShell commands (`iex`, `Base64`, etc.)
   - Minimize all windows after execution to hide evidence.

3. **Dynamic Payload Delivery:**
   - Generate a randomized folder and file name for payload storage.
   - Use HTTPS and domain names instead of IPs for command-and-control (C2) infrastructure.

4. **UAC Bypass Variants:**
   - Use alternate bypass techniques (e.g., `fodhelper.exe`, `eventvwr.exe`) for privilege escalation.

5. **Payload Persistence:**
   - Add logic to establish persistence (e.g., adding to startup or registry).

6. **Reduce Static Delays:**
   - Use conditional waits, like checking for window titles or system responses, instead of static `delay()` times.

7. **Evade Defender Smarter:**
   - Consider registry-level disabling of Defender features using PowerShell:
     ```powershell
     Set-MpPreference -DisableRealtimeMonitoring $true
     ```

---

## 🔐 Security Reminder

This project showcases the power of USB HID devices for red teaming but also the severe risks they pose if misused. Always operate within ethical and legal boundaries.

