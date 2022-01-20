#include "uslugi.h"

uslugi::uslugi(QObject *parent) : QObject(parent){}

uslugi::~uslugi()
{
}

void uslugi::otworzEdycyjne(){
    edycyjne = new Edycyjne(Glowne,this);
    edycyjne->exec();
    delete edycyjne;
}

void uslugi::dodajWpis(wpisy &instacja){
    dana->wpisz(instacja);
    wypisz();
}

void uslugi::Import(QString sciezka){
    dana->wczytaj(sciezka);
    wypisz();
}

void uslugi::Eksport(){
    dana->zapisz();
}

void uslugi::wypisz(){
    Glowne->wyswietl(curr_wspom);
}

void uslugi::saveRecoverCopy()
{
    dana->zapiszcopy();
}

void uslugi::usun(){
    dana->usun();
}
QList<wpisy> uslugi::pobierzWpisy(){
    return dana->getPamietnik();
}

void uslugi::nastepny(){
    if(curr_wspom >= 0 && curr_wspom < pobierzWpisy().length()-1){
    curr_wspom++;
    Glowne->wyswietl(curr_wspom);
    }
}

void uslugi::poprzedni(){
    if(curr_wspom > 0 && curr_wspom <= pobierzWpisy().length()-1){
    curr_wspom--;
    Glowne->wyswietl(curr_wspom);
    }
}

void uslugi::arrows(QKeyEvent *event){
    int m_event = event->key();

    switch(m_event){
    case Qt::Key_Down:
            nastepny();
            break;
    case Qt::Key_Up:
            poprzedni();
            break;
    }
}

void uslugi::wheelmouse(QWheelEvent *event){
    if(event->angleDelta().y() < 0){
        poprzedni();
    }
    if(event->angleDelta().y() > 0){
        nastepny();
    }
}

void uslugi::setPozycja(int pos){
    curr_wspom = pos;
}



