/*
use Touch Intrrerupts and read touch values
just touch the pins themselves to get different values
*/

int threshold = 40;
bool touch1detected = false;
bool touch2detected = false;
uint8_t touch1Val = 0;
uint8_t touch2Val = 0;

void gotTouch1(){
 touch1detected = true;
 touch1Val = touchRead(T2);
}

void gotTouch2(){
 touch2detected = true;
 touch2Val = touchRead(T9);
}

void setup() {
  Serial.begin(250000);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 Touch Interrupt Test");
  touchAttachInterrupt(T2, gotTouch1, threshold);
  touchAttachInterrupt(T9, gotTouch2, threshold);
}

void loop(){
  if(touch1detected){
    touch1detected = false;
    Serial.println(touch1Val);
  }
  if(touch2detected){
    touch2detected = false;
    Serial.println(touch2Val);
  }
}
