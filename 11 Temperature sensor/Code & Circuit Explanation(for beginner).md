# 🔌 Circuit Connections (TMP36 → Arduino UNO)

🔌 সার্কিট কানেকশন (Circuit Connection)
==========================

**তোমার যা লাগবে:**
- Arduino UNO
- TMP36 Temperature Sensor
- Jumper Wires

**কানেকশন টেবিল:**

| TMP36 Pin | Arduino Pin | কাজ/ব্যাখ্যা                |
|-----------|-------------|-----------------------------|
| VCC       | 5V          | Power input                 |
| GND       | GND         | Ground                      |
| Vout      | A0          | Analog output to Arduino    |

📌 **বিশেষ টিপস:**
- TMP36 sensor 0°C-তে 0.5V দেয়, এবং প্রতি 1°C বাড়লে ~10mV বাড়ে  
- যেমন: 25°C হলে Vout ≈ 0.75V

✨ এই প্রজেক্টে কী হবে?
==========================
- TMP36 temperature sensor দিয়ে Arduino UNO-তে তাপমাত্রা মাপা শিখবে
- Celsius, Fahrenheit, এবং Kelvin—তিন ইউনিটেই তাপমাত্রা দেখতে পারবে

💡 কোড ব্যাখ্যা (Code Explanation)
==========================

| অংশ | কী বোঝায়? |
|------|-----------|
| `const int tempPin = A0;` | TMP36 sensor-এর output Arduino-র A0 analog pin-এ নেওয়া হয়েছে |
| `analogRead(tempPin);` | 0–5V analog voltage → 0–1023 digital মানে রূপান্তর করে |
| `voltage = sensorValue * (5.0 / 1023.0);` | ADC মানকে actual voltage-এ রূপান্তর করা হচ্ছে |
| `temperature = (voltage - 0.5) * 100.0;` | TMP36-এর formula অনুযায়ী Celsius হিসাব করা হচ্ছে (1°C = 10mV) <br> উদাহরণ: 0.75V → (0.75–0.5)×100 = 25°C |
| `temperatureF = (temperature * 9.0 / 5.0) + 32.0;` | Celsius থেকে Fahrenheit-এ রূপান্তর |
| `temperatureK = temperature + 273.15;` | Celsius থেকে Kelvin-এ রূপান্তর |
| `Serial.print()` / `Serial.println()` | Real-time temperature Serial Monitor-এ দেখা যায় |
| `delay(2000);` | প্রতি ২ সেকেন্ড পর পর নতুন temperature value নেওয়া হয় |

📝 ধাপে ধাপে কী হচ্ছে (Step-by-Step)
==========================
1. TMP36 sensor-এর VCC, GND, Vout যথাযথভাবে সংযুক্ত করো
2. analogRead() দিয়ে Vout-এর মান পড়ো (A0 pin)
3. sensorValue থেকে voltage হিসাব করো
4. voltage থেকে Celsius temperature বের করো
5. চাইলে Fahrenheit ও Kelvin-এ রূপান্তর করো
6. Serial Monitor-এ মান দেখো
7. delay() দিয়ে প্রতি ২ সেকেন্ড পর পর আপডেট করো

✅ এই প্রজেক্টে যা শিখবে
==========================
- TMP36 দিয়ে তাপমাত্রা মাপা
- analogRead() ও voltage calculation
- Temperature unit conversion (Celsius, Fahrenheit, Kelvin)
- Serial Monitor-এ মান দেখা

🚦 এখন নিজে চেষ্টা করো!
==========================
- সার্কিট বানাও
- কোড আপলোড করো
- দেখো কিভাবে temperature মান বদলায়!

