#include <Servo.h>      // Include lib for servo motor

Servo trash;            
 
int trig = 13;          // Pin number for trig
int echo = 12;          // Pin number for echo

void setup() {
  trash.attach(2);      // Set control pin to 2
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); 
}

void loop() {
  /////////////// Calculate distance from Ultrasoic sensor /////////////
  long duration, distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration / 58; // From duration To cm unit
  //////////////////////////////////////////
 
  if (distance <= 6) {      // If within 6cm
    delay(500);
    trash.write(120);       // Set 120 degree
    delay(2500);
  } else {
    trash.write(0);         // Return to 0 degree
  }
}
