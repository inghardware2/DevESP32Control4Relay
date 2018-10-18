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
//led state by ON/OFF electrovalvule
GPIOPin led1;
GPIOPin led2;
GPIOPin led3;
GPIOPin led4;
//pin control by ON/OFF electrovalvule
GPIOPin switch1;
GPIOPin switch2;
GPIOPin switch3;
GPIOPin switch4;

void setup()
{
    Serial.begin(115200);
    // cout << "Relevo seleccionado: 1" << endl;
    relay1.selectRelay(1);
    relay2.selectRelay(2);
    relay3.selectRelay(3);
    relay4.selectRelay(4);
    //
    //configure pin led state switch
    led1.selectGPIO(4,0,0);
    led2.selectGPIO(5,0,0);
    led3.selectGPIO(15,0,0);
    led4.selectGPIO(18,0,0);
    //
    //configure pin switch
    switch1.selectGPIO(19,1,0);
    switch2.selectGPIO(21,1,0);
    switch3.selectGPIO(22,1,0);
    switch4.selectGPIO(23,1,0);

}

void loop()
{
    int ta = switch1.QueryPin(19);

    if(ta == 1)
    {
        led1.stateHIGH(4);
    }
   // cout << "activo led 1" << endl;
  //  led1.stateHIGH(4);
  /*  delay(1000);
    cout << "desactivo led 1" << endl;
    led1.stateLOW(4);
    delay(1000);
    */
}
