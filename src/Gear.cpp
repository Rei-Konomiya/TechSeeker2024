#include "Gear.h"


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
Gear::Gear(int pin, float off, float drive, float low, float medium, float high)
:off(off), drive(drive), low(low), medium(medium), high(high) {}

/** @fn
 * @brief pinModeの設定、setup関数内で呼び出す
 */
void Gear::start(){ pinMode(pin, ANALOG); }

/** @fn
 * @brief 値をアナログ値で取得し判別、重複なしのため値は 0~4で返す
 * @return モード番号
 */
int Gear::get(){
  int param = 0;
  float thresholds[] = {off, drive, low, medium, high};
  for(float th : thresholds){
    if(analogRead(pin) >= th) param ++;
  }
  return param; // off ~ high == 0 ~ 4
}