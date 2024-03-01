#pragma once

class CDriveMotor
{
public:
    CDriveMotor(){};
    ~CDriveMotor();
    CDriveMotor(unsigned char _pin_PWM, unsigned char _pin_in1, unsigned char _pin_in2);
    void Init();
    void Loop();
    void WriteSpeed(unsigned char _speed, DriveDirection _direction = DriveDirection::NONE);
    inline DriveDirection GetCurrentDriveDirection() { return m_Direction; }
private:
    DriveDirection m_Direction = DriveDirection::NONE;
    unsigned char pin_PWM = 0;
    unsigned char pin_in1 = 0;
    unsigned char pin_in2 = 0;
};
