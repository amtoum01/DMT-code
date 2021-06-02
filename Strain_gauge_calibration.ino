/*

 This is the calibration sketch. Use it to determine the calibration_factor that the main example uses.

 Setup the scale and start the sketch WITHOUT a weight on the bar
 Once readings are displayed place the weight on the bar
 Press +/- or a/z to adjust the calibration_factor until the output readings match the known weight
 Use this calibration_factor on the example sketch



 Your calibration factor may be very positive or very negative. 
 This example code uses this library which must be downloaded first to be able to use the functions
 : https://github.com/bogde/HX711
 
 
 Arduino pin 2 -> HX711 CLK
 3 -> DOUT
 5V -> VCC
 GND -> GND


*/

#include "HX711.h"

#define DOUT  3
#define CLK  2

HX711 scale;

float calibration_factor = -7050; //random initial calibration factor

void setup() {
  Serial.begin(9600);
  Serial.println("HX711 calibration sketch");
  Serial.println("Remove all weight from scale");
  Serial.println("After readings begin, place known weight on scale");
  Serial.println("Press + or a to increase calibration factor");
  Serial.println("Press - or z to decrease calibration factor");

  scale.begin(DOUT, CLK);
  scale.set_scale();
  scale.tare(); //Reset the scale to 0

  long zero_factor = scale.read_average(); //Get a baseline reading
  Serial.print("Zero factor: "); 
  Serial.println(zero_factor);
}

void loop() {

  scale.set_scale(calibration_factor); //Adjust to this calibration factor

  Serial.print("Reading: ");
  Serial.print(scale.get_units(), 1);
  Serial.print(" Kg"); 
  Serial.print(" calibration_factor: ");
  Serial.print(calibration_factor);
  Serial.println();

// If Reading isnt == to know weight the press 'a' or 'z' depending if you want to increase the calibration factor or reduce it
  if(Serial.available())
  {
    char temp = Serial.read();
    if(temp == '+' || temp == 'a')
      calibration_factor += 10;
    else if(temp == '-' || temp == 'z')
      calibration_factor -= 10;
  }

  //When the reading displayed == known weight note down the calibration_factor value for use in the main testing sketch
}
