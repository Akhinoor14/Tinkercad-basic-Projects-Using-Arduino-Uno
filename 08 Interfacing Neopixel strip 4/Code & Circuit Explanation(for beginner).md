Project Goal:
Arduino UNO দিয়ে ৪-পিক্সেল NeoPixel strip-এর রঙ পরিবর্তন করানো (চলমান animation সহ), যেখানে প্রতিটি LED এর রঙ আলাদাভাবে নিয়ন্ত্রণ করা যায়।

✨ এই প্রজেক্টে কী হবে?
==========================
- Arduino UNO দিয়ে ৪-পিক্সেল NeoPixel strip-এর রঙ পরিবর্তন করবে
- প্রতিটি LED-এর রঙ আলাদাভাবে নিয়ন্ত্রণ করা যাবে
- চলমান animation তৈরি করা যাবে

🔌 সার্কিট কানেকশন (Circuit Connection)
==========================
**যা লাগবে:**
- Arduino UNO
- ১টি NeoPixel strip (৪টি LED)
- Jumper Wires

**কানেকশন:**
| NeoPixel Wire | Arduino Pin | কাজ |
|---------------|-------------|-----|
| DIN           | D6          | Data Input (signal) |
| +5V           | 5V          | Power supply |
| GND           | GND         | Ground |

**নোট:**
- D6 pin থেকে data যাবে NeoPixel strip-এ
- Arduino USB power দিয়ে ৫টি LED পর্যন্ত চালানো যায় (বেশি হলে external 5V দরকার)
- NeoPixel strip অবশ্যই Arduino-র সাথে common ground শেয়ার করবে

💡 কোড ব্যাখ্যা (Code Explanation)
==========================

| অংশ | কী বোঝায়? |
|------|-----------|
| `#include <Adafruit_NeoPixel.h>` | NeoPixel strip চালাতে এই লাইব্রেরি দরকার |
| `Adafruit_NeoPixel strip(...)` | strip তৈরি করা হয়, কোন পিনে, কতগুলো পিক্সেল |
| `strip.begin()` | strip কে initialize করা হয় |
| `strip.setPixelColor(i, strip.Color(...))` | i-নাম্বার LED-তে নির্দিষ্ট রঙ দেয়া |
| `strip.Color(255,0,0)` | RED রঙের RGB মান |
| `strip.show()` | যতগুলো change করা হয়েছে, সব তখনই apply হয় |
| `delay(200)` | LED পরিবর্তনের মাঝে ২০০ মিলিসেকেন্ড বিরতি |

📝 ধাপে ধাপে কী হচ্ছে (Step-by-Step)
==========================
1. NeoPixel লাইব্রেরি যোগ করো
2. strip object তৈরি করো (কোন পিনে, কতটি LED)
3. strip.begin() দিয়ে strip initialize করো
4. for loop দিয়ে প্রতিটি LED-এর রঙ সেট করো (setPixelColor)
5. strip.show() দিয়ে সব রঙ একসাথে apply করো
6. delay() দিয়ে animation-এ বিরতি দাও

✅ এই প্রজেক্টে যা শিখবে
==========================
- NeoPixel strip-এর hardware connection
- Adafruit NeoPixel লাইব্রেরির বেসিক structure
- RGB মান (0–255) বোঝা
- Pixel index ও loop দিয়ে sequential animation
- strip.show() ও setPixelColor() এর ব্যবহার

🚦 এখন নিজে চেষ্টা করো!
==========================
- সার্কিট বানাও
- কোড আপলোড করো
- দেখো কিভাবে NeoPixel strip-এর রঙ ও animation বদলায়!