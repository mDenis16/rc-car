#pragma once

class CSteerMotor
{
public:
    CSteerMotor(){};
    CSteerMotor(unsigned char _pin_PWM, unsigned char _pin_in1, unsigned char _pin_in2);
    void Init();
    void WriteSpeed(unsigned char _speed, SteerDirection _direction = SteerDirection::NONE);
    inline SteerDirection GetCurrentSteerDirection() { return m_Direction; }
private:
    SteerDirection m_Direction = SteerDirection::NONE;
    unsigned char pin_PWM = 0;
    unsigned char pin_in1 = 0;
    unsigned char pin_in2 = 0;
};
