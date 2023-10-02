#ifndef TIME_UTILITIES_STOPWATCH_H
#define TIME_UTILITIES_STOPWATCH_H

#include "Time.h"
#include "TimeUtility.h"
#include "ButtonName.h"

namespace ArduinoFirmwareTimeUtilities
{
  // Секундомер
  class Stopwatch : public TimeUtility
  {
  public:
    Stopwatch();
    
    // Управление утилитой с помощью кнопок
    void control(ButtonName button) override;

    // Обновляет вычисленное время до актуального
    void update() override;

  private:
    // Секундомер тикает
    bool _isTicking;

    // Время старта секундомера
    Time _startTime;
  };
}

#endif // TIME_UTILITIES_STOPWATCH_H