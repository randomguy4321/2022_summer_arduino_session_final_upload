#include <SoftwareSerial.h>
#include <AFMotor.h>
int sL = A0;
int sR = A5;

AF_DCMotor motorL(1);
AF_DCMotor motorR(4);

void setup() {
  // put your setup code here, to run once:
  motorL.setSpeed(200);
  motorL.run(RELEASE);
  motorR.setSpeed(232);
  motorR.run(RELEASE);

  Serial.begin(9600);
  pinMode(sL, INPUT);
  pinMode(sR, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val_L = digitalRead(sL);
  int val_R = digitalRead(sR);
//  Serial.print("L: ");
//  Serial.print(val_L);
//  Serial.print("    R: ");
//  Serial.println(val_R);
//  delay(300);

  if(val_L == 1 && val_R == 1) {
    motorL.run(RELEASE);
    motorR.run(RELEASE);
  }
  else if(val_L == 1 && val_R == 0) {
    motorL.run(RELEASE);
    motorR.run(FORWARD);
  }
  else if(val_L == 0 && val_R == 1) {
    motorL.run(FORWARD);
    motorR.run(RELEASE);
  }
  else if(val_L == 0 && val_R == 0) {
    motorL.run(FORWARD);
    motorR.run(FORWARD);
  }
}
