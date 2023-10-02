#ifndef TIME_UTILITIES_TIME_H
#define TIME_UTILITIES_TIME_H

#include "Arduino.h"

namespace ArduinoFirmwareTimeUtilities
{
  // Хранит время с точностью до секунд
  class Time
  {
  public:
    // Полное время в секундах
    unsigned long allTime;


    // Инициализировать временем прошедшим с момента запуска программы 
    Time();

    // Инициализировать время количеством секунд
    Time(unsigned long allTime);

    // Часы (в формате до двух знаков)
    char getHours() const;

    // Минуты (в формате до двух знаков)
    char getMinutes() const;
    
    // Секунды (в формате до двух знаков)
    char getSeconds() const;

    // Время прошедее с момента запуска программы
    static Time fromLaunch();

    Time operator + (Time time) const;

    Time operator - (Time time) const;

    Time operator = (Time time);

    bool operator == (Time time) const;

    bool operator <= (Time time) const;
  };
}

#endif // TIME_UTILITIES_TIME_H
