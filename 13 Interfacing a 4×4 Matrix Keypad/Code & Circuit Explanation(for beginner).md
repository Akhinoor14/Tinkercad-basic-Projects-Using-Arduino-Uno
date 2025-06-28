
🔌 সার্কিট কানেকশন (Circuit Connection)
==========================
**যা লাগবে:**
- Arduino UNO
- ৪x৪ Matrix Keypad
- Jumper Wires

**কানেকশন টেবিল:**

| Keypad Pin | Arduino Pin | কাজ/ব্যাখ্যা                |
|------------|-------------|-----------------------------|
| ROW1       | D9          | Top row (first from left)   |
| ROW2       | D8          | Second row                  |
| ROW3       | D7          | Third row                   |
| ROW4       | D6          | Bottom row                  |
| COL1       | D5          | Leftmost column             |
| COL2       | D4          |                             |
| COL3       | D3          |                             |
| COL4       | D2          | Rightmost column            |

📌 মোট ৮টি পিন—৪টি row ও ৪টি column Arduino-র digital পিনে সংযুক্ত করো।

📚 প্রয়োজনীয় লাইব্রেরি (Library Required)
==========================
- **Keypad লাইব্রেরি** ব্যবহার করতে হবে。
- ইন্সটল করতে:  
  ➤ Sketch > Include Library > Manage Libraries  
  ➤ "Keypad" (by Mark Stanley) খুঁজে ইন্সটল করো

**এই লাইব্রেরি দিয়ে:**  
- getKey(), makeKeymap() ইত্যাদি ফাংশন দিয়ে matrix keypad সহজে পড়া যায়

💡 কোড ব্যাখ্যা (Code Explanation)
==========================

| অংশ | কী বোঝায়? |
|------|-----------|
| `#include <Keypad.h>` | Keypad লাইব্রেরি যোগ করা হয়েছে, matrix scanning সহজ হয় |
| `char keys[ROWS][COLS] = {...}` | ২D array—প্রতিটি বাটনের জন্য কোন ক্যারেক্টার সেট হবে |
| `byte rowPins[ROWS] = {9, 8, 7, 6};`<br>`byte colPins[COLS] = {5, 4, 3, 2};` | কোন row/column কোন পিনে সংযুক্ত তা নির্ধারণ |
| `Keypad keypad = Keypad(...);` | keypad object তৈরি, যেটা কী প্রেস পড়বে |
| `keypad.getKey();` | কোন কী প্রেস হয়েছে তা রিটার্ন করে (না হলে NO_KEY/null) |
| `Serial.println(key);` | প্রেস হওয়া কী Serial Monitor-এ দেখায় |

📝 ধাপে ধাপে কী হচ্ছে (Step-by-Step)
==========================
1. Keypad লাইব্রেরি যোগ করো
2. keys array দিয়ে কোন বাটনে কোন ক্যারেক্টার সেট হবে তা নির্ধারণ করো
3. rowPins ও colPins দিয়ে পিন সংযোগ নির্ধারণ করো
4. Keypad object তৈরি করো
5. loop-এ keypad.getKey() দিয়ে কী প্রেস হচ্ছে কিনা চেক করো
6. কী প্রেস হলে Serial Monitor-এ দেখাও

✅ এই প্রজেক্টে যা শিখবে
==========================
- Matrix keypad কিভাবে Arduino-তে সংযুক্ত ও পড়া যায়
- Keypad লাইব্রেরি ব্যবহার
- Serial Monitor-এ কী প্রেস দেখা

🚦 এখন নিজে চেষ্টা করো!
==========================
- সার্কিট বানাও
- কোড আপলোড করো
- কী প্রেস করলে Serial Monitor-এ দেখো!