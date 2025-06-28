Servo motor interfacing! 😄 এই প্রজেক্টের মাধ্যমে তুমি শিখবে কিভাবে একটা servo motor-কে নির্দিষ্ট কোণে ঘোরানো যায় Arduino দিয়ে। এটা future robotics প্রজেক্টের বুনিয়াদ তৈরি করবে,

চল শুরু করি ১ম ধাপ: Circuit Connection + কোড + ব্যাখ্যা ✅

✨ এই প্রজেক্টে কী হবে?
==========================
- Arduino দিয়ে servo motor নির্দিষ্ট কোণে ঘোরানো শিখবে
- Robotics বা automation প্রজেক্টের জন্য এটা খুব দরকারি

🔌 সার্কিট কানেকশন (Circuit Connection)
==========================
**যা লাগবে:**
- Arduino UNO
- ১টি Servo Motor
- Jumper Wires

**কানেকশন:**
- Servo-এর Red wire → 5V (Power)
- Servo-এর Black/Brown wire → GND (Ground)
- Servo-এর Orange/Yellow wire → D9 (Signal, PWM pin)

**নোট:** Servo motor-এ signal পাঠানো হয় PWM (Pulse Width Modulation) দিয়ে। D9 pin PWM-compatible, তাই এটা ব্যবহার করা হয়।

💡 কোড ব্যাখ্যা (Code Explanation)
==========================

| অংশ | কী হচ্ছে? |
|-----|-----------|
| `#include <Servo.h>` | Servo motor control করার লাইব্রেরি |
| `Servo myServo;` | servo object তৈরি করা |
| `myServo.attach(9);` | servo-এর signal pin Arduino D9-এ সংযুক্ত |
| `myServo.write(angle);` | servo motor নির্দিষ্ট কোণে ঘোরানো |
| `for loop` | 0° → 180° → 0° smooth ঘোরানোর জন্য |

📝 ধাপে ধাপে কী হচ্ছে (Step-by-Step)
==========================
1. Servo লাইব্রেরি যোগ করো
2. Servo object তৈরি করো
3. Servo-এর signal pin D9-এ সংযুক্ত করো
4. for loop দিয়ে servo-কে ধীরে ধীরে 0° থেকে 180° এবং আবার 0°-তে ফেরাও
5. myServo.write() দিয়ে কোণ নির্ধারণ করো

✅ এই প্রজেক্টে যা শিখবে
==========================
- Servo motor কিভাবে কাজ করে
- Servo লাইব্রেরি ব্যবহার
- attach(), write() ফাংশনের ব্যবহার
- PWM signal এর গুরুত্ব
- loop দিয়ে smooth motion বানানো

🚦 এখন নিজে চেষ্টা করো!
==========================
- সার্কিট বানাও
- কোড আপলোড করো
- দেখো servo motor কিভাবে নির্দিষ্ট কোণে ঘোরে!