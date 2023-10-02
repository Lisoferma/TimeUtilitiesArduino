#ifndef TIME_UTILITIES_TIME_UTILITY_MANAGER_H
#define TIME_UTILITIES_TIME_UTILITY_MANAGER_H

#include "TimeUtility.h"
#include "ButtonName.h"
#include <List.hpp>

namespace ArduinoFirmwareTimeUtilities
{
  // Менеджер для переключения между утилитами;
  // Через него происходит управление и получение времени от выбранной утилиты
  class TimeUtilityManager : public TimeUtility
  {
  public:
    // Кнопка на которую происходит переключение между утилитами
    const ButtonName UTILITY_SWITCH_BUTTON = ButtonName::E;

    // Список утилит между которыми можно переключаться
    List<TimeUtility*> utilities;


    TimeUtilityManager();

    // Управление менеджером с помощью кнопок
    void control(ButtonName button) override;

    // Обновляет вычисленное время выбранной утилиты до актуального
    void update() override;

  private:
    // Индекс текущей выбранной утилиты в списке утилит
    char _currentUtilityIndex;


    // Установить индекс, указывающий на текущую утилиту, на следующую утилиту из списка 
    void SetUtilityIndexToNext();
  };
}

#endif // TIME_UTILITIES_TIME_UTILITY_MANAGER_H