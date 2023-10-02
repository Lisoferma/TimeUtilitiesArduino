#include "Time.h"
#include "TimeIndicator.h"
#include "Button.h"
#include "ButtonName.h"
#include "TimeUtility.h"
#include "TimeUtilityManager.h"
#include "Stopwatch.h"
#include "Timer.h"
#include "Watch.h"

using namespace ArduinoFirmwareTimeUtilities;

// Пины для управления сдвиговым регистром
#define UPDATE_PIN 11
#define DATA_PIN   12
#define CLK_PIN    13

// Пины отвечающие за подсветку разрядов индикатора, от 0 до 5 разряда
#define INDICATOR_DIGIT_1_PIN 10
#define INDICATOR_DIGIT_2_PIN 9
#define INDICATOR_DIGIT_3_PIN 8
#define INDICATOR_DIGIT_4_PIN 7
#define INDICATOR_DIGIT_5_PIN 6
#define INDICATOR_DIGIT_6_PIN 5

// Пины кнопок
#define BUTTON_A_PIN 4
#define BUTTON_B_PIN 3
#define BUTTON_C_PIN 2
#define BUTTON_D_PIN 1
#define BUTTON_E_PIN 0

// Индикатор на который выводится время
TimeIndicator indicator(INDICATOR_DIGIT_1_PIN,
  INDICATOR_DIGIT_2_PIN,
  INDICATOR_DIGIT_3_PIN,
  INDICATOR_DIGIT_4_PIN,
  INDICATOR_DIGIT_5_PIN,
  INDICATOR_DIGIT_6_PIN,
  UPDATE_PIN,
  DATA_PIN,
  CLK_PIN);

// Менеджер для переключения между утилитами;
// Через него происходит управление и получение времени от выбранной утилиты
TimeUtilityManager timeUtilityManager;

// Кнопки управления
Button buttonA(BUTTON_A_PIN, ButtonName::A, &timeUtilityManager);
Button buttonB(BUTTON_B_PIN, ButtonName::B, &timeUtilityManager);
Button buttonC(BUTTON_C_PIN, ButtonName::C, &timeUtilityManager);
Button buttonD(BUTTON_D_PIN, ButtonName::D, &timeUtilityManager);
Button buttonE(BUTTON_E_PIN, ButtonName::E, &timeUtilityManager);


void setup()
{
  timeUtilityManager.utilities.add(new Stopwatch());
  timeUtilityManager.utilities.add(new Timer());
  timeUtilityManager.utilities.add(new Watch());
}


void loop()
{
  buttonA.update();
  buttonB.update();
  buttonC.update();
  buttonD.update();
  buttonE.update();

  timeUtilityManager.update();
  Time timeToDisplay = timeUtilityManager.getTime();

  indicator.displayTime(timeToDisplay);
}








