#pragma once
#include <Arduino.h>

int BUT(
  byte pin, //пин с INPUT_PULLUP
  int timeStop = 2000, //время бездействия после которого программа выходит из функции
  int touch = 100,  //предотврошение дребезга контактов
  int TAS = 10, //количество считываемых раз в сикунду (1000 / TAS)
  bool EX = 0 //выход если кнопка не нажата
) 
{
  unsigned long pm = millis(); //счетчик выхода
  int but = 0; //количество нажатий на кнопку
  if (digitalRead(pin) == 1 && EX == 1) 
  {
    return 0;
  }
  while (true) //безконечный цикл
  {
    if (digitalRead(pin) == 0) //прочитать с pin
    {
      but += 1; //увеличеть количество нажатий на 1
      delay(touch); // предотвратить дребезг контактов
      pm = millis(); //обнулить счетчик выхода
    }
    
    delay(1000 / TAS); //регулировка скорости цикла
    if (pm + timeStop < millis()) //если бездействие больше timeStop выйти из цикла
    {
      break;
    }
  }
  return but; //передать значение but
}
