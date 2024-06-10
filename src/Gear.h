#pragma once

#include <Arduino.h>

class Gear {
public:

  Gear(int pin, float off, float drive, float low, float medium, float high);

  void start();
  int get();

private:
  int pin;
  float off;
  float drive;
  float low;
  float medium;
  float high;
};