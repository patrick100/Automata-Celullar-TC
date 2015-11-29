#include "interfaz.h"

Interfaz::Interfaz()
{
 this->setFixedSize(anchop,altop);
 //Creamos las subpantallas
 ingresardatos = new QWidget;
 ingresardatos->setFixedSize(anchop-600,altop);
 ingresardatos->setStyleSheet("background-color:#EAD4A5;");
 ingresardatos->setParent(this);
 //Para mostrar los datos
 mostrardatos = new QWidget;
 mostrardatos->setGeometry(300,0,900-300,500);
 mostrardatos->setStyleSheet("background-color:#FFFFFF;");
 mostrardatos->setParent(this);

 //Creamos las cajas de ingresardatos

 box1 = new Cajas(ingresardatos,mostrardatos,0);
 //box2 = new Cajas(ingresardatos,mostrardatos,250);


}


