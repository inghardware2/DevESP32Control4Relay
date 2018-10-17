#include <Arduino.h>
#include <ArduinoSTL.h>

#include "ControlRelay.h"

using namespace std;

//instances of objects in the Relays class
Relays relay1;
Relays relay2;
Relays relay3;
Relays relay4;

void setup()
{
    Serial.begin(115200);
    // cout << "Relevo seleccionado: 1" << endl;
    relay1.selectRelay(1);   
    relay2.selectRelay(2);
    relay3.selectRelay(3);
    relay4.selectRelay(4);

}

void loop()
{
    
}
