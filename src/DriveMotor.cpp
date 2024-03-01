#include <Arduino.h>
#include "Direction.h"
#include "DriveMotor.h"

CDriveMotor::CDriveMotor(unsigned char _pin_PWM, unsigned char _pin_in1, unsigned char _pin_in2)
{
    pin_PWM = _pin_PWM;
    pin_in1 = _pin_in1;
    pin_in2 = _pin_in2;
}

CDriveMotor::~CDriveMotor()
{
}

void CDriveMotor::Init()
{
    pinMode(pin_PWM, OUTPUT);
    pinMode(pin_in1, OUTPUT);
    pinMode(pin_in2, OUTPUT);
}
void CDriveMotor::Loop()
{
    // other logic
}

void CDriveMotor::WriteSpeed(unsigned char _speed, DriveDirection _direction )
{
    analogWrite(pin_PWM, _speed);
    switch (_direction)
    {
    case DriveDirection::FORWARD:
        digitalWrite(pin_in1, HIGH);
        digitalWrite(pin_in2, LOW);
        break;
    case DriveDirection::BACKWARD:
        digitalWrite(pin_in1, LOW);
        digitalWrite(pin_in2, HIGH);
        break;
    default:
        digitalWrite(pin_in1, LOW);
        digitalWrite(pin_in2, LOW);
        break;
    }
}