#include <AccelStepper.h>

const int s1StepPin = 6;
const int s1DirPin = 7;
const int s1EnablePin = 8;

// TMC2209 controller
AccelStepper s1(AccelStepper::DRIVER, s1StepPin, s1DirPin);

void setup() {
    // set elow = enable s1
    pinMode(s1EnablePin, OUTPUT);
    digitalWrite(s1EnablePin, LOW);  

    // s1 config
    s1.setMaxSpeed(6000);
    s1.setAcceleration(1000);
    s1.moveTo(10000);
}

void loop() {
    // continious loop 
  s1.run();
  if (s1.distanceToGo() == 0) {
    s1.moveTo(-s1.currentPosition());
  }
}
