#include <Arduino.h>

/*
 * Project 14: TMP36 + ATtiny85 + RGB LED + DIP Power Switch
 * Author: Md Akhinoor Islam
 * Description: Show 5 distinct color zones from -40°C to +125°C using TMP36 and RGB LED
 */

const int redPin   = 0;  // PB0 → Pin 5
const int greenPin = 1;  // PB1 → Pin 6
const int bluePin  = 4;  // PB4 → Pin 3
const int tempPin  = A1; // PB2 → Pin 7 (TMP36 analog input)

const float Vcc = 3.0; // Supply voltage, change if different

float temperature;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  int raw = analogRead(tempPin);
  float voltage = raw * (Vcc / 1023.0);           // TMP36 powered by Vcc
  temperature = (voltage - 0.5) * 100.0;          // TMP36 voltage → °C

  // Map temperature ranges to 5 distinct color zones
  if (temperature <= -20) {
    setColor(0, 0, 255);   // Deep Cold → Blue
  }
  else if (temperature > -20 && temperature <= 10) {
    setColor(0, 255, 255); // Cool → Cyan
  }
  else if (temperature > 10 && temperature <= 35) {
    setColor(0, 255, 0);   // Normal → Green
  }
  else if (temperature > 35 && temperature <= 60) {
    setColor(255, 165, 0); // Warm → Orange
  }
  else {
    setColor(255, 0, 0);   // Hot → Red
  }

  delay(1000); // Update every 1s
}

void setColor(int r, int g, int b) {
  // Ensure values are within 0-255
  r = constrain(r, 0, 255);
  g = constrain(g, 0, 255);
  b = constrain(b, 0, 255);

  // যদি RGB LED কমন ক্যাথোড হয় (সাধারণত তাই হয়), analogWrite(pin, value) ঠিক আছে।
  // যদি কমন অ্যানোড হয়, analogWrite(pin, 255-value) দিতে হবে。
  // নিচের কোড কমন ক্যাথোডের জন্য:
  analogWrite(redPin, r);    // PWM: PB0
  analogWrite(greenPin, g);  // PWM: PB1
  analogWrite(bluePin, b);   // PWM: PB4

  // যদি LED কমন অ্যানোড হয়, তাহলে নিচের লাইনগুলো ব্যবহার করুন:
  // analogWrite(redPin, 255 - r);
  // analogWrite(greenPin, 255 - g);
  // analogWrite(bluePin, 255 - b);
}
