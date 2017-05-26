#include <Servo.h>

Servo pan;  // < ----- > max position = 70-130
Servo tilt; // top/botom max position = 10-50

// Random position

int pinLaser = 2;
int iRandomTilt, iRandomPan;

void setup() {
  
  // Init laser & turn it ON
  pinMode (pinLaser, OUTPUT);
  digitalWrite(pinLaser, LOW);
  delay(100);
  digitalWrite(pinLaser, HIGH);

  // Init til & pan servo
  pan.attach(8);
  tilt.attach(9);
  delay(500);
}


void loop() {
  // New random values for tilt & pan
  iRandomTilt = random(10, 80);
  iRandomPan = random(70, 130);
  
  tilt.write(iRandomTilt);
  delay(1500);
  
  pan.write(iRandomPan);
  delay(1500);

}
