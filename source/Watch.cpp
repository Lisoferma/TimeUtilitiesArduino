#include "Watch.h"

namespace ArduinoFirmwareTimeUtilities
{
  Watch::Watch()
  {
    _isTicking = false;
  }


  // Управление утилитой с помощью кнопок
  void Watch::control(ButtonName button)
  {
    if (button == ButtonName::A)
    {
      if (_isTicking == false)
      {
        // старт
        _isTicking = true;
        _startTime = Time::fromLaunch();
      }
      else
      {
        // пауза
        _isTicking = false;
      }
    }
    else
    {
      // установка времени
      _setTime = TimeChanger::changeTimeByButton(_setTime, button);
      time = _setTime;
    }
  }


  // Обновляет вычисленное время до актуального
  void Watch::update()
  {
    if (_isTicking == true)
    {
      // вычисление текущего времени
      time = Time::fromLaunch() - _startTime + _setTime;

      if (time.getHours() >= 24)
      {
        _setTime = 0;
        _startTime = Time::fromLaunch();
      }     
    }
  }
}