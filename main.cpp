#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QStringList>
#include <QStringListModel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Alpha01_OOP_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    MainWindow w;

    QStringListModel Sensors;     //Creates the list_model
    QStringList SensorList;     //Creates the actual list to store the available Sensors.
    SensorList << "Sensor1" << "Sensor2" << "Sensor3" << "Sensor4" << "Sensor5";     //TODO FIND NAMES
    Sensors->setStringList(SensorList);      //Sets the elements to the model

   // QMainWindow::ui->ActiveSensors.setmodel(&Sensors);   //Links the model (elements) to the ListView gadget








    w.show();



    return a.exec();
}
