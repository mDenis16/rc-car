#pragma once

class CSteerState
{
    constexpr static float factor = 1.85;
    constexpr static int baseAngle = 90;

public:
    CSteerState(){};
    CSteerState(unsigned char _IR_left, unsigned char _IR_right);
    void Loop();
    void Init();

    inline SteerDirection &GetPredictedSteerDirection() { return predictedTurnDirection; }

private:
    CInfraRed left;
    CInfraRed right;
    Servo servo;

    SteerDirection predictedTurnDirection = SteerDirection::NONE;
    unsigned long lastExecutionTime = 0;
    float targetValue = 0;
    float deltaTime = 0;
    unsigned long nextTimeCalc = 0;
    unsigned short delay = 0;
};