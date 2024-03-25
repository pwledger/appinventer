#include <DHT.h>

#include <SoftwareSerial.h>

DHT dht(3, DHT11);
SoftwareSerial BTSerial(4, 5);

int soil = A0;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);

  dht.begin();
}
void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  int soilHumi = analogRead(soil);  //토양수분센서값 측정

  /*블루투스 통신*/
  // [＂온도,습도,토양수분"]
  BTSerial.print(t); // 온도
  BTSerial.print(",");
  BTSerial.print(h); // 습도
  BTSerial.print(",");
  BTSerial.print(soilHumi); // 토양수분

  Serial.print(t); // 온도
  Serial.print(",");
  Serial.print(h); // 습도
  Serial.print(",");
  Serial.println(soilHumi); // 토양수분

  delay(1000);
}
