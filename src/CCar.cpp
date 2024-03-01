#include <Arduino.h>
#include <Servo.h>
#include "InfraRed.h"
#include "Direction.h"
#include "SteerMotor.h"
#include "DriveMotor.h"
#include "SteerState.h"
#include "CCar.h"
#include "pins.h"

CCar::CCar()
{
    steerMotor = CSteerMotor(PIN_ENA_PUNTE_FATA, PIN_INPUT_3_PUNTE_FATA, PIN_INPUT_4_PUNTE_FATA);
    steerState = CSteerState(PIN_INPUT_IR_STANGA, PIN_INPUT_IR_DREAPTA);
    driveMotor = CDriveMotor(PIN_ENB_PUNTE_SPATE, PIN_INPUT_1_PUNTE_SPATE, PIN_INPUT_2_PUNTE_SPATE);
}

CCar::~CCar()
{
}


void CCar::Init(){
    steerMotor.Init();
    steerState.Init();
    driveMotor.Init();
}

void CCar::Loop(){
    steerState.Loop();
    steerMotor.WriteSpeed(100/*directionState.GetPredictedTurnSpeed()*/, steerState.GetPredictedSteerDirection());
    driveMotor.WriteSpeed(50, DriveDirection::FORWARD);
}

