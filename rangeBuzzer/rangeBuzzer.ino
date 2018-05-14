
/*

The program piezo buzzer whenever an obstacle is in the range of the 
ultrasonic range sensor

*/

#include "Ultrasonic.h"

Ultrasonic ultrasonic(6);
const int buzzer = 7;

void setup()
{
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
 
}
void loop()
{
  long RangeInInches;
  long RangeInCentimeters;
  int inRange = 20;

  digitalWrite(buzzer, HIGH); 
  /*
  Serial.println("The distance to obstacles in front is: ");
  RangeInInches = ultrasonic.MeasureInInches();
  Serial.print(RangeInInches);//0~157 inches
  Serial.println(" inch");
  delay(250);
  */
  RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
  Serial.print(RangeInCentimeters);//0~400cm
  Serial.println(" cm");
  if (RangeInCentimeters < inRange){tone(buzzer, 1000);}
  else{noTone(buzzer);}
  delay(1000);
  //delay(500);
}
