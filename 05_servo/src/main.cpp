#include <Arduino.h>
#include <Servo.h>

Servo myServo;
const int servo_pin = 3;

const int potentiometer_pin = A0;
int potentiometer_value;
int potentiometer_angle;

void setup() {
  myServo.attach(servo_pin);

  Serial.begin(9600);
}

void loop() {
  potentiometer_value = analogRead(potentiometer_pin);
  Serial.print("potentiometer_value: ");
  Serial.print(potentiometer_value);

  // Map Potentiometer values to servo angles
  potentiometer_angle = map(potentiometer_value, 0, 1023, 0, 179);
  Serial.print("potentiometer_angle: ");
  Serial.print(potentiometer_angle);

  myServo.write(potentiometer_angle);
  delay(15);
}