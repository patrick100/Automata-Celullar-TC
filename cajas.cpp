#include "cajas.h"

Cajas::Cajas(QWidget *pantalla_datos,QWidget * mostrar_datos, int y)
{
    caja1 = new QGroupBox(pantalla_datos);
    caja1->setGeometry(0,y,300,500);
    eti_contra = new Datos(caja1,mostrar_datos);
}

