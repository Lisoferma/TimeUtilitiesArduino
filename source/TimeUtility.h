#ifndef TIME_UTILITIES_TIME_UTILITY_H
#define TIME_UTILITIES_TIME_UTILITY_H

#include "Time.h"
#include "ButtonName.h"
#include "IControllable.h"

namespace ArduinoFirmwareTimeUtilities
{
  // Интерфейс для взаимодействия с классами связанными со временем
  class TimeUtility : public IControllable
  {
  public:
    // Время вычисленное утилитой
    Time getTime() const;

    // Обновляет вычисленное время до актуального
    virtual void update() = 0;
  
  protected:
    // Время вычисленное утилитой
    Time time;
  };
}

#endif // TIME_UTILITIES_TIME_UTILITY_H