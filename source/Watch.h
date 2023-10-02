#ifndef TIME_UTILITIES_WATCH_H
#define TIME_UTILITIES_WATCH_H

#include "Time.h"
#include "TimeUtility.h"
#include "ButtonName.h"
#include "TimeChanger.h"

namespace ArduinoFirmwareTimeUtilities
{
  // Часы
  class Watch : public TimeUtility
  {
  public:
    Watch();

    // Управление утилитой с помощью кнопок
    void control(ButtonName button) override;

    // Обновляет вычисленное время до актуального
    void update() override;

  private:
    // Часы тикают
    bool _isTicking;

    // Время старта часов
    Time _startTime;

    // Заданное пользователем время
    Time _setTime;
  };
}

#endif // TIME_UTILITIES_WATCH_H