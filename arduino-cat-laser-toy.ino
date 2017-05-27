#include <Servo.h>

Servo pan;  // < ----- > max position = 70-130
Servo tilt; // top/botom max position = 10-50

// Random position

int pinLaser = 2;
int iRandomTilt, iRandomPan;
int iOldTilt = 20;
int iOldPan = 70;
int angleT, angleP;

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
  iRandomTilt = random(30, 90);
  iRandomPan = random(60, 140);

  if (iOldTilt < iRandomTilt) {
    for(angleT = iOldTilt; angleT < iRandomTilt; angleT++) {                                  
      tilt.write(angleT);               
      delay(20);                   
    } 
  } else {
    for(angleT = iOldTilt; angleT > iRandomTilt; angleT--) {                                  
      tilt.write(angleT);               
      delay(20);                   
    } 
  }

  if (iOldPan < iRandomTilt) {
    for(angleP = iOldPan; angleP < iRandomPan; angleP++) {                                  
      pan.write(angleP);               
      delay(20);                   
    } 
  } else {
    for(angleP = iOldPan; angleP > iRandomPan; angleP--) {                                  
      pan.write(angleP);               
      delay(20);                   
    } 
  }

  iOldTilt = iRandomTilt;
  iOldPan = iRandomPan;

}
