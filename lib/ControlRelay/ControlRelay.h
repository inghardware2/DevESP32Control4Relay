#include <Arduino.h>
#include <ArduinoSTL.h>
#include <iostream>

using namespace std;

//pins for relay control
#define pin1 12 
#define pin2 13 
#define pin3 14 
#define pin4 27 

class Relays
{
      private:
        int _relay1 = 1, _relay2 = 2, _relay3 = 3, _relay4 = 4;
        boolean IselectedRelay1 = false, IselectedRelay2 = false, IselectedRelay3 = false, IselectedRelay4 = false;
        int PinRelay1 = 0, PinRelay2 = 0, PinRelay3 = 0, PinRelay4 = 0;
        int actRelay=0;
        void configPinRelay(int pinAct);  
      public:
        void selectRelay(int numberRelay);         
        void stateON(int turnON_relay);
        void stateOFF(int turnOFF_relay);
};

//Relay selection
void Relays::selectRelay(int numberRelay)
{
        switch (numberRelay)
        {
        case 1:
                IselectedRelay1 = true;
                PinRelay1 = pin1;
                configPinRelay(pin1);
                break;
        case 2:
                IselectedRelay2 = true;
                PinRelay2 = pin2;
                configPinRelay(pin2);
                break;
        case 3:
                IselectedRelay3 = true;
                PinRelay3 = pin3;
                configPinRelay(pin3);
                break;
        case 4:
                IselectedRelay4 = true;
                PinRelay4 = pin4;
                configPinRelay(pin4);
                break;
        default:
                break;
        }      
}
//config OUTPUT pin by relay
void Relays::configPinRelay(int pinAct)
{
       
        if (IselectedRelay1)
        {
                actRelay = pinAct;
                IselectedRelay1 = false;
        }
        else if (IselectedRelay2)
        {
                actRelay = pinAct;
                IselectedRelay2 = false;
        }
        else if (IselectedRelay3)
        {
                actRelay = pinAct;
                IselectedRelay3 = false;
        }
        else if (IselectedRelay4)
        {
                actRelay = pinAct;
                IselectedRelay4 = false;
        }
        
        pinMode(actRelay, OUTPUT); //define relay pin how OUTPUT and it´s initialization is LOW state
        digitalWrite(actRelay, LOW);
}
//turn ON relay
void Relays::stateON(int turnON_relay)
{
        switch (turnON_relay)
        {
        case 1:
                digitalWrite(PinRelay1, HIGH);
                break;
        case 2:
                digitalWrite(PinRelay2, HIGH);
                break;
        case 3:
                digitalWrite(PinRelay3, HIGH);
                break;
        case 4:
                digitalWrite(PinRelay4, HIGH);
                break;
        default:
                break;
        }
}
//turn OFF relay
void Relays::stateOFF(int turnOFF_relay)
{
        switch (turnOFF_relay)
        {
        case 1:
                digitalWrite(PinRelay1, LOW);
                break;
        case 2:
                digitalWrite(PinRelay2, LOW);
                break;
        case 3:
                digitalWrite(PinRelay3, LOW);
                break;
        case 4:
                digitalWrite(PinRelay4, LOW);
                break;
        default:
                break;
        }
}