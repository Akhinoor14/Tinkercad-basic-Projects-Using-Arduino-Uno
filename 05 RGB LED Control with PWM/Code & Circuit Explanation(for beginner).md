✨ এই প্রজেক্টে কী হবে?
==========================
- ১টি RGB LED-এর তিনটি রং (Red, Green, Blue) আলাদাভাবে নিয়ন্ত্রণ করবে
- রংগুলো ধীরে ধীরে fade in ও fade out হবে
- একেক সময় একেকটা রঙ মিশে নতুন রঙ তৈরি হবে (smooth color change)

🔌 সার্কিট কানেকশন (Circuit Connection)
==========================
**যা লাগবে:**
- Arduino UNO
- ১টি Common Cathode RGB LED (Tinkercad-এ সাধারণত এইটাই থাকে)
- ৩টি 220Ω resistor
- Breadboard ও Jumper Wires

**কানেকশন:**
- Red pin → D9 (PWM) → 220Ω resistor → LED-এর Red পা
- Green pin → D10 (PWM) → 220Ω resistor → LED-এর Green পা
- Blue pin → D11 (PWM) → 220Ω resistor → LED-এর Blue পা
- LED-এর বড় পা (common cathode) → GND

**নোট:** D9, D10, D11 পিন PWM সাপোর্ট করে, তাই analogWrite() কাজ করবে।

💡 কীভাবে কাজ করবে? (Expected Behavior)
==========================
- Red, Green, Blue আলাদাভাবে fade করবে
- কখনও কখনও রং মিশে নতুন রঙ তৈরি হবে
- ধীরে ধীরে রঙ পরিবর্তন হবে (smooth transition)


📝 কোড ব্যাখ্যা (Code Explanation)
==========================

| অংশ | কী হচ্ছে? |
|-----|-----------|
| `analogWrite()` | প্রতিটি রঙে কতটা উজ্জ্বলতা দিতে হবে সেটি নির্ধারণ করে (0–255) |
| Fade in/out | একটার মান বাড়ে, অন্যটার কমে—রং মসৃণভাবে বদলায় |
| Loop structure | প্রতিটি কালার ট্রানজিশনের জন্য for loop ব্যবহার করা হয়েছে |
| Smooth change | সব রং একসাথে না জ্বলে ধাপে ধাপে চেঞ্জ হয়—নরম ও নিঃশ্বাসের মতো পরিবর্তন |


🧭 কী শিখবে এই প্রজেক্টে?
==========================
- PWM Pins: কেন D9–D11 ব্যবহার করা হয়
- Color Mixing: Red + Green = Yellow টাইপ মিশ্রণ
- analogWrite: কিভাবে light intensity নিয়ন্ত্রণ হয়
- Fade Technique: ধীরে রঙ পরিবর্তনের জন্য loop ও delay ব্যবহার


🚦 এখন নিজে চেষ্টা করো!
==========================
- সার্কিট বানাও
- কোড আপলোড করো
- দেখো কিভাবে RGB LED-র রং ধীরে ধীরে বদলায়!
