#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
private:      //All arguments are set to 0 as Default.
    float posX = 0, posY = 0;    //Using const cause the position will be fixed once selected, and float (32bit) instead of double (64 bit)  [CONST?]
    int Identification = 0;   //ID-Identification will not change once selected.  [CONST?]
    int SensorType = 0;   //Needs to be 0-4 (max 5 Sensors). It will be the ID for the Sensor type choosed.   [CONST?]
    int LastUpdate = 0;     // Keep tracking time of last update of the XML file (if used)
    float SensorValue = 0;         //Actual value of the Sensor (Not used int cause I wanna the PRECISION)
    float SensorValueMax = 0;    //If needed, a bottom value (es:temperature)
    float SensorValueMin = 0;   //If needed, a maximum value (es:temperature)
    float LastSensorValue = 0;    //It can be used to do the comparation PRE-ACTUAL in (+/-)%
    bool FromXML = 0;    //Bool const which tells me if the User choosed to use an XML file. 0: Not Used | 1: Used -> Do not start Simulation for that Sensor.    [CONST?]

public:
    Sensor();  //constructor of the Class Sensor
    ~Sensor();  //Deconstructor of the Class Sensor
    bool InputSanification(int Identification, float posX, float posY);    //Checks if the User was that gentle to use a valid Input during the "Form". Returns 1 if OK //TODO InputForm
    bool IsOutOfBonds(const float posX, const float posY);    //Checks if the User used a valid position within the Map bounds. Returns 0 if OK
    bool ValidSensorType(const int SensorType);   //Checks if the User choosed an avaible Sensor. Returns 1 if OK

    void GetUserInput();  //Opens a new dialog windows that asks to define Sensor ID - posX & posY - SensorType
    //TODO
    // virtual void CalculateSensorValue(float SensorValue);   //It does every calculation on the actual value and returns it updated.
};



#endif // SENSOR_H
