# 🔌 Circuit Connections

| NeoPixel Jewel Pin | Arduino UNO Pin | Description              |
|--------------------|------------------|--------------------------|
| IN (DIN)           | D6               | Data signal input        |
| +5V                | 5V               | Power supply             |
| GND                | GND              | Ground connection        |

> 📎 Tip: NeoPixel Jewel ও Arduino-এর **GND একই রাখা জরুরি**, না হলে signal প্রপারভাবে কাজ করবে না।

---

# 🧠 Code Explanation (line by line)

| অংশ | কী বোঝায়? |
|------|-----------|
| `#include <Adafruit_NeoPixel.h>` | NeoPixel Jewel চালাতে লাইব্রেরি যুক্ত করা হয়েছে |
| `Adafruit_NeoPixel ring(NUMPIXELS, PIN, ...)` | ৭-পিক্সেল NeoPixel object তৈরি করা হয়েছে, Data PIN = D6 |
| `ring.begin()` | NeoPixel Jewel initialize করা হয়েছে |
| `ring.setPixelColor(i, ring.Color(R, G, B))` | i-নাম্বার LED-তে নির্দিষ্ট RGB রঙ সেট করা হচ্ছে |
| `ring.Color(255,0,0)` | RED রঙের মান |
| `ring.Color(0,255,0)` | GREEN রঙের মান |
| `ring.Color(0,0,255)` | BLUE রঙের মান |
| `ring.show()` | সব পিক্সেলে নতুন রঙ apply করার কমান্ড |
| `delay(150)` | প্রতিটি LED animation’র মাঝে সামান্য বিরতি |
| `ring.setPixelColor(i, 0)` | পিক্সেল বন্ধ করে দেওয়া হচ্ছে (black/off) |

---

# 📚 ধাপে ধাপে কী হচ্ছে (Step-by-Step)

1. NeoPixel লাইব্রেরি যোগ করো
2. `ring` object তৈরি করো (৭টি পিক্সেল, D6 পিন)
3. `ring.begin()` দিয়ে NeoPixel Jewel initialize করো
4. `for` loop দিয়ে প্রতিটি LED-এর রঙ সেট করো (`setPixelColor`)
5. `ring.show()` দিয়ে সব রঙ একসাথে apply করো
6. `delay()` দিয়ে animation-এ বিরতি দাও
7. LED বন্ধ করতে `setPixelColor(i, 0)` ব্যবহার করো

---

# ✅ এই প্রজেক্টে যা শিখবে

- NeoPixel Jewel-এর hardware connection
- Adafruit NeoPixel লাইব্রেরির বেসিক structure
- RGB মান (0–255) বোঝা
- Pixel index ও loop দিয়ে sequential animation
- `setPixelColor()` ও `show()` এর ব্যবহার

---

# 🚦 এখন নিজে চেষ্টা করো!

- সার্কিট বানাও
- কোড আপলোড করো
- দেখো কিভাবে NeoPixel Jewel-এর রঙ ও animation বদলায়!
