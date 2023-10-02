#include "Stopwatch.h"

namespace ArduinoFirmwareTimeUtilities
{
  Stopwatch::Stopwatch()
  {
    _isTicking = false;
  }


  // Управление утилитой с помощью кнопок
  void Stopwatch::control(ButtonName button)
  {
    if (button != ButtonName::A) return;

    if (_isTicking == false)
    {
      if (time == 0)
      {
        // запуск
        _isTicking = true;
        _startTime = Time::fromLaunch();
      }         
      else
        // обнуление
        time = 0;             
    }
    else
      // остановка
      _isTicking = false;
  }


  // Обновляет вычисленное время до актуального
  void Stopwatch::update()
  {
    if (_isTicking == true)
      time = Time::fromLaunch() - _startTime; 
  }
}