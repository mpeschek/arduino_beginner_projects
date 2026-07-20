#include <Arduino.h>

int switch_state;
int red_state = 1;
int blue_state = 0;
void alternate(int& pin_1, int& pin_2);

void setup() {
  pinMode(3, OUTPUT);     // green light
  pinMode(4, OUTPUT);     // blue light 
  pinMode(10, OUTPUT);     // red light 
  pinMode(2, INPUT);      // Switch
}

void loop() {
  switch_state = digitalRead(2);

  if (switch_state == LOW) {
    // Only green light if button not pressed
    digitalWrite(3, HIGH);

    digitalWrite(4, LOW);
    digitalWrite(10, LOW);
  } else {

    digitalWrite(3, LOW);

    // alternating blue and red
    digitalWrite(4, blue_state);
    digitalWrite(10, red_state);
    delay(200);
    alternate(red_state, blue_state);
  }
}

void alternate(int& pin_1, int& pin_2) {
  int intermediate = pin_1;
  pin_1 = pin_2;
  pin_2 = intermediate;
}