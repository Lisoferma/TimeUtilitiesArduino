#ifndef TIME_UTILITIES_TIME_CHANGER_H
#define TIME_UTILITIES_TIME_CHANGER_H

#include "Time.h"
#include "ButtonName.h"

namespace ArduinoFirmwareTimeUtilities
{
  class TimeChanger
  {
  public:
    // Кнопка отвечающая за изменение секунд
    static const ButtonName CHANGE_SECONDS_BUTTON = ButtonName::B;

    // Кнопка отвечающая за изменение минут
    static const ButtonName CHANGE_MINUTES_BUTTON = ButtonName::C;

    // Кнопка отвечающая за изменение часов
    static const ButtonName CHANGE_HOURS_BUTTON = ButtonName::D;


    // Изменяет еденицы времени относительно переданной кнопки
    // (если единица времени максимальна вернёт 00):
    // B: +секунда;
    // C: +минута;
    // D: +час (максимум часов - 23).
    // time - время которое нужно изменить;
    // button - название кнопки.
    // Возвращает изменённое время.
    static Time changeTimeByButton(Time time, ButtonName button)
    {
      switch (button)
      {
        case CHANGE_SECONDS_BUTTON:
          if (time.getSeconds() == 59)
            return time - 59;
          else
            return time + 1;

        case CHANGE_MINUTES_BUTTON:
          if (time.getMinutes() == 59)
            return time - 3540; // отнимаем количество секунд в 59 минутах
          else
            return time + 60; // прибавляем минуту в секундах

        case CHANGE_HOURS_BUTTON:
          if (time.getHours() == 23)
            return time - 82800; // отнимаем количество секунд в 23 часах
          else
            return time + 3600; // прибавляем час в секундах

        default:
          return time;
      }
    }
  };
}

#endif // TIME_UTILITIES_TIME_CHANGER_H