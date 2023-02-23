#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Neurona datos;//objeto tipo neurona
Lista mi_lista;//objeto tipo lista

//Variables globales de neurona
QString nombre_ID;
QString nombre_voltaje;
QString nombre_posicion_x;
QString nombre_posicion_y;
QString nombre_red;
QString nombre_green;
QString nombre_blue;

//+ QString::number( myInt ); // CORRECT

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Neurona::Neurona()
{

}//constructor

void Neurona::establecer_id(int valor_id)
{
    id = valor_id;
}
int Neurona::obtener_id()const
{
    return id;
}

void Neurona::establecer_voltaje(int valor_voltaje)
{
    voltaje = valor_voltaje;
}
int Neurona::obtener_voltaje()const
{
    return voltaje;
}

void Neurona::establecer_posx(int valor_posx)
{
    posicion_x = valor_posx;
}
int Neurona::obtener_posx()const
{
    return posicion_x;
}

void Neurona::establecer_posy(int valor_posy)
{
    posicion_y = valor_posy;
}
int Neurona::obtener_posy()const
{
    return posicion_y;
}

void Neurona::establecer_red(int valor_red)
{
    red = valor_red;
}
int Neurona::obtener_red()const
{
    return red;
}

void Neurona::establecer_green(int valor_green)
{
    green = valor_green;
}
int Neurona::obtener_green()const
{
    return green;
}

void Neurona::establecer_blue(int valor_blue)
{
    blue = valor_blue;
}
int Neurona::obtener_blue()const
{
    return blue;
}

Neurona::~Neurona()
{

}//dtor

Lista::Lista()
{
}//ctor

void Lista::obtener_insert_inicio(Neurona info)
{
    Lista *temp = new Lista();
    temp ->Datos = info;
    if(first == nullptr)
    {
        first = temp;
        temp -> before = nullptr;
        first ->next = nullptr;
        last = temp;
    }
    else
    {
        temp ->before = nullptr;
        temp ->next = first;
        first->before = temp;
        first = temp;
    }
}

void Lista::obtener_insert_final(Neurona info)
{
    Lista *temp = new Lista();
    temp ->Datos = info;
    if(last == NULL)
    {
        temp->before = NULL;
        first = temp;
        first ->next = NULL;
        last = temp;
    }
    else
    {
        last -> next = temp;
        temp-> before = NULL;
        temp -> next = NULL;
        last = temp;
    }
}

string Lista::obtener_print()
{
    Lista *temp;
    temp = first;
    string s;
    ostringstream buffer;
    if(first != nullptr)
    {
        int i = 0; //contador de posicion
        while (temp != nullptr)
        {
            buffer <<endl<<"posicion: "<<i<<endl
             <<"id: "<<temp->Datos.obtener_id()<<endl
             <<"voltaje: "<<temp->Datos.obtener_voltaje()<<endl
             <<"posicion y: "<<temp->Datos.obtener_posy()<<endl
             <<"posicion x: "<<temp->Datos.obtener_posx()<<endl
             <<"red: "<<temp->Datos.obtener_red()<<endl
             <<"green: "<<temp->Datos.obtener_green()<<endl
             <<"blue: "<<temp->Datos.obtener_blue()<<endl;

            temp = temp ->next;
            i++;
            s = buffer.str();
        }
        return s;
    }
    else
    {
        cout << "La lista esta vacia"<<endl;
    }
}

//se hace el getter de la lista privada
/*void Lista::obtener_insert_inicio(Neurona)
{
    return Insertar_inicio(Datos);
}
void Lista::obtener_insert_final(Neurona)
{
    return Insertar_final(Datos);
}
void Lista::obtener_print()
{
    return print();
}*/

Lista::~Lista()
{
}//dtor


void MainWindow::on_pushButton_guardar_Final_clicked()
{
    cout << "Guardado"<<endl;
    nombre_ID = ui ->leID ->text();
    nombre_voltaje = ui ->levoltaje -> text();
    nombre_posicion_x = ui ->leX ->text();
    nombre_posicion_y = ui ->leY ->text();
    nombre_red = ui ->leRed ->text();
    nombre_green = ui ->leGreen ->text();
    nombre_blue = ui ->leBlue ->text();
    datos.establecer_id(nombre_ID.toInt());
    datos.establecer_voltaje(nombre_voltaje.toInt());
    datos.establecer_posx(nombre_posicion_x.toInt());
    datos.establecer_posy(nombre_posicion_y.toInt());
    datos.establecer_red(nombre_red.toInt());
    datos.establecer_green(nombre_green.toInt());
    datos.establecer_blue(nombre_blue.toInt());
    mi_lista.obtener_insert_final(datos);
    ui ->leID->clear();
    ui ->levoltaje->clear();
    ui ->leX->clear();
    ui ->leY->clear();
    ui ->leRed->clear();
    ui ->leGreen->clear();
    ui ->leBlue->clear();
}




void MainWindow::on_pushButton_guardar_Inicio_clicked()
{
    cout << "Guardado"<<endl;
    nombre_ID = ui ->leID ->text();
    nombre_voltaje = ui ->levoltaje -> text();
    nombre_posicion_x = ui ->leX ->text();
    nombre_posicion_y = ui ->leY ->text();
    nombre_red = ui ->leRed ->text();
    nombre_green = ui ->leGreen ->text();
    nombre_blue = ui ->leBlue ->text();
    datos.establecer_id(nombre_ID.toInt());
    datos.establecer_voltaje(nombre_voltaje.toInt());
    datos.establecer_posx(nombre_posicion_x.toInt());
    datos.establecer_posy(nombre_posicion_y.toInt());
    datos.establecer_red(nombre_red.toInt());
    datos.establecer_green(nombre_green.toInt());
    datos.establecer_blue(nombre_blue.toInt());
    mi_lista.obtener_insert_inicio(datos);
    ui ->leID->clear();
    ui ->levoltaje->clear();
    ui ->leX->clear();
    ui ->leY->clear();
    ui ->leRed->clear();
    ui ->leGreen->clear();
    ui ->leBlue->clear();
}

void MainWindow::on_pushButton_Imprimir_clicked()
{
    mi_lista.obtener_print();
    string s = mi_lista.obtener_print();
    ui->plainTextEdit_imprimir->setPlainText(QString::fromStdString (s));
}


void MainWindow::on_pushButton_clicked()
{
    ui ->plainTextEdit_imprimir ->clear();
}

