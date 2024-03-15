#include <iostream>
#include <math.h>


class Sensor
{
private:
    const float posX, posY;    //Using const cause the position will be fixed once selected, and float (32bit) instead of double (64 bit)
    const int Identification;   //ID-Identification will not change once selected.
    const int SensorType;   //Needs to be 0-4 (max 5 Sensors). It will be the ID for the Sensor type choosed.  //TODO SANIFICATION of INPUT
    int LastUpdate;     // Keep tracking time of last update of the XML file (if used)
    float SensorValue;         //Actual value of the Sensor (Not used int cause I wanna the PRECISION)
    float SensorValueMax;    //If needed, a bottom value (es:temperature)
    float SensorValueMin;   //If needed, a maximum value (es:temperature)
    float LastSensorValue;    //It can be used to do the comparation PRE-ACTUAL in (+/-)%
    const bool FromXML;    //Bool const which tells me if the User choosed to use an XML file. 0: Not Used | 1: Used -> Do not start Simulation for that Sensor

public:
/*
 * void NewSensor()   //Adds 1 new Sensor to the SXSideSensor tab. Need to POP-UP an "alert" (New window) in which must be added ID - SensorType - FromXML. Remaining are optional
    {
        if (InputSanification() == 0){    //Calls the [TODO bool InputSanification function], which returns True if the Input is respected, 0 otherwise
            std::cout << "Something went wrong with the Input. Error: 001 " << std::endl;   //Error 001 - Errors will be "sequential", so I can track easly where the error is
            return 0;      //Exit the program. TODO --> Display Error on the "alert" window and recall a NEW "alert" window, asking gently if you can choose between 0-5
        }


    }
    void DeleteSensor()
    {

    }

*/
};
