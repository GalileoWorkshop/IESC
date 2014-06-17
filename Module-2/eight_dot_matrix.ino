
// 1-dimensional array of row pin numbers:
const int row[8] = {
  2,7,19,5,13,18,12,16 };


// 1-dimensional array of column pin numbers:
const int col[8] = {
  6,11,10,3,17,4,8,9  };


//array of pixels taken from the generator above
int pixels [8] = {B00011111,
B00010001,
B00010001,
B00010001,
B00010001,
B10010001,
B10010001,
B11110001};        

void setup() {
  // initialize the I/O pins as outputs
  // iterate over the pins:
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    // initialize the output pins:
    pinMode(col[thisPin], OUTPUT);
    pinMode(row[thisPin], OUTPUT);  
    // take the col pins (i.e. the cathodes) high to ensure that
    // the LEDS are off:
    digitalWrite(col[thisPin], HIGH);    
  }
}
  
void refreshScreen() {
  // iterate over the rows (anodes):
  for (int thisRow = 0; thisRow < 8; thisRow++) {
    digitalWrite(row[thisRow], HIGH); 
    // take the row pin (anode) high:
     // iterate over the cols (cathodes):
    for (int thisCol = 0; thisCol < 8; thisCol++) {
      
      // get the state of the current pixel;
      int thisPixel = bitRead((pixels[thisRow]), 7-thisCol);
      // when the row is HIGH and the col is LOW,
      // the LED where they meet turns on:
      if (thisPixel == HIGH) {
          //turn on/off pixels
        digitalWrite(col[thisCol], LOW);
        digitalWrite(col[thisCol], HIGH);
      }
    }
    // take the row pin low to turn off the whole row:
    digitalWrite(row[thisRow], LOW);
  }
  }
  

void loop(){
 refreshScreen();
}


