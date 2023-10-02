#include "Timer.h"

namespace ArduinoFirmwareTimeUtilities
{
  Timer::Timer()
  {
    _isTicking = false;
  }


  // Управление утилитой с помощью кнопок
  void Timer::control(ButtonName button)
  {
    if (button == ButtonName::A)
    {
      if (_isTicking == false)
      {
        // старт
        _isTicking = true;
        _endTime = _endTime + Time::fromLaunch();
      }
      else
      {
        // пауза
        _isTicking = false;
        _endTime = _endTime - Time::fromLaunch();
        time = _endTime;
      }
    }
    else
    {
      // установка времени
      _endTime = TimeChanger::changeTimeByButton(_endTime, button);
      time = _endTime;
    }
  }


  // Обновляет вычисленное время до актуального
  void Timer::update()
  {
    if (_isTicking == true)
    {
      // вычисление оставшегося времени
      time = _endTime - Time::fromLaunch();

      if (time <= 0)
      {
        _isTicking = false;
        _endTime = 0;
        time = 0;
      }       
    }
  }
}