#include <ESP32Servo.h>
#include <Stepper.h>

const int stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 16, 17, 18, 19);
Servo myServo;  

int servoPosition = 0;
int increment = 10;

void setup() {
  myServo.write(servoPosition);
  myServo.attach(27);
  Serial.begin(115200);
  myStepper.setSpeed(10);
}

void loop(){

  // set motor positions
  myStepper.step(2048);
  servoPosition = servoPosition + increment;
  if (servoPosition >= 180) {
    servoPosition = 0;
  }
  myServo.write(servoPosition);
  
//  delay(2000);
}
