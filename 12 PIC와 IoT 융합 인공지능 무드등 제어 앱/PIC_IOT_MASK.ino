//인공지능 마스크 판별기
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(4, 5);
String data ;
void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
}


void loop() {
  if (BTSerial.available()) {
    data = BTSerial.readString();

    if (data == "on") {
      analogWrite(9, 0);  analogWrite(10, 0);  analogWrite(11, 255);
    }
    else if (data == "off") {
      analogWrite(9, 255);  analogWrite(10, 0);  analogWrite(11, 0);
    }
  }
}
