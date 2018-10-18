#include <Arduino.h>
#include <ArduinoSTL.h>

#include "ControlRelay.h"
#include "GPIOpins.h"

using namespace std;

//timer event
volatile int interruptCounter;

//instances of objects in the Relays class
Relays valveRelay;

//instances of objects in the GPIOpins class
//led state by ON/OFF electrovalvule
GPIOPin ledIndicator;
//pin control by ON/OFF electrovalvule
GPIOPin valveSwitch;

//global variable
boolean IsSwitch1Push = false;
boolean IsSwitch2Push = false;

int counterSwitch1 = 0, counterSwitch2 = 0, counterSwitch3 = 0, counterSwitch4 = 0;

void setup()
{
    Serial.begin(115200);
    // cout << "Relevo seleccionado: 1" << endl;
    valveRelay.selectRelay(1);
    valveRelay.selectRelay(2);
    valveRelay.selectRelay(3);
    valveRelay.selectRelay(4);
    //
    //configure pin led state switch
    ledIndicator.selectGPIOoutput(4, 0);
    ledIndicator.selectGPIOoutput(5, 0);
    ledIndicator.selectGPIOoutput(15, 0);
    ledIndicator.selectGPIOoutput(18, 0);
    //
    //configure pin switch
    valveSwitch.selectGPIOinput(19);
    valveSwitch.selectGPIOinput(21);
    valveSwitch.selectGPIOinput(22);
    valveSwitch.selectGPIOinput(23);
}

void loop()
{
    if (IsSwitch2Push == false)
    {
        int t1 = valveSwitch.readPin(22);
        if (t1 == HIGH)
        {
            counterSwitch1++;
            switch (counterSwitch1)
            {
            case 1:
                IsSwitch1Push = true;
                cout << "Initialization of cicle; valve Enabled" << endl;
                ledIndicator.stateHIGH(4);
                valveRelay.stateON(2);
                delay(1000);
                break;
            case 2:
                counterSwitch1 = 0;
                IsSwitch1Push = false;
                cout << "Finalization of cicle; valve Disabled" << endl;
                ledIndicator.stateLOW(4);
                valveRelay.stateOFF(2);
                delay(1000);
                break;
            }
        }
    }
    if (IsSwitch1Push == false)
    {
        int t2 = valveSwitch.readPin(23);
        if (t2 == HIGH)
        {
            counterSwitch2++;
            switch (counterSwitch2)
            {
            case 1:
                IsSwitch2Push = true;
                cout << "Initialization of cicle; valve Enabled" << endl;
                ledIndicator.stateHIGH(15);
                valveRelay.stateON(2);
                delay(1000);
                break;
            case 2:
                counterSwitch2 = 0;
                IsSwitch2Push = false;
                cout << "Finalization of cicle; valve Disabled" << endl;
                ledIndicator.stateLOW(15);
                valveRelay.stateOFF(2);
                delay(1000);
                break;
            }
        }
    }
}
