#include <Arduino.h>
#include <Servo.h>
#include "InfraRed.h"
#include "Direction.h"
#include "SteerState.h"
// in2 pin 3
// in1 pin 4

// enb pin 5
// in4 pin 6

// ena a5

// d6 - ph3
CSteerState::CSteerState(unsigned char _IR_left, unsigned char _IR_right)
{
    left = CInfraRed(_IR_left);
    right = CInfraRed(_IR_right);
    delay = 2;
}
void CSteerState::Init()
{
    left.Init();
    right.Init();
    servo.attach(10);
    nextTimeCalc = millis() + delay;
    servo.write(baseAngle);
}
void CSteerState::Loop()
{
    if ((millis() - lastExecutionTime) >= delay)
    {
        deltaTime = (millis() - lastExecutionTime) / delay;

        if (left.Read())
            targetValue += factor * deltaTime;
        if (right.Read())
            targetValue -= factor * deltaTime;

        targetValue = constrain(targetValue, -45, 45);

        servo.write(baseAngle + targetValue);

        if (targetValue <= -15)
            predictedTurnDirection = SteerDirection::LEFT;
        else if (targetValue >= 15)
            predictedTurnDirection = SteerDirection::RIGHT;

        lastExecutionTime = millis();
    }
}
