#pragma once
class CCar
{
private:
    int turnAngle = 0;
    CSteerState steerState;
    CSteerMotor steerMotor;
    CDriveMotor driveMotor;
public:
    CCar();
    ~CCar();

    void Init();
    void Loop();
};

