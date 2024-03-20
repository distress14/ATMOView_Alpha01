#include <iostream>
#include <math.h>
#include "../include/Sensor.h"

const int MAX_X = 50;
const int MAX_Y = 50;
const int MIN_X = 0;
const int MIN_Y = 0;

Sensor::Sensor()
{
    //TODO
}

 //TODO == Adds 1 new Sensor to the SXSideSensor tab. Need to POP-UP an "alert" (New window) in which must be added ID - SensorType - FromXML. Remaining are optional


bool Sensor::InputSanification()
{
    if (IsOutOfBonds(posX, posY) || (! ValidSensorType(SensorType)))    //Checks if IsOutOfBonds && if ValidSensorType IS NOT true
    {
        std::cout << "Something went wrong with the Input. Error: 001 " << std::endl;   //Error 001 - Errors will be "sequential", so I can track easly where the error is
        return 0;      //Exit the program. TODO --> Display Error on the "alert" window and recall a NEW "alert" window, asking gently if you can choose between 0-5
    }

    return 1;        //Input is OK
}


bool Sensor::IsOutOfBonds(const float User_X, const float User_Y)
{
    if ((User_X > MAX_X) || (User_Y > MAX_Y))      //Checks if the User choosed a valid position within the max_BoundlLmit of the map
    {
        std::cout << "Cazzone Hai sbagliato a mettere una posizione decente. Mettine una valida" << std::endl;
        std::cout << "Error 002" << std::endl;
        return 0;
    }
    if ((User_X < MIN_X) || (User_Y < MIN_Y))       //Checks if the User choosed a valid position within the min_BoundlLmit of the map
    {
        std::cout << "Cazzone Hai sbagliato a mettere una posizione decente. Mettine una valida" << std::endl;
        std::cout << "Error 003" << std::endl;
        return 0;
    }

    return 1;     //Bound is OK
}


bool Sensor::ValidSensorType()       //Checks if the User choosed an avaible Sensor. Returns 1 if OK. 0 otherwise
{                                       //TODO code inside Cases
    switch (SensorType)
    {
    case 0:
        std::cout << "You choose the Sensor #0 " << std::endl;
        break;
    case 1:
        std::cout << "You choose the Sensor #1 " << std::endl;
        break;
    case 2:
        std::cout << "You choose the Sensor #2 " << std::endl;
        break;
    case 3:
        std::cout << "You choose the Sensor #3 " << std::endl;
        break;
    case 4:
        std::cout << "You choose the Sensor #4 " << std::endl;
        break;
    default:
        std::cout << "Bastardo scegli bene" << std::endl;
        return 0;

    }
    return 1;  //Type is OK
}

