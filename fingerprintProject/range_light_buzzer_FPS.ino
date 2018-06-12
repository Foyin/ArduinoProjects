#include <SPI.h>
#include <math.h>
#define LIGHT_SENSOR A1 //Light Sensor is connected to A1 of Arduino
float Rsensor; //Resistance of sensor in K 
const int trigPin = 8;
const int echoPin = 9;
int buzz = 2;
int lightValue = analogRead(LIGHT_SENSOR);
int buzzState; 

#include "FPS_GT511C3.h"
#include "SoftwareSerial.h" 

FPS_GT511C3 fps(10, 11); // (Arduino SS_RX = pin 4, Arduino SS_TX = pin 5)

void setup()
{
 Serial.begin(9600);   //i think i wont need this to show data on internet
  delay(100);
  fps.Open();         //send serial command to initialize fps
  fps.SetLED(true);
      // int id = fps.Identify1_N();

  pinMode(trigPin, OUTPUT); //make trigPin (#7) as output to trigger the sound wave
  pinMode(echoPin, INPUT);  //make echoPin(#8) to catch the reflected back sound wave
  pinMode(buzz,OUTPUT);
 
}
 
void loop()
{
 // Serial.println(Serial.read());
 int id = fps.Identify1_N();
 
 
 float duration, inches, cm;
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 
 duration = pulseIn(echoPin, HIGH);
 
 inches = (duration/2)/74;
 cm = (duration/2)/29.1;

  if (inches < 25 && lightValue <=250){//dark and someone here    
      Serial.println("Its dark and someone is here");
      buzzOn();
      //buzzState = 1;
     }

  if (inches < 25 && lightValue >250){//bright and someone here   *
      Serial.println("Its bright and someone is here");
      buzzOff();
      //buzzState = 0;
     }
  if (inches >= 25 && lightValue <= 250){//*
      Serial.println("Its dark and no one is here");
      buzzOff();
      //buzzState = 0;
     }

  if (inches >= 25 && lightValue > 250){
      Serial.println("Its bright and no one is here");
      buzzOff()
      //buzzState = 0;
     }

  if((fps.IsPressFinger() == true))
        {
          //Serial.println(id);
          Serial.println("checking finger print");
          buzzOff();
          //buzzState = 1;
          delay(5000)
        } 

  
 delay(500);
 
}

void buzzOn(){
  Serial.println(lightValue);
  Serial.println(inches);
  digitalWrite(buzz, HIGH);
  delay(100);
  digitalWrite(buzz, LOW);
}

void buzzOff(){
  Serial.println(lightValue);
  Serial.println(inches);
  digitalWrite(buzz, LOW);
}
