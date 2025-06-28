এবার তুমি Arduino থেকে একটু লাইটওয়েট পথে আগাচ্ছো—ATtiny85, যেটা অনেক ছোট কিন্তু শক্তিশালী microcontroller। এই প্রজেক্টে আমরা শিখবো কিভাবে potentiometer দিয়ে LED-এর brightness নিয়ন্ত্রণ করা যায় ATtiny85 দিয়ে, যা embedded systems এর একটি অন্যতম গুরুত্বপূর্ণ ধারণা ✨

✨ এই প্রজেক্টে কী হবে?
==========================
- Potentiometer ঘোরালে LED-এর উজ্জ্বলতা বাড়বে বা কমবে
- ATtiny85 দিয়ে এই কাজ হবে (ছোট, কম পাওয়ারের microcontroller)
- Power হিসেবে 3V battery ব্যবহার করা হবে

🔌 সার্কিট কানেকশন (Circuit Connection)
==========================
**যা লাগবে:**
- ATtiny85
- ১টি LED
- ১টি 220Ω resistor
- ১টি potentiometer
- Breadboard (ঐচ্ছিক)
- Jumper Wires
- 3V Battery

**কানেকশন:**
- Potentiometer-এর মাঝের পা → ATtiny85 Pin 2 (PB3/A3, analog input)
- Potentiometer-এর দুই পাশ → GND ও 3V
- LED-এর বড় পা (anode) → ATtiny85 Pin 5 (PB0, PWM output) → 220Ω resistor → GND
- Battery (3V) → VCC & GND (ATtiny85-এ সরাসরি)

**নোট:**
- ATtiny85-এর PWM পিন: PB0 (Pin 5), PB1 (Pin 6)
- Analog input পিন: PB3 = A3 (Pin 2)

💡 কোড ব্যাখ্যা (Code Explanation)
==========================

| অংশ | কী হচ্ছে? |
|------|-----------|
| `A3` | Potentiometer-এর middle pin থেকে analog value নেয় |
| `PB0 (pin 5)` | PWM output pin, যেখানে LED লাগানো হয়েছে |
| `analogRead(potPin)` | Potentiometer থেকে value নেয় (0–1023) |
| `map()` | এই value কে 0–255 রেঞ্জে রূপান্তর করে (brightness) |
| `analogWrite()` | PWM signal পাঠিয়ে LED-এর উজ্জ্বলতা নিয়ন্ত্রণ করে |


📝 ধাপে ধাপে কী হচ্ছে (Step-by-Step)
==========================
1. Potentiometer-এর মাঝের পা analog input (A3)-এ সংযুক্ত করো
2. LED-এর বড় পা PWM output (PB0)-এ সংযুক্ত করো (resistor দিয়ে)
3. analogRead() দিয়ে potentiometer-এর মান পড়ো
4. map() দিয়ে মানকে 0–255 রেঞ্জে রূপান্তর করো
5. analogWrite() দিয়ে LED-এর brightness নিয়ন্ত্রণ করো


✅ এই প্রজেক্টে যা শিখবে
==========================
- ATtiny85 দিয়ে কিভাবে LED কন্ট্রোল করতে হয়
- analogRead() আর analogWrite() ব্যবহার
- PWM কীভাবে brightness নিয়ন্ত্রণ করে
- map() function দিয়ে মান কনভার্ট করা


🚦 এখন নিজে চেষ্টা করো!
==========================
- সার্কিট বানাও
- কোড আপলোড করো
- Potentiometer ঘুরিয়ে দেখো LED-এর brightness কিভাবে বাড়ে/কমে!