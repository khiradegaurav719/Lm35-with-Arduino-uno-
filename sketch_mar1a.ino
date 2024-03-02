// Connect the Vout/output pin of the LM35 to any analog pin of the Arduino Uno (A0).
// Connect the "GND" pin of the LM35 to the "GND" pin of the Arduino Uno.
// Connect the "Vcc" pin of the LM35 to the "5V" pin of the Arduino Uno.

//Gaurav Khirade (Embedded Firmware Developer)

#include <elapsedMillis.h>
// #include "const.h"  // including "const.h" for declarations

const int lm35Pin = A0;   // LM35 analog input pin
const int ledPin = 13;    // Onboard LED pin
int ledState = LOW;        //declaring led state as low
float temperatureThreshold = 30.0; 

elapsedMillis elapsed_time;

void setup() {
  Serial.begin(9600);       // Initialize serial communication for debugging
  pinMode(ledPin, OUTPUT);  // Set the LED pin as an output
}

void loop() {
  int lm35_value = analogRead(lm35Pin);                 // Reading analog input from LM35 i.e A0
  float temperature = (lm35_value * 5.0 / 1024) * 100;  // Converting analog value to temperature (in Celsius)

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  if (temperature < temperatureThreshold) {  // Check if the temperature falls below 30 degrees Celsius
    onBoardLed(250);
  } else {
    onBoardLed(500);  // If the temperature rises above 30 degrees Celsius, blink every 500 milliseconds
  }
}

void onBoardLed(int blink_time) {
  if (elapsed_time >= blink_time) {
    elapsed_time = 0;  // Reset the timer


    if (ledState == LOW) {
      ledState = HIGH;
    } else {            // Toggle the LED state
      ledState = LOW;
    }

    // Applying the LED state
    digitalWrite(ledPin, ledState);
  }
}
