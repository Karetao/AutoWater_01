#include <Arduino.h>


// constants won't change
const int RELAY_PIN = 3;  // the Arduino pin, which connects to the IN pin of relay
#define AOUT_PIN A0       // Arduino pin (A0) that connects to "AOUT" of moisture sensor



void setup() {
  // initialize digital pin as an output.
  pinMode(RELAY_PIN, OUTPUT);

  // start serial communication at 9600 bits per second. Use the "Monitor" to see the output
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(AOUT_PIN); // read the analog value from sensor

  Serial.print("Moisture: ");
  Serial.println(value);

  delay(500);

  if (value < 500)  // if the value is less than 500, then turn on the relay so we get water
  {
    digitalWrite(RELAY_PIN, HIGH);    // turn the relay on
    delay(500);                       //Just half a second of water
    digitalWrite(RELAY_PIN, LOW);     // turn the relay off
  }
  
  //Have a 5 second delay before repeating the loop
  delay(5000);    /* code */

}





