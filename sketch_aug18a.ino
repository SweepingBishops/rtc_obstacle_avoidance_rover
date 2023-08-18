#include <Servo.h>
Servo servo;
const int trigPin = 9;
const int echoPin=10;
const int enRight = 3;
const int right = 4;
const int rightRev = 5;
const int enLeft = 6;
const int left = 7;
const int leftRev = 8;
#define SOUND_VELOCITY 0.034
long duration;
float distance;

const int spookDistance = 35;
int servo_pos=0;
int increaseServoAngle=1;



void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(enRight, OUTPUT);
  pinMode(enLeft, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(rightRev, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(leftRev, OUTPUT);
  servo.attach(2)
  servo.write(servo_pos);
  delay(10);
}

void loop() {
  if (servo_pos == 180) {
    increaseAngle = -1;
  } else if (servo_pos == 0) {
    increaseAngle = 1;
  }
  servo_pos += increaseAngle;
  servo.write(servo_pos);  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*SOUND_VELOCITY/2;
  
  if (distance > 35) {
    digitalWrite(right, HIGH);
    digitalWrite(left, HIGH);
    digitalWrite(rightRev, LOW);
    digitalWrite(leftRev, LOW);    
  }
}
