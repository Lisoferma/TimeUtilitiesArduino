#ifndef TIME_UTILITIES_TIMER_H
#define TIME_UTILITIES_TIMER_H

#include "Time.h"
#include "TimeUtility.h"
#include "ButtonName.h"
#include "TimeChanger.h"

namespace ArduinoFirmwareTimeUtilities
{
  // Таймер
  class Timer : public TimeUtility
  {
  public:
    Timer();

    // Управление утилитой с помощью кнопок
    void control(ButtonName button) override;

    // Обновляет вычисленное время до актуального
    void update() override;

  private:
    // Таймер тикает
    bool _isTicking;

    // Время от начала запуска программы
    // когда таймер будет равен нулю
    Time _endTime;
  };
}

#endif // TIME_UTILITIES_TIMER_H