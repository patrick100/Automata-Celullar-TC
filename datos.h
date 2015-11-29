#ifndef DATOS_H
#define DATOS_H
#include <QLabel>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>
#include "string.h"
#include <QDebug>
#include <QObject>
#include <QWidget>
#include <fstream>
#include <sstream>

using namespace std;

class Datos:public QObject
{

public:
    Datos(QGroupBox *caja, QWidget * subpantalla);
    QWidget * mostrardatos;
    QGroupBox *caja_mostradora;

    QLabel *nombre_contra;
    QLineEdit *entrada_contra;
    QLineEdit *entrada_regla;
    QLabel *nombre_regla;
    QLabel *nombre_gene;
    QLineEdit *entrada_generaciones;
    QPushButton *button1;
    QPushButton *button_guardar;
    QPushButton *button_encriptar;
    QGroupBox *micaja;
    QWidget *bloque;

    int ancho_bloque;
    int alto_bloque;
    int ejex=0;
    int ejey=0;

    bool guardar=false;
    QLabel *contra_encriptada;
    QLineEdit *mostrar_contra;
    string contra;
    int regla;
    int num_generacion;
    ofstream myfile;
    string bin;
    vector <string> lineas;




public slots:
    void obtener_datos();
    string convert_int(string encriptada);
    void convascii();
    void guardarkey();
    string convert_binary(int entrada);
    void automata_celular(string binario, string regla, int generaciones);
    void imprimir_automata(string generacion);
    string encriptar();
private:
    //string binario;
};

#endif // DATOS_H
