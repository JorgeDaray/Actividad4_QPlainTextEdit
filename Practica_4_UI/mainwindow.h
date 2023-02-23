#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <string>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_guardar_Final_clicked();

    void on_pushButton_guardar_Inicio_clicked();

    void on_pushButton_Imprimir_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};


class Neurona
{
public:
    Neurona();
    void establecer_id(int);
    int obtener_id() const;
    void establecer_voltaje(int);
    int obtener_voltaje() const;
    void establecer_posx(int);
    int obtener_posx() const;
    void establecer_posy(int);
    int obtener_posy() const;
    void establecer_red(int);
    int obtener_red() const;
    void establecer_green(int);
    int obtener_green() const;
    void establecer_blue(int);
    int obtener_blue() const;
    ~Neurona();
private:
    int id;
    int voltaje;
    int posicion_x;
    int posicion_y;
    int red;
    int green;
    int blue;
};

class Lista
{
public:
    Lista();
    Neurona Datos; // tipo objeto neurona
    Neurona copia; //tipo objeto datos para imprimir
    void obtener_insert_inicio(Neurona);
    void obtener_insert_final(Neurona);
    string obtener_print();
    string mostrar();
    ~Lista();
private:
    Lista *first;//apuntador al principio de la lista
    Lista *last;//apuntador al final de la lista
    Lista *next;//apuntador a siguiente
    Lista *before;//apuntador a anterior
    /*void Insertar_inicio(Neurona);
    void Insertar_final(Neurona);
    void print();*/
};

#endif // MAINWINDOW_H
