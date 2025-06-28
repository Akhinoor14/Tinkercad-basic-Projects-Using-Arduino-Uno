==========================
🔰 শেখার পয়েন্ট (What You'll Learn)
==========================
- **analogRead()**: কিভাবে potentiometer-এর value পড়া যায়
- **if / else if**: কিভাবে বিভিন্ন LED trigger করা যায় বিভিন্ন voltage level এ
- **Voltage threshold**: কিভাবে কিছু value অনুযায়ী ব্লিঙ্ক করানো যায়
- **Serial Monitor**: analog value debug করার জন্য
- **পিনের ব্যবহার**: A0 analog input, D2–D6 digital output কেন ও কিভাবে

==========================
🛠️ সার্কিট গাইড (Circuit Guide)
==========================
**Potentiometer:**
- এক পাশ → 5V (Arduino)
- অন্য পাশ → GND
- মাঝের পিন → A0 pin

**LEDs:**
- ৫টি LED → D2–D6 pins (প্রত্যেকটির সাথে 220Ω resistor)
- LED-এর ছোট পা → GND লাইনে

**Breadboard:**
- Arduino UNO-এর GND → Breadboard-এর GND লাইনে
- Breadboard-এর – লাইন → Arduino GND

==========================
🧑‍💻 কোড ব্যাখ্যা (Step-by-Step Code Explanation)
==========================

--------------------------
1️⃣ ভেরিয়েবল ডিক্লেয়ারেশন (Variable Declaration)
--------------------------
```cpp
const int potPin = A0;              // Potentiometer-এর middle pin A0 তে লাগানো
const int leds[] = {2, 3, 4, 5, 6}; // ৫টা LED D2–D6 পিনে লাগানো হয়েছে
```
- **potPin**: A0 পিনকে represent করে
- **leds[]**: ৫টি LED-এর পিন নম্বর রাখা হয়েছে

--------------------------
2️⃣ সেটআপ ফাংশন (setup())
--------------------------
```cpp
void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT); // প্রতিটি LED পিনকে output হিসেবে সেট করছি
  }
  Serial.begin(9600); // Serial Monitor চালু করছি debug করার জন্য
}
```
- **setup()**: শুধু একবার চলে Arduino চালু হলে
- **pinMode()**: প্রতিটি LED পিনকে output বানানো হয়েছে
- **Serial.begin()**: potentiometer-এর value দেখতে পারবো Serial Monitor-এ

--------------------------
3️⃣ লুপ ফাংশন (loop())
--------------------------
```cpp
void loop() {
  int potValue = analogRead(potPin); // potentiometer থেকে analog value নিচ্ছি (0–1023)
  Serial.println(potValue);          // সেই value print করছি monitor-এ

  // ভোল্টেজ অনুযায়ী LED জ্বলে
  if (potValue < 200) {
    digitalWrite(leds[0], HIGH);  // শুধু প্রথম LED জ্বলবে
    for (int i = 1; i < 5; i++) digitalWrite(leds[i], LOW);
  }
  else if (potValue < 400) {
    for (int i = 0; i < 2; i++) digitalWrite(leds[i], HIGH);
    for (int i = 2; i < 5; i++) digitalWrite(leds[i], LOW);
  }
  // ...এভাবে আরও ধাপে ধাপে LED জ্বলবে...

  delay(300); // ৩০০ মিলিসেকেন্ড অপেক্ষা করে আবার loop শুরু হবে
}
```
- **analogRead()**: potentiometer-এর ভোল্টেজ রিড করছে (0 মানে 0V, 1023 মানে 5V)
- **if/else if**: ভোল্টেজ অনুযায়ী কয়টা LED জ্বলবে ঠিক করছে
- **delay()**: একটু বিরতি, যেন LED blink করে

==========================
🎯 সংক্ষেপে (In Short)
==========================
- Potentiometer ঘুরালে analog value বদলায়
- সেই value অনুযায়ী LED গুলো জ্বলে/বন্ধ হয়
- Serial Monitor-এ value দেখতে পারো

==========================
✅ Try it Yourself!
==========================
- Breadboard-এ সার্কিট বানাও
- কোড আপলোড করো
- Potentiometer ঘুরিয়ে দেখো LED কিভাবে জ্বলে!