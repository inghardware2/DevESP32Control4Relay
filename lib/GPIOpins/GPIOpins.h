#include <Arduino.h>
#include <ArduinoSTL.h>
#include <iostream>

using namespace std;

class GPIOPin
{
  private:
    int GPIO1 = 1,
        GPIO2 = 2,
        GPIO3 = 3,
        GPIO4 = 4,
        GPIO5 = 5,
        GPIO12 = 12,
        GPIO13 = 13,
        GPIO14 = 14,
        GPIO15 = 15,
        GPIO16 = 16,
        GPIO17 = 17,
        GPIO18 = 18,
        GPIO19 = 19,
        GPIO21 = 21,
        GPIO22 = 22,
        GPIO23 = 23,
        GPIO25 = 25,
        GPIO26 = 26,
        GPIO27 = 27,
        GPIO32 = 32,
        GPIO33 = 33,
        GPIO34 = 34,
        GPIO35 = 35,
        GPIO36 = 36,
        GPIO39 = 39;

  public:
    void selectGPIO(int selectedGPIO, int IO, int state);
    void selectGPIOinput(int selectinput);
    void stateHIGH(int Hpin);
    void stateLOW(int Lpin);
    int QueryPin(int pin);
};
//
void GPIOPin::selectGPIOinput(int selectinput)
{
  pinMode(selectinput, INPUT);
}
//
void GPIOPin::selectGPIO(int selectedGPIO, int IO, int state)
{
  if (IO == 0)
  {
    pinMode(selectedGPIO, OUTPUT);
  }
  else if (IO == 1)
  {
    pinMode(selectedGPIO, INPUT);
  }
  //
  if (state == 0)
  {
    digitalWrite(selectedGPIO, LOW);
  }
  else if (state == 1)
  {
    digitalWrite(selectedGPIO, HIGH);
  }
}
//
void GPIOPin::stateHIGH(int Hpin)
{
  digitalWrite(Hpin, HIGH);
}
void GPIOPin::stateLOW(int Lpin)
{
  digitalWrite(Lpin, LOW);
}
//
int GPIOPin::QueryPin(int pin)
{
  int valor = digitalRead(pin);
  if(valor == LOW)
  {
    return 1;
  }
  else if(valor == HIGH)
  {
    return 0;
  }
}