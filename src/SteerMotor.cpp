#include "Arduino.h"
#include "Direction.h"
#include "SteerMotor.h"


/*
out4
Input1	Input2	Spinning Direction
Low(0)	Low(0)	Motor OFF
High(1)	Low(0)	Forward
Low(0)	High(1)	Backward
High(1)	High(1)	Motor OFF
*/

CSteerMotor::CSteerMotor(unsigned char _pin_PWM, unsigned char _pin_in1, unsigned char _pin_in2)
{
    pin_PWM = _pin_PWM;
    pin_in1 = _pin_in1;
    pin_in2 = _pin_in2;
}
void CSteerMotor::Init()
{
    pinMode(pin_PWM, OUTPUT);
    pinMode(pin_in1, OUTPUT);
    pinMode(pin_in2, OUTPUT);
}

void CSteerMotor::WriteSpeed(unsigned char speed, SteerDirection _direction)
{
    m_Direction = _direction;

    analogWrite(pin_PWM, speed);
    
    switch (_direction)
    {
    case SteerDirection::LEFT:
        digitalWrite(pin_in1, HIGH);
        digitalWrite(pin_in2, LOW);
        break;
    case SteerDirection::RIGHT:
        digitalWrite(pin_in1, LOW);
        digitalWrite(pin_in2, HIGH);
        break;
    default:
        digitalWrite(pin_in1, LOW);
        digitalWrite(pin_in2, LOW);
        break;
    }
}
