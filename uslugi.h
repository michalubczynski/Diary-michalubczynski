#ifndef USLUGI_H
#define USLUGI_H
#include <QObject>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QList>
#include "wpisy.h"
#include "mainwindow.h"
#include "edycyjne.h"
#include "dane.h"

class dane;
class MainWindow;
class Edycyjne;

class uslugi : public QObject
{
    Q_OBJECT
public:
    explicit uslugi(QObject *parent = nullptr);
    ~uslugi();
    void setGlowne(MainWindow *ui = nullptr) {Glowne = ui;};
    void setEdycyjne(Edycyjne *ui = nullptr) {edycyjne = ui;};
    void setDane(dane *ui = nullptr){dana = ui;};
    void otworzEdycyjne();
    void dodajWpis(wpisy &instacja);
    void Import(QString sciezka);
    void Eksport();
    void wypisz();
    void saveRecoverCopy();


    void usun();
    void zamknij();
    void nastepny();
    void poprzedni();
    void arrows(QKeyEvent *event);
    void wheelmouse(QWheelEvent *event);


    QList<wpisy> pobierzWpisy();
    void setPozycja(int x);
    int getPozycja(){return curr_wspom;}

private:
   MainWindow *Glowne = nullptr;
   Edycyjne *edycyjne = nullptr;
   dane *dana=nullptr;
   int curr_wspom = 0;
};


#endif // USLUGI_H
