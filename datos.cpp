#include "datos.h"

//Convertir la entrada m1ca20dos a 0 y 1

Datos::Datos(QGroupBox *caja, QWidget *subpantalla)
{
    mostrardatos = subpantalla;
    micaja = caja;
    contra=" ";
    regla=0;
    num_generacion=0;
    //Pantalla donde se van a mostrar los datos

    //Creamos los Qlabel
    //PARA INGRESAR LA CONTRASEÑA
    nombre_contra = new QLabel("INGRESAR CONTRASEÑA:");
    nombre_contra->setGeometry(0,0,150,20);
    nombre_contra->setParent(caja);
    entrada_contra = new QLineEdit(caja);
    entrada_contra->setGeometry(150,0,120,20);
    //PARA INGRESAR LA REGLA
    nombre_regla = new QLabel("INGRESAR REGLA:");
    nombre_regla->setGeometry(0,30,150,20);
    nombre_regla->setParent(caja);
    entrada_regla = new QLineEdit(caja);
    entrada_regla->setGeometry(150,30,120,20);
    //PARA INGRESAR LAS GENERACIONES
    nombre_gene = new QLabel("INGRESAR GENERACIONES:");
    nombre_gene->setGeometry(0,70,150,20);
    nombre_gene->setParent(caja);
    entrada_generaciones = new QLineEdit(caja);
    entrada_generaciones->setGeometry(150,70,120,20);
    //PARA CREAR EL BOTON EJECUTAR
    button1 = new QPushButton("Ejecutar");
    button1->setGeometry(10,115,100,20);
    button1->setParent(caja);
    //PARA MOSTRAR LA CONTRASEÑA ENCRIPTADA
    mostrar_contra = new QLineEdit(caja);
    mostrar_contra->setGeometry(130,115,150,30);



    //PARA CREAR EL BOTON BORRAR
    button_guardar = new QPushButton("GUARDAR KEY");
    button_guardar->setGeometry(100,180,100,20);
    button_guardar->setParent(caja);

    //PARA CREAR EL BOTTON ENCRIPTAR
    button_encriptar = new QPushButton("ENCRIPTAR KEY");
    button_encriptar->setGeometry(100,200,100,20);
    button_encriptar->setParent(caja);

    connect(button1,&QPushButton::clicked,this,obtener_datos);
    connect(button_encriptar,&QPushButton::clicked,this,encriptar);
    connect(button_guardar,&QPushButton::clicked,this,guardarkey);

}



void Datos::obtener_datos()
{
    //std :: string str (micontra);
    //QString qstr (str. c_str ());
    //qDebug ()  <<"PRESS.."<< qstr;
    contra =entrada_contra->text().toStdString();
    regla = entrada_regla->text().toInt();
    num_generacion = entrada_generaciones->text().toInt();

   if(contra!=" " && regla!=0 && num_generacion!=0)
   {

        bloque = new QWidget;
        bloque->setGeometry(0,0,600,500);
        bloque->setStyleSheet("background-color:#FFFFFF;");
        bloque->setParent(mostrardatos);
        bloque->show();
        ancho_bloque =0;
        alto_bloque =0;
        ejex =0;
        ejey =0;

        convascii();
   }

}

string Datos::encriptar()
{
    ifstream archivo;
    string encriptada;
    string linea;
    string contras = bin;
    archivo.open("c:\\Users\\jeff\\Documents\\key.txt");
    if (archivo.is_open())
    {
        while (!archivo.eof())
        {
            getline(archivo,linea);
            lineas.push_back(linea);
        }
        archivo.close();
    }
   //XOR
    string temp;
    vector <string>::iterator it = lineas.begin();
    while(it!=lineas.end()-1)
    {
        temp = *it;
        encriptada = "";
        for(int i=0;i<temp.length();i++)
        {
            if(contras[i]==temp[i])
            {
              encriptada = encriptada + "0";
            }
            else
            {
              encriptada = encriptada + "1";
            }
        }
        std::string str (encriptada);
        QString qstr (str. c_str ());
        qDebug ()  <<"DESPUES DEL XOR->"<< qstr;
        contras = "";
        contras=encriptada;
     it++;
    }

    //std::string str (encriptada);
    //QString qstr (str. c_str ());
    //qDebug ()  <<"ESTO ES LA CONTRA EN BINARIO->"<< qstr;

    string copia;
    string pal_encriptada;
    int j =0;
    for(int i =0 ;i<encriptada.length(); i++)
    {
        copia = copia + encriptada[i];
        if(j==6)
        {
            std::string str (copia);
            QString qstr (str. c_str ());
            qDebug ()  <<"DESPUES DE SACAR 7->"<< qstr;
            pal_encriptada = pal_encriptada +convert_int(copia);
            copia ="";
            j=-1;
        }
        j++;
    }

    std::string str (pal_encriptada);//
    QString qstr (str. c_str ());
    qDebug ()  <<"ENCRIPTADA LA FIRMEEEE->"<< qstr;
    QFont font("Consolas", 18, QFont::Bold,true);
    mostrar_contra->setFont(font);
    mostrar_contra->setText(qstr);
    //ELIMINAR LO YA NO HAGA FALTA
}

