// Code to control motor speed using PWM.  PWM controlled
// by potentiometer setting

int pwmPin = 9;
int posPin = A0;
int value;

void setup() {
  // put your setup code here, to run once:
  pinMode(pwmPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  
  //Read the setting from the analog pin
  value = analogRead(posPin);
  
  //Re-map values
  value = map(value, 0, 1023, 0, 255);
  
  //Write value to pin controlling motor
  analogWrite(pwmPin, value);

}
