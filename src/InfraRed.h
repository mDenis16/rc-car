#pragma once
class CInfraRed {
public:
  CInfraRed(){

  };
  unsigned char pin;
  bool analogPin = false;
  int firstReadValue = -1;
  CInfraRed(unsigned char _pin, bool _analogPin = true) {
    pin = _pin;
    analogPin = _analogPin;
  };

  bool Read();
  void Init();
};