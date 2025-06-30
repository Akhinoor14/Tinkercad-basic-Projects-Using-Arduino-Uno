# 🔌 Circuit Connections

| Component            | Arduino Pin / Connection         | Description                                      |
|----------------------|----------------------------------|--------------------------------------------------|
| ATtiny85 VCC         | Step-Up Converter Output (5V) (+) | Powers the ATtiny85 from boosted voltage         |
| ATtiny85 GND         | Common Ground                  (-) | Ground for ATtiny85 and all components           |
| LCD GND              | Ground                         (-) | LCD ground                                       |
| LCD VCC              | Step-Up Converter Output (5V)  (+) | Powers the LCD                                   |
| LCD V0               | Common Ground                  (-) |                                                  |
| LCD RS               | ATtiny85 Digital Pin PB0         | Register Select pin                              |
| LCD RW               | Common Ground                  (-) |                                                  |
| LCD E                | ATtiny85 Digital Pin PB1         | Enable pin                                       |
| LCD D4               | ATtiny85 Digital Pin PB2         |                                                  |
| LCD D5               | ATtiny85 Digital Pin PB3         |                                                  |
| LCD D6               | ATtiny85 Digital Pin PB4         |                                                  |
| LCD D7               | ATtiny85 Digital Pin (PB5)         |                                                  |
| LED Cathode            |  Common Ground  (-) |                                                  |
| LCD Anode          | 220Ω resistor →Step-Up Converter Output (5V)  (+) | Powers the LED                                   |
| Battery (+)          | Step-Up Converter Input (+)      | 5V AA battery input power                        |
| Battery (–)          | Step-Up Converter Input (–)      | Battery ground                                   |

📌 **Note:**  
- Use a **step-up converter (MT3608)** to boost 1.5V from the battery to 5V for the ATtiny85 and LCD.  
- You can use an **LCD I2C backpack** to save pins (uses only two pins, e.g. A4/A5, if using software I2C).

---

# 🧠 Code Explanation (Line by Line)

| Code Line / Block                           | What It Does (Bangla Explanation)                                  |
|---------------------------------------------|--------------------------------------------------------------------|
| `LiquidCrystal lcd(RS, E, D4, D5, D6, D7);` | কোন পিনগুলো LCD-তে সংযুক্ত তা বলে দেয়                           |
| `lcd.begin(16, 2);`                         | ১৬x২ LCD চালু করে                                                  |
| `lcd.setCursor(col, row);`                  | LCD-র নির্দিষ্ট স্থানে কার্সর নেয়                                  |
| `lcd.print("text");`                        | LCD-তে লেখা বা সংখ্যা দেখায়                                         |
| `millis();`                                 | Arduino চালু হওয়ার পর থেকে কত ms হয়েছে তা জানায় (ঘড়ির মতো)         |
| টাইম ক্যালকুলেশন (mm:ss)                    | millis() দিয়ে মিনিট ও সেকেন্ড হিসাব করে LCD-তে দেখায়              |

---

# 📝 Step-by-Step (কাজের ধাপ)

1. সার্কিট টেবিল অনুযায়ী সব কম্পোনেন্ট সংযুক্ত করো।
2. কোডে LCD-এর জন্য সঠিক পিন দিয়ে `LiquidCrystal lcd(...)` লিখো।
3. `setup()`-এ:
   - `lcd.begin(16, 2);` দিয়ে LCD চালু করো।
   - প্রথম লাইনে ও দ্বিতীয় লাইনে তোমার মেসেজ প্রিন্ট করো।
4. `loop()`-এ:
   - `millis()` দিয়ে কত সময় (মিনিট:সেকেন্ড) হয়েছে হিসাব করো।
   - প্রতি সেকেন্ডে শুধু দ্বিতীয় লাইনের শেষ ৪ অক্ষর (`mm:ss`) আপডেট করো।
   - `lcd.setCursor()` দিয়ে কার্সর ঠিক জায়গায় নাও, তারপর সময় প্রিন্ট করো।

---

# 🎯 Display Format (Target)

| LCD Line | What to Show                |
|----------|-----------------------------|
| Line 1   | this is Akhinoor            |
| Line 2   | welcome mm:ss               |

- দ্বিতীয় লাইনের শেষ ৪ অক্ষর (`mm:ss`) প্রতি সেকেন্ডে আপডেট হবে।

---

# ✅ এই প্রজেক্টে যা শিখবে

- কিভাবে ১৬x২ LCD ATtiny85-এ সংযুক্ত ও চালু করতে হয়।
- কিভাবে স্টেপ-আপ কনভার্টার দিয়ে ১.৫V ব্যাটারি থেকে ৫V বানাতে হয়।
- কিভাবে LCD-তে লেখা ও সময় (মিনিট:সেকেন্ড) দেখাতে হয়।

---

# 🚦 এখন নিজে চেষ্টা করো!
- সার্কিট বানাও
- কোড আপলোড করো
- LCD-তে মেসেজ ও সময় দেখো!