/*
 * This example code is in the public domain *
 */

// constants won't change
const int TRIG_PIN  = 7;  // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN  = 6;  // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int RELAY_PIN = A5; // Arduino pin connected to Relay's pin
const int DISTANCE_THRESHOLD = 50; // centimeters

// variables will change:
float duration_us, distance_cm;

void setup() {
  Serial.begin (9600);        // initialize serial port
  pinMode(TRIG_PIN, OUTPUT);  // set arduino pin to output mode
  pinMode(ECHO_PIN, INPUT);   // set arduino pin to input mode
  pinMode(RELAY_PIN, OUTPUT); // set arduino pin to output mode
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;

  if(distance_cm < DISTANCE_THRESHOLD)
    digitalWrite(RELAY_PIN, HIGH); // turn on Relay
  else
    digitalWrite(RELAY_PIN, LOW);  // turn off Relay

  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(500);
}
