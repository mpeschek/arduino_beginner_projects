#include <Arduino.h>

const int sensor_pin = A0;
const float baseline_sensor = 162.0;

void show_led(float input);

void setup() {
  Serial.begin(9600);
  for (int i = 2; i < 5; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  int sensor_val = analogRead(sensor_pin);

  Serial.print("Sensor value: ");
  Serial.print(sensor_val);

  float voltage = (sensor_val / 1024) * 5;
  Serial.print(" | Voltage value: ");
  Serial.print(voltage);

  float temperature = (voltage - .5) * 100;
  Serial.print(" | Temperature value: ");
  Serial.print(temperature);
  
  Serial.print("\n");

  show_led(sensor_val);
  delay(1);
}

void show_led(float input) {
  if (input < baseline_sensor + 2) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (input < baseline_sensor + 6 && input >= baseline_sensor + 2) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (input < baseline_sensor + 10 && input >= baseline_sensor + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (input >= baseline_sensor + 10) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
}