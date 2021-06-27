#include <M5Core2.h>

#define LGFX_M5STACK_CORE2
#include <LovyanGFX.hpp>

static LGFX lcd;

void setup()
{
  M5.begin(true, true, true, true);

  lcd.init();
  lcd.setFont(&fonts::lgfxJapanGothic_28);
  lcd.setBrightness(128);
  lcd.setCursor(0, 128);
  lcd.println("はろーテスト壱");
}

void loop()
{
  M5.update();

  float batVol = M5.Axp.GetBatVoltage();
  float batCur = M5.Axp.GetBatCurrent();

  lcd.setCursor(0, 156);
  lcd.printf("Baterry: %1.3f\nCurrent: %.3f\n", batVol, batCur);

  if (batCur < 0) {
    delay(500);
    lcd.setBrightness(0);
    lcd.sleep();
    delay(500);
    lcd.wakeup();
    lcd.setBrightness(128);
  }
}