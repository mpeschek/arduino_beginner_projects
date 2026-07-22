#include <Arduino.h>

const int red_pin = 11;
const int blue_pin = 10;
const int green_pin= 9;

const int red_sensor = A0;
const int blue_sensor = A1;
const int green_sensor = A2;

int red_output = 0;
int blue_output = 0;
int green_output = 0;

int red_sensor_value = 0;
int blue_sensor_value = 0;
int green_sensor_value = 0;

void setup() {
  Serial.begin(9600);

  pinMode(red_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
}

void loop() {
  // Assign sensor phototransistor inputs to rgb values
  red_sensor_value = analogRead(red_sensor);
  blue_sensor_value = analogRead(blue_sensor);
  green_sensor_value = analogRead(green_sensor);

  // Serial.print("Raw sensor values: \t red: ");
  // Serial.print(red_sensor_value);
  // Serial.print("\t blue: ");
  // Serial.print(blue_sensor_value);
  // Serial.print("\t green: ");
  // Serial.print(green_sensor_value);
  // Serial.print("\n");
  
  delay(5);

  // Map the sensor values
  red_output = red_sensor_value / 4;
  blue_output = blue_sensor_value / 4;
  green_output = green_sensor_value / 4;

  Serial.print("Mapped sensor values: \t red: ");
  Serial.print(red_output);
  Serial.print("\t blue: ");
  Serial.print(blue_output);
  Serial.print("\t green: ");
  Serial.print(green_output);
  Serial.print("\n");


  analogWrite(red_pin, red_output);
  analogWrite(blue_pin, blue_output);
  analogWrite(green_pin, green_output);
}

