#ifndef TIME_UTILITIES_I_CONTROLLABLE_H
#define TIME_UTILITIES_I_CONTROLLABLE_H

#include "ButtonName.h"

namespace ArduinoFirmwareTimeUtilities
{
  // Предоставляет метод для управления с помощью кнопок
  class IControllable
  {
  public:
    // Управление с помощью кнопок
    virtual void control(ButtonName button) = 0;
  };
}

#endif // TIME_UTILITIES_I_CONTROLLABLE_H