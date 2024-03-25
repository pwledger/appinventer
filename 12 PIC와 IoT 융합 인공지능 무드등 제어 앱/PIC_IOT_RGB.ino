//인공지능 무드등 제어하기
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(4, 5);
String data;
void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
}


void loop() {
  if (BTSerial.available()) {
   data = BTSerial.readString();
    if (data == 'R') {
      analogWrite(9, 255);  analogWrite(10, 0);  analogWrite(11, 0);
    }
    else if (data == 'G') {
      analogWrite(9, 0);  analogWrite(10, 255);  analogWrite(11, 0);
    }
    else if (data == 'B') {
      analogWrite(9, 0);  analogWrite(10, 0);  analogWrite(11, 255);
    }
    else if (data == 'P') {
      analogWrite(9, 255);  analogWrite(10, 0);  analogWrite(11, 255);
    }
  }
}
