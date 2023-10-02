#include "TimeUtilityManager.h"

namespace ArduinoFirmwareTimeUtilities
{
  TimeUtilityManager::TimeUtilityManager()
  {
    _currentUtilityIndex = 0;
  }


  // Управление менеджером с помощью кнопок
  void TimeUtilityManager::control(ButtonName button)
  {
    if (utilities.isEmpty()) return;

    // Переключение на следующую утилиту на заданую кнопку, иначе управляем выбранной утилитой
    if (button == UTILITY_SWITCH_BUTTON)
    {
      SetUtilityIndexToNext();
    }
    else
    {
      utilities[_currentUtilityIndex]->control(button);
    }
  }


  // Обновляет вычисленное время выбранной утилиты до актуального
  void TimeUtilityManager::update()
  {
    utilities[_currentUtilityIndex]->update();
    time = utilities[_currentUtilityIndex]->getTime();
  }


  // Установить индекс, указывающий на текущую утилиту, на следующую утилиту из списка 
  void TimeUtilityManager::SetUtilityIndexToNext()
  {
    // Если дошли до конца списка, возвращаемся к первой утилите
    if (_currentUtilityIndex == utilities.getSize() - 1)
    {
      _currentUtilityIndex = 0;
    }
    else
    {
      ++_currentUtilityIndex;
    }  
  }
}