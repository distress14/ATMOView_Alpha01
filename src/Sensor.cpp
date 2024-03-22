#include <iostream>
#include <math.h>
#include <QInputDialog>    //Allows opening the actual Input window asking the UserInput
#include <QLineEdit>      //Allows users to enter and edit a single line of plain text
#include <QVBoxLayout>    //Allows the creation of usefull Vertical_layouts
#include <QString>      //Allows to save the UserInput
#include <QLabel>      //Widget for labels
#include "../include/Sensor.h"

const int MAX_X = 50;
const int MAX_Y = 50;
const int MIN_X = 0;
const int MIN_Y = 0;
const int IDENTIFICATION_MAX_LENGHT_DIV = 10000;   // if (12345 /  IDENTIFICATION_MAX_LENGHT_DIV == 0,12345) < 1  ok . if (Id.lenght = 123456 /IDMLD == 1,23456) not ok

Sensor::Sensor()
{
    //Asking for SensorInput
    GetUserInput();


    //Checking UserInput
    //InputSanification();
    //TODO
}

 //TODO == Adds 1 new Sensor to the SXSideSensor tab. Need to POP-UP an "alert" (New window) in which must be added ID - SensorType - FromXML. Remaining are optional


void Sensor::GetUserInput()  //Needs to
{
    QDialog UserInputWindow;        //Creates a new Window Object


    UserInputWindow.setWindowTitle("Add a new Sensor to the collection");    //Sets the windows title

    QVBoxLayout *InputLayout = new QVBoxLayout(&UserInputWindow);   //Adds a Vertical Layout (see SensorLayout) to the dialog window to arrange the "elements"

    //TODO -> HBoxLayout per dividere i due input posX e posY

    //TODO -> See Things That Needs to be checked


    QLabel *IdentificationLabel = new QLabel("Inserisci ID", &UserInputWindow);
    InputLayout->addWidget(IdentificationLabel);
    QLineEdit *InputIdentification = new QLineEdit(&UserInputWindow);    //Crates a new text edit box for Identification
    InputLayout->addWidget(InputIdentification);

    QLabel *PositionXLabel = new QLabel("Inserisci coordinate X", &UserInputWindow);
    InputLayout->addWidget(PositionXLabel);
    QLineEdit *InputPositionX = new QLineEdit(&UserInputWindow);    //Crates a new text edit box for User_posX
    InputLayout->addWidget(InputPositionX);

    QLabel *PositionYLabel = new QLabel("Inserisci coordinate Y", &UserInputWindow);
    InputLayout->addWidget(PositionYLabel);
    QLineEdit *InputPositionY = new QLineEdit(&UserInputWindow);    //Crates a new text edit box for User_posX
    InputLayout->addWidget(InputPositionY);





    if (UserInputWindow.exec() == QDialog::Accepted)
    {
        int Identification;
        QString StringIdentification = InputIdentification->text();
        Identification = StringIdentification.toInt();      //Converting possible string to INT  //TBD if need to report error message in string Input <> int

        QString PositionX = InputPositionX->text();
        this->posX = PositionX.toFloat();
        QString PositionY = InputPositionY->text();
        this->posY = PositionY.toFloat();




        InputSanification(Identification, posX, posY);

    }

}











bool Sensor::InputSanification(int InputID, float posX, float posY)   //Errors 100 - 199 --> Input
{
    if (IsOutOfBonds(posX, posY) || (! ValidSensorType(SensorType)))    //Checks if IsOutOfBonds && if ValidSensorType IS NOT true
    {
        std::cout << "You tryed to use a position Out of Bonds of the map, or selected an unavailable sensor. Please try again" << std::endl;   //Errors will be "sequential", so I can track easly where the error is

        return 0;      //Exit the program. TODO --> Display Error on the "alert" window and recall a NEW "alert" window, asking gently if you can choose between 0-5
    }

    if ( (InputID / IDENTIFICATION_MAX_LENGHT_DIV) < 1)   //ID lenght limit is 5 digits
    {
        this->Identification = InputID;    //ACCEPT THE ID and STORE IT
    }
    else
    {
        std::cout << "ID is a 5 digit integer. Try again" << std::endl;   //Error message for Id that exceed digit limit
        std::cout << "Error 102" << std::endl;    //Error 102 -> IDNot5digit
        return 0;     //Exit the program. TODO --> Display Error on the "alert" window and recall a NEW "alert" window
    }


    return 1;        //Input is OK
}


bool Sensor::IsOutOfBonds(const float User_X, const float User_Y)
{
    if ((User_X > MAX_X) || (User_Y > MAX_Y))      //Checks if the User choosed a valid position within the max_BoundlLmit of the map
    {
        std::cout << "Upper Bound exceeded" << std::endl;
        std::cout << "Error 199" << std::endl;     //Error 199 -> UpperBoundExceeded
        return 0;
    }
    if ((User_X < MIN_X) || (User_Y < MIN_Y))       //Checks if the User choosed a valid position within the min_BoundlLmit of the map
    {
        std::cout << "Lower Bound exceeded" << std::endl;
        std::cout << "Error 101" << std::endl;    //Error 101 -> LowerBoundExceeded
        return 0;
    }



    return 1;     //Bound is OK
}


bool Sensor::ValidSensorType(int SensorType)       //Checks if the User choosed an avaible Sensor. Returns 1 if OK. 0 otherwise
{                                       //TODO code inside Cases
    switch (SensorType)
    {
    case 0:
        std::cout << "You choose the Sensor #0 " << std::endl;
        this->SensorType = 0;
        break;
    case 1:
        std::cout << "You choose the Sensor #1 " << std::endl;
        this->SensorType = 1;
        break;
    case 2:
        std::cout << "You choose the Sensor #2 " << std::endl;
        this->SensorType = 2;
        break;
    case 3:
        std::cout << "You choose the Sensor #3 " << std::endl;
        this->SensorType = 3;
        break;
    case 4:
        std::cout << "You choose the Sensor #4 " << std::endl;
        this->SensorType = 4;
        break;
    default:
        std::cout << "This sensor is not available now. Please select from 0 to 4. " << std::endl;
        return 0;

    }
    return 1;  //Type is OK
}


