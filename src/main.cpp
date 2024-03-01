#include <Arduino.h>
#include <Servo.h>
#include "InfraRed.h"
#include "Direction.h"
#include "SteerMotor.h"
#include "DriveMotor.h"
#include "SteerState.h"
#include "CCar.h"

CCar car;
void setup() {
 Serial.begin(9600);
 car.Init();
}

void loop() {
  car.Loop();
}
