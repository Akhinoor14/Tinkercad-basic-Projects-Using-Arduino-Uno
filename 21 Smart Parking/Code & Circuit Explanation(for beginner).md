# 🧠 Code & Circuit Explanation (for beginner) – Project 21: Smart Parking System using Arduino

এই প্রজেক্টে আমরা একটি স্মার্ট পার্কিং সিস্টেম তৈরি করব যেখানে গাড়ি প্রবেশ ও প্রস্থান শনাক্ত করা হবে IR সেন্সরের মাধ্যমে, গেট খুলবে সার্ভো মোটর দিয়ে, এবং LCD তে পার্কিং স্লটের অবস্থা দেখানো হবে।

---

## 1. 🎒 যা লাগবে (What You Need)

| Component             | Quantity | Description                                 |
|------------------------|----------|---------------------------------------------|
| Arduino UNO           | 1        | Main controller board                       |
| IR Sensor Module      | 4        | Entry, Exit, Slot 1, Slot 2 detection       |
| Servo Motor (SG90)    | 2        | Entry & Exit gate control                   |
| 16x2 LCD (parallel)   | 1        | Display for slot status                     |
| Potentiometer         | 1        | Optional: manual override or threshold set  |
| Breadboard + Jumper Wires | as needed | For connections                        |
| USB Cable / 5V Supply | 1        | Power for Arduino                           |

---

## 2. 🔌 Circuit Connections (pin-to-pin details)

| Arduino Pin | Connected To                  | Description                                |
|-------------|-------------------------------|--------------------------------------------|
| D6          | Entry IR sensor OUT           | Detects vehicle at entry                   |
| D13         | Exit IR sensor OUT            | Detects vehicle at exit                    |
| D7          | Slot 1 IR sensor OUT          | Detects car in parking slot 1              |
| D8          | Slot 2 IR sensor OUT          | Detects car in parking slot 2              |
| D9          | Entry Servo signal (S1)       | Controls entry gate                        |
| D10         | Exit Servo signal (S2)        | Controls exit gate                         |
| D12–D2      | LCD RS, E, D4–D7              | Parallel LCD control pins                  |
| A0–A5       | Potentiometer (optional)      | Analog input for future use                |
| 5V / GND    | All sensors, LCD, servo power | Power supply and common ground             |

> **Note:** IR সেন্সরগুলো LOW output দেয় যখন সামনে কিছু থাকে (obstacle detected)। Servo গুলো 0° মানে বন্ধ, 90° মানে খোলা।

---

## 3. 🧠 Reason Behind the Connection & How It Works

- **Entry IR (D6):** গাড়ি এলে detect করে → Entry Servo (D9) গেট খোলে  
- **Exit IR (D13):** গাড়ি বের হলে detect করে → Exit Servo (D10) গেট খোলে  
- **Slot IRs (D7, D8):** প্রতিটি slot এ গাড়ি থাকলে তা detect করে → LCD তে “Occupied” দেখায়  
- **LCD (D12–D2):** 16x2 ডিসপ্লেতে দুই লাইনে Slot 1 ও Slot 2 এর অবস্থা দেখায়  
- **Potentiometer (A4):** ভবিষ্যতে threshold বা ম্যানুয়াল override হিসেবে ব্যবহার করা যেতে পারে  

---

## 4. 📝 ধাপে ধাপে কী হচ্ছে (Step-by-Step Workflow)

1. `setup()` এ Serial Monitor, LCD, Servo ও IR সেন্সর initialize হয়  
2. Entry IR (D6) → LOW হলে Entry Servo 90° → গেট খোলে → delay → আবার 0°  
3. Exit IR (D13) → LOW হলে Exit Servo 90° → গেট খোলে → delay → আবার 0°  
4. Slot 1 ও Slot 2 IR → LOW হলে LCD তে “Occupied”, HIGH হলে “Free”  
5. LCD তে প্রতি 0.5 সেকেন্ডে স্লট স্ট্যাটাস আপডেট হয়  
6. Serial Monitor এ প্রতিটি সেন্সরের রিয়েল-টাইম স্ট্যাটাস দেখা যায়  

---

## 5. ✨ এই প্রজেক্টে কী হবে (Project Outcome)