string Datos::convert_int(string encriptada)
{
    int nume=0;
    char a;
    string letra;
    stringstream ss;
    int lista[]={64,32,16,8,4,2,1};
    for(int i=0;i<encriptada.length();i++)
    {
       if(encriptada[i]=='1')
       {
           nume = nume + lista[i];

       }
    }

    //std::string str (convert_int(copia));
    //QString qstr (str. c_str ());
    qDebug() <<"EN NUMEROS->"<< QByteArray::number(nume);
    //qDebug ()  <<"EN NUMEROS->"<< qstr;

    a=static_cast<char>(nume);
    ss << a;
    ss >> letra;
    return letra;
}


void Datos::convascii()
{
    int num;
    string binario;
    string temp;
    //Convierto con contra en ascci y despues en binario
    for(int i =0;i<contra.length(); i++)
    {
        num = int(contra[i]);
        temp = convert_binary(num);
        while(temp.length()<7)
        {
            temp = "0"+temp;
        }
        binario = binario+temp;
    }
    alto_bloque = 500/num_generacion;
    ancho_bloque = 600/binario.length();

    //Genero la regla en binario
    string regla_binaria = convert_binary(regla);
    automata_celular(binario,regla_binaria,num_generacion);
}


void Datos::automata_celular(string binario,string regla,int generaciones)
{

if(guardar==true)
{
   myfile.open("c:\\Users\\jeff\\Documents\\key.txt");
}

string nueva="0";
string wolframe[]={"111","110","101","100","011","010","001","000"};
string temp;

int k =0;
//Completo la regla con 0s A LA izquierda
while(regla.length()<8)
{
    regla="0"+regla;
}



//std::string str (binario);
//QString qstr (str. c_str ());
//qDebug ()  <<"CREANDO LAS GENERACIONES 1RA->"<< qstr;

while(k<generaciones)
{

for(int i=1; i<binario.length()-1;i++)
{
    temp = temp+binario[i-1];
    temp = temp+binario[i];
    temp = temp+binario[i+1];
    //cout<<temp<<endl;
    for(int j=0; j<8;j++)
    {
        if(wolframe[j]==temp)
        {
            if(regla[j]=='1')
            {
               nueva = nueva+"1";
               break;
            }
            else
            {
                nueva = nueva+"0";
                break;
            }
         }
    }
    temp="";
}
nueva = nueva+"0";
if(guardar==true)
{
    myfile <<nueva<<"\n";
}
else
{
  imprimir_automata(nueva);
}

binario = nueva;
nueva ="";
nueva ="0";
k++;
}
myfile.close();
guardar=false;
}





string Datos::convert_binary(int entrada)
{
  string binario;
  int divisor = 2;
  int resto;
  while(entrada >= divisor)
  {
     resto=entrada%2;
     if(resto == 1)
     {
         binario="1"+binario;
     }
     else
     {
        binario ="0"+binario;
     }
     entrada =entrada/divisor;
  }

  if(entrada = 1)
  {
      binario= "1"+binario;
  }
  else
  {
      binario = "0"+binario;
  }
  return binario;
}


void Datos::imprimir_automata(string generacion)
{

    for(int i =0; i<generacion.length(); i++)
    {
        if(generacion[i]=='1')
        {
            bloque = new QWidget;
            bloque->setGeometry(ejex,ejey,ancho_bloque,alto_bloque);
            bloque->setStyleSheet("background-color:#000000;");
            bloque->setParent(mostrardatos);
            bloque->show();
            ejex = ejex + ancho_bloque;
        }
        else
        {
            ejex = ejex + ancho_bloque;
        }

    }
    ejey = ejey+alto_bloque;
    ejex = 0;
}


void Datos::guardarkey()
{
    guardar=true;
    obtener_datos();
}



















