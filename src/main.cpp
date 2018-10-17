#include <Arduino.h>
#include <ArduinoSTL.h>

#include "ControlRelay.h"
#include "GPIOpins.h"

using namespace std;

//instances of objects in the Relays class
Relays relay1;
Relays relay2;
Relays relay3;
Relays relay4;

//instances of objects in the GPIOpins class
GPIOPin led1;

void setup()
{
    Serial.begin(115200);
    // cout << "Relevo seleccionado: 1" << endl;
    relay1.selectRelay(1);
    relay2.selectRelay(2);
    relay3.selectRelay(3);
    relay4.selectRelay(4);
    
    led1.selectGPIO(23,0,1);
    
    

    /*
    cout << "Relevo seleccionado: 1" << endl;
    relay1.stateON(1);
    delay(2000);
    relay1.stateOFF(1);
    delay(1000);
    cout << "Relevo seleccionado: 2" << endl;
    relay2.stateON(2);
    delay(2000);
    relay2.stateOFF(2);
    delay(1000);
    cout << "Relevo seleccionado: 3" << endl;
    relay3.stateON(3);
    delay(2000);
    relay3.stateOFF(3);
    delay(1000);
    cout << "Relevo seleccionado: 4" << endl;
    relay4.stateON(4);
    delay(2000);
    relay4.stateOFF(4);
    */
}

void loop()
{
   // cout << "activo led 1" << endl;
  //  led1.stateHIGH(4);
  /*  delay(1000);
    cout << "desactivo led 1" << endl;
    led1.stateLOW(4);
    delay(1000);
    */
}