- গাড়ি প্রবেশ ও প্রস্থান শনাক্ত করতে পারবে  
- Servo দিয়ে গেট স্বয়ংক্রিয়ভাবে খোলা ও বন্ধ হবে  
- LCD তে পার্কিং স্লটের অবস্থা (Free/Occupied) দেখা যাবে  
- Serial Monitor দিয়ে রিয়েল-টাইম ডিবাগিং করা যাবে  
- Real-world smart parking system-এর ধারণা তৈরি হবে  

---

# 🔍 Code Breakdown – Project 21: Smart Parking System

এই কোডে আমরা ৪টি IR সেন্সর দিয়ে গাড়ির উপস্থিতি শনাক্ত করব, ২টি সার্ভো দিয়ে গেট কন্ট্রোল করব, এবং LCD তে স্লট স্ট্যাটাস দেখাবো।

---

## 📌 Pin Declarations

| Name         | Pin  | Description                          |
|--------------|------|--------------------------------------|
| `IR_Slot1`   | D7   | Slot 1 IR sensor                     |
| `IR_Slot2`   | D8   | Slot 2 IR sensor                     |
| `IR_entry`   | D6   | Entry IR sensor                      |
| `IR_exit`    | D13  | Exit IR sensor                       |
| `S1`         | D9   | Entry gate servo                     |
| `S2`         | D10  | Exit gate servo                      |
| `lcd`        | D12–D2 | LCD control pins (RS, E, D4–D7)   |

---

## ⚙️ setup()

- `Serial.begin(9600);`  
  ➤ Serial Monitor initialize করে debugging এর জন্য

- `lcd.begin(16, 2);`  
  ➤ 16x2 LCD initialize করা হয়

- `pinMode(..., INPUT);`  
  ➤ IR সেন্সরগুলোকে ইনপুট হিসেবে সেট করা হয়

- `S1.attach(9);`, `S2.attach(10);`  
  ➤ Servo মোটর গুলো নির্দিষ্ট পিনে অ্যাটাচ করা হয়

- `lcd.print("System Ready");`  
  ➤ শুরুতে LCD তে স্ট্যাটাস দেখানো হয়

---

## 🔁 loop()

### 🚗 Slot Detection

- `digitalRead(IR_Slot1)`  
  ➤ Slot 1 এ গাড়ি থাকলে “Occupied”, না থাকলে “Free”

- `S1.write(90)`  
  ➤ Slot 1 এ গাড়ি এলে গেট খোলে (90°), পরে বন্ধ হয়

- একইভাবে Slot 2 এর জন্য `IR_Slot2` ও `S2.write()` ব্যবহার করা হয়

---

### 🚪 Entry & Exit Gate Logic

- `digitalRead(IR_entry)`  
  ➤ গাড়ি এলে Entry গেট খোলে → delay → বন্ধ হয়

- `digitalRead(IR_exit)`  
  ➤ গাড়ি বের হলে Exit গেট খোলে → delay → বন্ধ হয়

---

### 🖥️ LCD Display

- `lcd.setCursor()` + `lcd.print()`  
  ➤ Slot 1 ও Slot 2 এর স্ট্যাটাস LCD তে দেখানো হয়

---

### 🧪 Serial Debugging

- `Serial.print(...)`  
  ➤ Slot ও IR সেন্সরের রিয়েল-টাইম স্ট্যাটাস Serial Monitor এ দেখা যায়

---

## 🎯 Logic Summary

- ৪টি IR সেন্সর দিয়ে গাড়ি detect করা হয়  
- Entry ও Exit গেট Servo দিয়ে খোলা ও বন্ধ করা হয়  
- Slot status LCD তে দেখানো হয়  
- Serial Monitor দিয়ে debugging সহজ হয়  
- Delay দিয়ে গেট খোলার সময় নির্ধারণ করা হয়

## 6. 🚦 এখন নিজে চেষ্টা করো! (Hands-On Challenge)

- Breadboard এ ৪টি IR সেন্সর connect করো ঠিকমতো  
- Servo গুলোকে D9 ও D10 এ সংযুক্ত করো  
- LCD ঠিকভাবে parallel mode এ connect করো (RS, E, D4–D7)  
- কোড আপলোড করে গাড়ির simulation করো (IR সামনে হাত রাখো)  
- LCD তে স্লট স্ট্যাটাস দেখো, Servo গেট খোলে কিনা যাচাই করো  
- Serial Monitor খুলে প্রতিটি সেন্সরের রিডিং পর্যবেক্ষণ করো  
- Potentiometer দিয়ে analog input পড়া পরীক্ষা করো future use-এর জন্য  

---
