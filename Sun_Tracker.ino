// ---------------- BLYNK CONFIG ----------------
#define BLYNK_TEMPLATE_ID "TMPL3b0t9IifS"
#define BLYNK_TEMPLATE_NAME "Solar"
#define BLYNK_AUTH_TOKEN "rasrpwrl5yizP6yupneL74iPfErVfdFZ"

// ---------------- LIBRARIES ----------------
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

// ---------------- WIFI ----------------
char ssid[] = "LENOVO";
char pass[] = "90000000";

// ---------------- PINS ----------------
#define LDR1 35
#define LDR2 34
#define SERVO_PIN 12
#define CURRENT_PIN 23

// ---------------- CONSTANTS ----------------
#define SOLAR_VOLTAGE 12.0   // Panel voltage

// ---------------- VARIABLES ----------------
Servo myservo;

int pos = 90;         // Servo start position
int tolerance = 50;   // Light difference threshold

float current = 0.0;
float power = 0.0;

// ---------------- TIMER ----------------
BlynkTimer timer;

// ---------------- FUNCTION ----------------
void sendSensorData() {
  int val1 = analogRead(LDR1);
  int val2 = analogRead(LDR2);

  int rawCurrent = analogRead(CURRENT_PIN);

  // Convert ADC to current (ACS712 5A)
  current = abs(((rawCurrent * 3.3 / 4095.0) - 1.65) / 0.185);

  power = SOLAR_VOLTAGE * current;

  // Send to Blynk
  Blynk.virtualWrite(V0, val1);
  Blynk.virtualWrite(V1, val2);
  Blynk.virtualWrite(V2, pos);
  Blynk.virtualWrite(V3, power);
  Blynk.virtualWrite(V5, current);
}

// ---------------- SETUP ----------------
void setup() {
  Serial.begin(115200);

  // Blynk start
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Servo setup
  ESP32PWM::allocateTimer(0);
  myservo.attach(SERVO_PIN);
  myservo.write(pos);

  // Timer (1 sec)
  timer.setInterval(1000L, sendSensorData);
}

// ---------------- LOOP ----------------
void loop() {
  Blynk.run();
  timer.run();

  int val1 = analogRead(LDR1);
  int val2 = analogRead(LDR2);

  // -------- Current + Power --------
  int rawCurrent = analogRead(CURRENT_PIN);
  current = abs(((rawCurrent * 3.3 / 4095.0) - 1.65) / 0.185);
  power = SOLAR_VOLTAGE * current;

  // -------- Debug Print --------
  Serial.printf("LDR1: %d | LDR2: %d | Servo: %d | Current: %.2f A | Power: %.2f W\n",
                val1, val2, pos, current, power);

  // -------- Sun Tracking Logic --------
  if (abs(val1 - val2) > tolerance) {
    if (val1 < val2) {
      pos = min(pos + 1, 180);   // Move right
    } else {
      pos = max(pos - 1, 0);     // Move left
    }
    myservo.write(pos);
  }

  delay(50);
}