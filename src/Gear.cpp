﻿#include "Gear.h"

/** 
 * @class Gear
 * @brief 前後するギアチェンジレバーの管理クラス
 */
class Gear {
public:
  /** @fn
   * @brief コンストラクタ、しきい値やピン番号の設定
   * 
   * @param pin    ピン番号
   * @param off    オフ のしきい値
   * @param drive  ドライブ のしきい値
   * @param low    弱 のしきい値
   * @param medium 中 のしきい値
   * @param high   強 のしきい値
   */
  Gear(int pin, float off, float drive, float low, float medium, float high)
  :off(off), drive(drive), low(low), medium(medium), high(high) {}

  /** @fn
   * @brief pinModeの設定、setup関数内で呼び出す
   */
  void start(){ pinMode(pin, ANALOG); }

  int get(){
    int param = 0;
    float thresholds[] = {off, drive, low, medium, high};
    for(float th : thresholds){
      if(analogRead(pin) >= th) param ++;
    }
    return param; // off ~ high == 0 ~ 4
  }

private:
  int pin;      // アナログ入力ピン番号
  float off;    // off時のしきい値、0と予想
  float drive;  // drive時のしきい値
  float low;    // low時のしきい値
  float medium; // medium時のしきい値
  float high;   // high時のしきい値
};