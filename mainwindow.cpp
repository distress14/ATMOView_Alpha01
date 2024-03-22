#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QStringList>
#include <QStringListModel>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringListModel Sensors;     //Creates the list_model
    QStringList SensorList;     //Creates the actual list to store the available Sensors.
    SensorList << "Sensor1" << "Sensor2" << "Sensor3" << "Sensor4" << "Sensor5";     //TODO FIND NAMES
    Sensors.setStringList(SensorList);      //Sets the elements to the model
}





// QMainWindow::ui->ActiveSensors.setmodel(&Sensors);   //Links the model (elements) to the ListView gadget



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ActiveSensors_itemPressed(QListWidgetItem *SensorList)
{
    //Selezione del Sensore
}

