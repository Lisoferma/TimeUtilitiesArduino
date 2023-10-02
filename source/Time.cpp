#include "Time.h"

namespace ArduinoFirmwareTimeUtilities
{
  // Инициализировать временем прошедшим с начала запуска программы 
  Time::Time()
  {
    allTime = fromLaunch().allTime;
  }


  // Инициализировать время количеством секунд
  Time::Time(unsigned long seconds)
  {
    this->allTime = seconds;
  }


  // Часы (в формате до двух знаков)
  char Time::getHours() const
  {
    return (allTime / 3600ul);
  }


  // Минуты (в формате до двух знаков)
  char Time::getMinutes() const
  {
    return (allTime % 3600ul) / 60ul;
  }


  // Секунды (в формате до двух знаков)
  char Time::getSeconds() const
  {
    return (allTime % 3600ul) % 60ul;
  }


  // Время прошедее с момента запуска программы
  Time Time::fromLaunch()
  {
    return millis() / 1000ul;
  }


  Time Time::operator + (Time time) const
  {
    return Time{allTime + time.allTime};
  }


  Time Time::operator - (Time time) const
  {
    return Time{allTime - time.allTime};
  }


  Time Time::operator = (Time time)
  {
    return Time{allTime = time.allTime};
  }


  bool Time::operator == (Time time) const
  {
    return allTime == time.allTime;
  }


  bool Time::operator <= (Time time) const
  {
    return allTime <= time.allTime;
  }
}