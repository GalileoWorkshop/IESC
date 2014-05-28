#include <Servo.h>
#include <Wire.h>

// Variable declarations
int serialSpeed = 9600; // Speed of serial Comms
int servoPin = 9; // Pin where Servo motor is attached
int potPin = 0;   // Analog Pin Number
Servo myServo;

void setup()
{
  //initialize teh serial communication. Will use it for debugging
  Serial.begin(serialSpeed);         
  myServo.attach(servoPin);          // Telling Arduino where the servo is connected
}

void loop()
{
  int angle;
  int value;
  
  // Read the Analog Voltage
  value = analogRead(potPin);
  Serial.println(value);
  // Remap/Scale Voltage Reading to Degrees
  angle = map(value, 0, 1023, 0 , 180);
  //Serial.write(angle);

  // Instruct Servo to move
  myServo.write(angle);
  
  // Wait for a little bit of time for servo to move
  delay(15);  
}
