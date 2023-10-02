#ifndef TIME_UTILITIES_TIME_INDICATOR_H
#define TIME_UTILITIES_TIME_INDICATOR_H

#include "Time.h"
#include "Arduino.h"

namespace ArduinoFirmwareTimeUtilities
{
  // Семи-сегментный шести-разрядный дисплей для отображения времени
  class TimeIndicator
  {
  public:
    // Количество разрядов на индикаторе
    static const char INDICATOR_SIZE = 6;


    // digit1 - digit6 - пины отвечающие за подсветку разрядов индикатора, от 0 до 5 разряда;
    // updatePin, dataPin, clkPin - пины для управления сдвиговым регистром
    TimeIndicator(char digit1, char digit2, char digit3, char digit4, char digit5,
      char digit6, char updatePin, char dataPin, char clkPin);

    // Вывести время на индикатор в формате hours.minutes.seconds
    void displayTime(Time time);

  private:
    // Пины для управления сдвиговым регистром
    char _updatePin;
    char _dataPin;
    char _clkPin;

    // Пины отвечающие за подсветку разрядов индикатора, от 0 до 5 разряда.
    // Например DIGIT_PINS[0] равно пину отвечающему за крайний правый разряд на индикаторе
    char _digit_pins[INDICATOR_SIZE];

    // Коды цифр от 0 до 9 для передачи сдвигающему регистру.
    // Например DIGITS_CODE[3] равно 3 на индикаторе
    const char DIGITS_CODE[10] = {
      0b00111111,
      0b00000110,
      0b01011011,
      0b01001111,
      0b01100110,
      0b01101101,
      0b01111101,
      0b00000111,
      0b01111111,
      0b01101111 };

    // Код точки для передачи сдвигающему регистру
    static const char DOT_CODE = 0b10000000;

    // Массив цифр которые будут выводится на индикатор
    byte _numbersToDisplay[INDICATOR_SIZE] = { 0 };


    // Получить массив цифр из числа.
    // number - число которое нужно разложить на массив цифр;
    // digits - указатель на массив цифр который будет получен после работы функции;
    // limit  - максимум цифр
    void getArrayDigits(byte number, byte* digits, byte limit);

    // Установить время для последующего вывода на индикатор
    // в формате hours.minutes.seconds
    void setTimeToDisplay(Time time);
  };
}

#endif // TIME_UTILITIES_TIME_INDICATOR_H