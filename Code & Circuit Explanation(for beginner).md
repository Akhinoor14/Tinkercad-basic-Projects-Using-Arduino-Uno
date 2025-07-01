# 🧠 Code & Circuit Explanation (for beginner) – Project 20: Light Intensity Measurement with Arduino

এই প্রজেক্টে Arduino UNO দিয়ে LDR-এর আলো এতটুকু জানতে পারবে, LED উজ্জ্বলতা বাড়া-কমা এবং Serial Monitor-এ ভোল্টেজ দেখা যাবে।

## 1. 🎒 যা লাগবে (What You Need)

| Component            | Quantity | Description                              |
|-----------------------|----------|------------------------------------------|
| Arduino UNO          | 1        | Controller board                         |
| LDR (Photoresistor)  | 1        | Light-dependent resistor                 |
| LED                  | 1        | Visual feedback via PWM                  |
| 10 kΩ Resistor       | 1        | Voltage divider fixed resistor           |
| 220 Ω Resistor       | 1        | LED current limiting resistor            |
| Breadboard + Jumper Wires | as needed | Prototype connections               |
| Multimeter           | 1        | To verify voltage                        |
| USB Cable / 5V Supply| 1        | Power source for Arduino                 |

## 2. 🔌 Circuit Connections (Easy Format)

| Arduino Pin | Component                   | Connection Details                                      |
|-------------|-----------------------------|---------------------------------------------------------|
| 5 V         | LDR one leg                 | +5 V power                                              |
| A0          | LDR other leg → Node A      | Node A reads divider voltage                            |
| Node A      | 10 kΩ resistor → GND        | Completes voltage divider                               |
| D9 (PWM)    | LED anode → 220 Ω → D9      | LED cathode → GND through 220 Ω resistor                |
| GND         | LDR, resistors, LED ground  | Common ground                                           |

> Node A হল LDR আর 10 kΩ রেজিস্টরের মাঝে যাংশন, এখানে ভোল্টেজ analogRead() এ আসে।

## 3. 🧠 Reason Behind the Connection & How It Works

- LDR + 10 kΩ দিয়ে একটি ভোল্টেজ ডিভাইডার তৈরি হয়, যেখানে Node A-তে আলো বাড়লে ভোল্টেজ বাড়ে।  
- Arduino analogRead() A0 থেকে 0–1023 রেঞ্জে মান নেয়, যা ভোল্টেজের প্রোপোরশনাল।  
- `map()` ফাংশন দিয়ে ADC মানকে 0–255 PWM রেঞ্জে রূপান্তর করি, LED-এ analogWrite() দিয়ে উজ্জ্বলতা নিয়ন্ত্রণ করি।  
- Serial Monitor-এ ভোল্টেজ দেখালে মাল্টিমিটার ছাড়া ও ভোল্টেজ রিয়েল-টাইমে জানা যায়।  

## 4. 📝 ধাপে ধাপে কী হচ্ছে

1. setup() এ `pinMode(D9, OUTPUT)` এবং `Serial.begin(9600)` করা হয়।  
2. loop() এ `analogRead(A0)` → sensorValue নেওয়া হয়।  
3. voltage = sensorValue × (5.0/1023) → ভোল্টেজ হিসাব করা হয়।  
4. brightness = map(sensorValue, 0, 1023, 0, 255) → PWM মান পাওয়া যায়।  
5. `analogWrite(D9, brightness)` → LED উজ্জ্বলতা সেট হয়।  
6. Serial.print() দিয়ে voltage Monitor-এ পাঠাই, delay(500) দিয়ে আপডেট প্রতি আধ সেকেন্ডে।  

# 🔍 Code Breakdown – Project 20: Light Intensity Measurement (Arduino)

এই কোডে আমরা LDR-এর মাধ্যমে আলো পরিমাপ করব, LED-এর ব্রাইটনেস আঁদ্রুস্ত করব, আর Serial Monitor-এ ভোল্টেজ দেখাবো।

---

## 🔌 Pin Declarations

| Name        | Pin       | Purpose                             |
|-------------|-----------|-------------------------------------|
| `ldrPin`    | A0        | Voltage divider input from LDR      |
| `ledPin`    | D9 (PWM)  | LED brightness control via PWM      |

---

## ⚙️ setup()

- `pinMode(ledPin, OUTPUT);`  
  ➤ LED চালানোর জন্য D9 কে OUTPUT হিসেবে সেট করা হয়  
- `Serial.begin(9600);`  
  ➤ Serial Monitor-এ ভোল্টেজ দেখাবো, 9600 baud rate

---

## 🔁 loop()

1. `sensorValue = analogRead(ldrPin);`  
   ➤ A0 থেকে 0–1023 এর মধ্যে মান পায় LDR voltage divider থেকে  

2. `voltage = sensorValue * (5.0 / 1023.0);`  
   ➤ ADC মানকে ভোল্টে রূপান্তর করে (Arduino 10-bit ADC, Vref=5V)

3. `brightness = map(sensorValue, 0, 1023, 0, 255);`  
   ➤ ADC reading কে PWM duty-cycle এ ম্যাপ করে (0–255)

4. `analogWrite(ledPin, brightness);`  
   ➤ LED-এ সেই PWM পাঠিয়ে ব্রাইটনেস প্রয়োগ

5. Serial prints:  
   - `Serial.print("Light Voltage: ");`  
   - `Serial.print(voltage);`  
   - `Serial.println(" V");`  
   ➤ বর্তমান LDR voltage Serial Monitor-এ দেখানো হয়

6. `delay(500);`  
   ➤ প্রতি 0.5 সেকেন্ডে আপডেট, দ্রুত কিন্তু চোখে ফ্লিকার কম

---

## 🎯 Logic Summary

- LDR + fixed resistor দিয়ে **voltage divider** তৈরি  
- ভোল্টেজ analogue read করে আলো পরিমাপ  
- LED PWM output দিয়ে ভিজ্যুয়াল ফিডব্যাক  
- Serial Monitor-এ মাপা voltage দিয়ে মাল্টিমিটার ছাড়া ও পরিমাপ যাচাই করা যায়  




## 5. ✨ এই প্রজেক্টে কী হবে?

- ভোল্টেজ ডিভাইডার ও ADC রিডিং নিয়ে ধারণা পাবে।  
- PWM দ্বারা LED উজ্জ্বলতা নিয়ন্ত্রণ শেখবে।  
- Serial Monitor-এ রিয়েল-টাইম sensor data দেখতে পারবে।  
- মাল্টিমিটার দিয়ে কোডের সাথে রিডিং মিলিয়ে Troubleshooting শিখবে।  

## 6. 🚦 এখন নিজে চেষ্টা করো!

- Breadboard-এ LDR + 10 kΩ voltage divider set up করো।  
- LED ও 220 Ω রেজিস্টর D9 এ connect করো।  
- কোড আপলোড করে Serial Monitor খুলো।  
- আলোর বিভিন্ন উৎসে LDR expose করে voltage ও LED উজ্জ্বলতা পরীক্ষা করো।  
- মাল্টিমিটারে Node A-র voltage নাপিয়ে কোডের রিডিং যাচাই করো।  
```
