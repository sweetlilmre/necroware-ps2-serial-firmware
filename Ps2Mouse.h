#pragma once

#include <Arduino.h>

class Ps2Mouse {
public:

  struct Data {
    bool leftButton;
    bool middleButton;
    bool rightButton;
    int  xMovement;
    int  yMovement;
  };

  struct Settings {
    bool scaling;
    byte resolution;
    byte sampleRate;
  };
  
  Ps2Mouse();

  bool reset(bool streaming);

  bool setScaling(bool flag) const;
  bool setResolution(byte resolution) const;
  bool setSampleRate(byte sampleRate) const;

  bool getSettings(Settings& settings) const;

  bool enableStreaming();
  bool disableStreaming();
  bool readData(Data& data) const;

private:
  struct Impl;

  bool m_stream;
};
