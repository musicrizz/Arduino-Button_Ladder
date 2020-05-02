#include "ButtonLadder.h"

#define PIN_LADDER A0

ButtonLadder* butt_ladder = 0;

void exploreVoltRange(int val);

void setup() {
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  
  butt_ladder = new ButtonLadder(PIN_LADDER, exploreVoltRange);
  
  Serial.begin(115200, SERIAL_8N1);
  while(!Serial);

}

void loop() {
  
  butt_ladder->check();
  delay(5);

}

void exploreVoltRange(int val)   {
  Serial.print(F("The voltage at this button is:"));
  Serial.println(val);
  Serial.println(F("------------"));
  //at different voltage you can call different method ;)
}
