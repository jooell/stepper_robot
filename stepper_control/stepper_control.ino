#include <AccelStepper.h>
#include <MultiStepper.h>

const int s1EnablePin = 5;    // g
const int s1StepPin =   4;    // b
const int s1DirPin =    3;    // y

const int s2EnablePin = 8;    // g
const int s2StepPin =   7;    // b
const int s2DirPin =    6;    // p

const int s3EnablePin = 11;    // g
const int s3StepPin =   10;    // b
const int s3DirPin =    9;     // p


// TMC2209 controller
AccelStepper s1(AccelStepper::DRIVER, s1StepPin, s1DirPin);
AccelStepper s2(AccelStepper::DRIVER, s2StepPin, s2DirPin);
AccelStepper s3(AccelStepper::DRIVER, s3StepPin, s3DirPin);

MultiStepper steppers;

long positions[3];

void setup() {
    // set low = enable s1
    pinMode(s1EnablePin, OUTPUT);
    digitalWrite(s1EnablePin, LOW);  

    // set low = enable s2
    pinMode(s2EnablePin, OUTPUT);
    digitalWrite(s2EnablePin, LOW);  

    // set low = enable s3
    pinMode(s3EnablePin, OUTPUT);
    digitalWrite(s3EnablePin, LOW);  

    // stepper config
    s1.setMaxSpeed(700);
    s1.setAcceleration(500);

    s2.setMaxSpeed(700);
    s2.setAcceleration(500);

    s3.setMaxSpeed(700);
    s3.setAcceleration(500);

    steppers.addStepper(s1);
    steppers.addStepper(s2);
    steppers.addStepper(s3);

    positions[0] = 1000;
    positions[1] = 1000;
    positions[2] = 1000;
    steppers.moveTo(positions);

}

void loop() {

  if (steppers.run()) {

    return;
  }

  positions[0] = -positions[0];
  positions[1] = -positions[1];
  positions[2] = -positions[2];
  steppers.moveTo(positions);

}
