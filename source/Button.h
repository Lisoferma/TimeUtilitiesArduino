#ifndef TIME_UTILITIES_BUTTON_H
#define TIME_UTILITIES_BUTTON_H

#include "Arduino.h"
#include "ButtonName.h"
#include "TimeUtility.h"

namespace ArduinoFirmwareTimeUtilities
{
  // Кнопка.
  // Имеет возможность обратного вызова метода IControllable::control при клике на кнопку
  class Button
  {
  public:
    // pin - пин к которму подключена кнопка;
    // name - название кнопки;
    // controlledUtility - утилита под управлением кнопки
    Button(char pin, ButtonName name, IControllable* controlledUtility);

    // Опрос кнопки на клик
    void update();

  private:
    // Защитная задержка от ложного срабатывания кнопки при дребезге
    static const unsigned int DEBOUNCE_DELAY = 100;

    // Промежуток времени через который будет фиксироваться клик при зажатии кнопки
    static const unsigned int PRESS_DELAY = 300;

    // Пин к которму подключена кнопка
    char _pin;

    // Кнопка зажата
    bool _pressed;

    // Время первого срабатывания кнопки
    unsigned int _activationTime;

    // Название кнопки   
    ButtonName _buttonName;

    // Утилита под управлением кнопки
    IControllable* _controlledUtility;


    // Кнопка нажата
    bool isClicked();

    // Проверка на дребезг кнопки при нажатии
    // true - не дребезг
    bool isNotBounce() const;

    // Кнопка зажата длительное время
    bool isPressed() const;
  };
}

#endif // TIME_UTILITIES_BUTTON_H