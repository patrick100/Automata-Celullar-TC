#ifndef CAJAS_H
#define CAJAS_H
#include <QGroupBox>
#include "datos.h"


class Cajas
{
public:
    Cajas(QWidget*pantalla_datos, QWidget *mostrar_datos, int y);
    QGroupBox *caja1;
    Datos *eti_contra;
};

#endif // CAJAS_H
