# 🔌 Circuit Connections

| Component        | Arduino Pin | Description                          |
|------------------|-------------|--------------------------------------|
| Photodiode (+)   | A0          | Analog signal input (via resistor)   |
| Photodiode (–)   | GND         | Connected to Ground                  |
| 10kΩ Resistor    | Between A0 and GND | Forms voltage divider        |
| VCC              | +5V         | Through photodiode (if needed)       |

📌 Typical setup: Photodiode connected in reverse-bias mode with a resistor forming a voltage divider circuit. The analog voltage varies with light intensity.

---

# 🧠 Code Explanation (line by line)

- `const int sensorPin = A0;`  
  ▸ Photodiode-র সিগন্যাল Arduino-এর A0 পিনে আসবে।

- `analogRead(sensorPin);`  
  ▸ এই ফাংশনে light intensity অনুযায়ী একটা মান পাওয়া যাবে (0–1023)।

- `Serial.begin(9600);`  
  ▸ Arduino ও PC-এর মাঝে সিরিয়াল কমিউনিকেশন শুরু হয়।

- `Serial.print()` এবং `Serial.println()`  
  ▸ Light এর মান মনিটরে দেখা যায় real-time এ।

- `delay(500);`  
  ▸ প্রতি ০.৫ সেকেন্ড পর পর নতুন মান পড়া হয়।

---

✨ এই প্রজেক্টে কী হবে?
==========================
- Photodiode দিয়ে Arduino UNO-তে আলো (light intensity) মাপা শিখবে
- আলো কম-বেশি হলে analog মান কিভাবে বদলায়, সেটা দেখতে পারবে

🔌 সার্কিট কানেকশন (Circuit Connection)
==========================
**যা লাগবে:**
- Arduino UNO
- ১টি Photodiode
- ১টি 10kΩ resistor
- Jumper Wires

**কানেকশন:**
| Component        | Arduino Pin | কাজ/ব্যাখ্যা                         |
|------------------|-------------|--------------------------------------|
| Photodiode (+)   | A0          | Analog signal input (resistor দিয়ে)  |
| Photodiode (–)   | GND         | Ground                               |
| 10kΩ Resistor    | A0 ↔ GND    | Voltage divider তৈরি করে            |
| VCC              | +5V         | Photodiode-এ (প্রয়োজনে)             |

**নোট:** সাধারণভাবে photodiode কে reverse-bias mode-এ resistor দিয়ে voltage divider বানিয়ে সংযুক্ত করা হয়। আলো বাড়লে/কমলে analog voltage বদলায়।

💡 কোড ব্যাখ্যা (Code Explanation)
==========================

| অংশ | কী বোঝায়? |
|------|-----------|
| `const int sensorPin = A0;` | Photodiode-র সিগন্যাল Arduino-এর A0 পিনে আসবে |
| `analogRead(sensorPin);` | আলো অনুযায়ী analog মান (0–1023) পাওয়া যাবে |
| `Serial.begin(9600);` | Arduino ও PC-এর মাঝে সিরিয়াল কমিউনিকেশন শুরু হয় |
| `Serial.print()` / `Serial.println()` | আলো কতটা পড়ছে, সেটা মনিটরে দেখা যায় |
| `delay(500);` | প্রতি ০.৫ সেকেন্ড পর পর নতুন মান পড়া হয় |

📝 ধাপে ধাপে কী হচ্ছে (Step-by-Step)
==========================
1. Photodiode ও resistor দিয়ে voltage divider বানাও
2. Photodiode (+) পা A0-তে, (–) পা GND-তে সংযুক্ত করো
3. analogRead() দিয়ে আলো অনুযায়ী মান পড়ো
4. Serial Monitor-এ মান দেখো (print)
5. delay() দিয়ে প্রতি ০.৫ সেকেন্ড পর পর মান আপডেট করো

✅ এই প্রজেক্টে যা শিখবে
==========================
- Photodiode দিয়ে আলো মাপা
- analogRead() ব্যবহার
- voltage divider কীভাবে কাজ করে
- Serial Monitor-এ মান দেখা

🚦 এখন নিজে চেষ্টা করো!
==========================
- সার্কিট বানাও
- কোড আপলোড করো
- আলো কমালে/বাড়ালে মান কিভাবে বদলায় দেখো!


