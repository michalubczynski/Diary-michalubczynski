#ifndef DANE_H
#define DANE_H
#include <QList>
#include <QFont>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QImage>
#include "wpisy.h"
#include "uslugi.h"

class uslugi;

class dane : public QObject
{
    Q_OBJECT
public:

    explicit dane(QObject *parent = nullptr,uslugi *us=nullptr);
    ~dane();
    void wpisz(wpisy& instancja);
    void sortuj(QList <wpisy>&x);
    void wczytaj(QString sciezka);
    void zapisz();
    void usun();
    QList<wpisy> getPamietnik();
    void zapiszcopy();
private:
    QFile pliki;
    QList <wpisy>lista;
    uslugi *us=nullptr;

};

#endif // DANE_H
