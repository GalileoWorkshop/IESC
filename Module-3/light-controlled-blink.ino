/*  Analog InputDemonstrates analog input by reading an analog sensor on analog pin 0 and turning on and off a light emitting diode(LED) connected to digital pin 13. The amount of time the LED will be on and off depends on the value obtained by analogRead(). */ 

int photo = A0; // select the input pin for the potentiometer 
int led = 8; // select the pin for the LED
int sensorValue = 0; // variable to store the value coming from the sensor 

void setup() {   
// declare the ledPin as an OUTPUT:   
pinMode(led, OUTPUT);
 } 

void loop() {   
// read the value from the sensor:   
sensorValue = analogRead(photo);   
// turn the ledPin on   
digitalWrite(led, HIGH);   
// stop the program for <sensorValue> milliseconds:  
 delay(sensorValue);   
// turn the ledPin off:   
digitalWrite(led, LOW);   
// stop the program for for <sensorValue> milliseconds:   
delay(sensorValue); 
}
