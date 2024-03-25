#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial BTSerial(4, 5);
Servo myservo;

#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988

int notes1[25] = { NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_G4, 
NOTE_E4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_G4, NOTE_G4, 
NOTE_A4, NOTE_A4, NOTE_G4, NOTE_G4,NOTE_E4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_E4,NOTE_C4 };

int notes2[] = {
  NOTE_D4, 0, NOTE_F4, NOTE_D4, 0, NOTE_D4, NOTE_G4, NOTE_D4, NOTE_C4,
  NOTE_D4, 0, NOTE_A4, NOTE_D4, 0, NOTE_D4, NOTE_AS4, NOTE_A4, NOTE_F4,
  NOTE_D4, NOTE_A4, NOTE_D5, NOTE_D4, NOTE_C4, 0, NOTE_C4, NOTE_A3, NOTE_E4, NOTE_D4,
  0,NOTE_D4,NOTE_D4
};
int duration[] = {
  8, 8, 6, 16, 16, 16, 8, 8, 8, 
  8, 8, 6, 16, 16, 16, 8, 8, 8,
  8, 8, 8, 16, 16, 16, 16, 8, 8, 2,
  8,4,4
};

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  myservo.attach(6);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

}

void loop() {
  if (BTSerial.available()) {
    char data = BTSerial.read();
    if (data == '1') {
      digitalWrite(9, HIGH); digitalWrite(10, HIGH); digitalWrite(11, HIGH);
    }
    else if (data == '2') {
      digitalWrite(9, LOW); digitalWrite(10, LOW); digitalWrite(11, LOW);
    }
    else if (data == '3') {
      myservo.write(180);
    }
    else if (data == '4') {
      myservo.write(0);
    }
    else if (data == '5') {
      music_1();
    }
    else if (data == '6') {
            music_2();
    }
  }
}


void music_1() {

  for (int i = 0; i < 12; i++) {
    tone (8, notes1[ i ], 200);
    delay (300);
  }
  delay(100);

  for (int i = 12; i < 25; i++) {
    tone (8 , notes1[ i ], 200);
    delay(300);
  }
}

void music_2() {
 
    for (int i= 0; i < (sizeof(notes2)/sizeof(int)); i++) {

    int noteDuration = 1000 / duration[i]; //convert duration to time delay
    tone(8, notes2[i], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;//Here 1.30 is tempo, decrease to play it faster
    delay(pauseBetweenNotes);
    noTone(8); //stop music on buzzer pin 
    }
}



// https://ddangeun.tistory.com/19
