#include "Button.h"

namespace ArduinoFirmwareTimeUtilities
{ 
  // pin - пин к которму подключена кнопка;
  // name - название кнопки;
  // controlledUtility - утилита под управлением кнопки
  Button::Button(char pin, ButtonName name, IControllable* controlledUtility)
  {
    _pin = pin;
    pinMode(_pin, INPUT_PULLUP);
    _buttonName = name;
    _controlledUtility = controlledUtility;    
    _activationTime = millis();    
  }


  // Опрос кнопки на клик
  void Button::update()
  {
    if (isClicked())
      _controlledUtility->control(_buttonName);
  }


  // Кнопка нажата
  bool Button::isClicked()
  {
    bool isPowered = !digitalRead(_pin);

    if (isPowered && !_pressed && isNotBounce())
    {
      _pressed = true;
      _activationTime = millis();
      return true;
    }
    else if (isPowered && _pressed && isPressed())
    {
      _activationTime = millis();
      return true;
    }
    else if (!isPowered && _pressed)
    {
      _pressed = false;
      _activationTime = millis();
    }

    return false;
  }


  // Проверка на дребезг кнопки при нажатии
  // true - не дребезг
  bool Button::isNotBounce() const
  {
    return (millis() - _activationTime >= DEBOUNCE_DELAY);
  }


  // Кнопка зажата длительное время
  bool Button::isPressed() const
  {
    return (millis() - _activationTime >= PRESS_DELAY);
  }
}