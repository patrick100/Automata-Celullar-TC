#include <QApplication>
#include <QVBoxLayout>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <QDebug>
#include <interfaz.h>

using namespace std;

/*
void test()
{
    string temp =contra->text().toStdString();
    std :: string str (temp);
    QString qstr (str. c_str ());
    //var = "sdfasd";
    qDebug ()  <<"PRESS.."<< qstr;
}
*/

int main(int argc, char *argv[])
{
     //string contra;
     //cout<<"Ingrese la contrasena a encriptar:"<<endl;
     //cin>>contra;
     //convascii(contra);
     QApplication app(argc, argv);
     //Creamos la pantalla principal
     Interfaz *vent = new Interfaz();
     vent->show();
     //Muestra las pantallas
     //ingresardatos->setParent(window);
     //mostrardatos->setParent(window);
     return app.exec();
}





