#include <_BUTTON_.h>
void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT_PULLUP);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.println(BUT(8, 1000, 80, 8));
  
  

}
