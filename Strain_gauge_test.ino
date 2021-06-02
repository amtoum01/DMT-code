/*
 * 
 Arduino pin 2 -> HX711 CLK
 3 -> DAT
 5V -> VCC
 GND -> GND

 The HX711 board can be powered from 2.7V to 5V so the Arduino 5V power should be fine.

*/

#include "HX711.h"

#define calibration_factor -7050.0 // This value is obtained using the Starin_gauge_calibration sketch which must be run first

#define DOUT  3
#define CLK  2

HX711 scale;

void setup() {
  Serial.begin(9600);
  Serial.println("Strain gauge test");

  scale.begin(DOUT, CLK);
  scale.set_scale(calibration_factor); 
  scale.tare(); //Assuming there is no weight on the bar at start up, reset the scale to 0

  //Serial.println("Readings:");
}

// This loop should give the readings that will be used to fill out the table given in the testing handout
void loop() {
  //Serial.print("Reading: ");
  Serial.print(scale.get_units(), 1); //scale.get_units() returns a float
  //Serial.print(" Kg"); 
  //Serial.println();


  delay(1000);
}
