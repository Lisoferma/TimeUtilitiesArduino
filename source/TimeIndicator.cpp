#include "TimeIndicator.h"

namespace ArduinoFirmwareTimeUtilities
{
  // digit1 - digit6 - пины отвечающие за подсветку разрядов индикатора, от 0 до 5 разряда;
  // updatePin, dataPin, clkPin - пины для управления сдвиговым регистром
  TimeIndicator::TimeIndicator(char digit1, char digit2, char digit3, char digit4, char digit5,
    char digit6, char updatePin, char dataPin, char clkPin)
  {
    _digit_pins[0] = digit1;
    _digit_pins[1] = digit2;
    _digit_pins[2] = digit3;
    _digit_pins[3] = digit4;
    _digit_pins[4] = digit5;
    _digit_pins[5] = digit6;

    _updatePin = updatePin;
    _dataPin = dataPin;
    _clkPin = clkPin;

    pinMode(_updatePin, OUTPUT);
    pinMode(_dataPin, OUTPUT);
    pinMode(_clkPin, OUTPUT);

    for (int i = 0; i < INDICATOR_SIZE; ++i)
      pinMode(_digit_pins[i], OUTPUT);
  }


  // Вывести время на индикатор в формате hours.minutes.seconds
  void TimeIndicator::displayTime(Time time)
  {
    setTimeToDisplay(time);

    for(int i = 0; i < INDICATOR_SIZE; ++i)
    {
      digitalWrite(_updatePin, LOW);
      shiftOut(_dataPin, _clkPin, MSBFIRST, _numbersToDisplay[i]);
      digitalWrite(_updatePin, HIGH);

      digitalWrite(_digit_pins[i], LOW);   
      delay(1);
      digitalWrite(_digit_pins[i], HIGH);  
    }
  }


  // Установить время для последующего вывода на индикатор
  void TimeIndicator::setTimeToDisplay(Time time)
  {
    // Цифры одной из единиц измерения
    byte timeUnit[2] = { 0 };

    getArrayDigits(time.getSeconds(), timeUnit, 2); 
    _numbersToDisplay[0] = DIGITS_CODE[timeUnit[0]];
    _numbersToDisplay[1] = DIGITS_CODE[timeUnit[1]];
    timeUnit[1] = 0;

    getArrayDigits(time.getMinutes(), timeUnit, 2); 
    _numbersToDisplay[2] = DIGITS_CODE[timeUnit[0]] | DOT_CODE;
    _numbersToDisplay[3] = DIGITS_CODE[timeUnit[1]];
    timeUnit[1] = 0;

    getArrayDigits(time.getHours(), timeUnit, 2); 
    _numbersToDisplay[4] = DIGITS_CODE[timeUnit[0]] | DOT_CODE;
    _numbersToDisplay[5] = DIGITS_CODE[timeUnit[1]];
    timeUnit[1] = 0;
  }


  // Получить массив цифр из числа.
  // number - число которое нужно разложить на массив цифр;
  // digits - указатель на массив цифр который будет получен после работы функции;
  // limit  - максимум цифр
  void TimeIndicator::getArrayDigits(byte number, byte* digits, byte limit)
  {
    byte digitsCount = 0;

    if (number == 0)
    {
      digits[0] = 0;
      return;
    }

    while (number > 0 && limit)
    {
      digits[digitsCount++] = number % 10;
      number /= 10;
      limit--;
    }
  }
}