#ifndef SENSOR_H
#define SENSOR_H

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
    Sensor();  //constructor of the Class Sensor
    ~Sensor();  //Deconstructor of the Class Sensor
    bool InputSanification();    //Checks if the User was that gentle to use a valid Input during the "Form". Returns 1 if OK //TODO InputForm
    bool IsOutOfBonds(const float posX, const float posY);    //Checks if the User used a valid position within the Map bounds. Returns 0 if OK
    bool ValidSensorType(const int SensorType);   //Checks if the User choosed an avaible Sensor. Returns 1 if OK

    //TODO
    //void CalculateSensorValue(float SensorValue);   //It does every calculation on the actual value and returns it updated.
};



#endif // SENSOR_H
