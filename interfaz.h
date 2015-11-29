#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "cajas.h"
#include "mostrardatos.h"
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class Interfaz:public QWidget
{
public:
    Interfaz();

    QWidget *ingresardatos;
    QWidget *mostrardatos;
    Cajas * box1;
    Cajas * box2;

    int anchop=900;
    int altop =500;
};

#endif // INTERFAZ_H
