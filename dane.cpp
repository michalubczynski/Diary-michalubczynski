#include "dane.h"

dane::dane(QObject *parent,uslugi *us)
    : QObject(parent),
    us(us){
    QFile txt("Pamietnik.txt");
    if (txt.size()!=0){
            wczytaj("Pamietnik.txt");
    }
    txt.close();
    us->setDane(this);
    us->wypisz();

}

dane::~dane()
{
    zapisz();
    zapiszcopy();
}

void dane::wpisz(wpisy &wpis){
    bool ishere{0};
   for (wpisy& temp : lista){
     if(temp==wpis){
       ishere=1;
     }
   }
    if(ishere==0){
    lista.push_back(wpis);
}
   sortuj(lista);

}

void dane::sortuj(QList<wpisy> &list){
    std::sort(list.begin(), list.end());
}

void dane::wczytaj(QString path){
    QFile txt(path);
           if (!txt.open(QIODevice::ReadOnly | QIODevice::Text))return;
           QTextStream stream(&txt);
           QString text, style, date, color, m_path;
           while (!stream.atEnd()) {
                text = stream.readLine();
                style =stream.readLine();
                date = stream.readLine();
                color = stream.readLine();
                m_path= stream.readLine();

                bool ok;
                QString ColorHex = color.remove('#');
                int ColorInt = ColorHex.toInt(&ok,16);
                QFont font;
                font.setPixelSize(16);
                font.fromString(style);
                wpisy wpis;
                wpis.setText(text);
                wpis.setdate(QDateTime::fromString(date));
                wpis.setNewFont(font);
                wpis.setColor(ColorInt);
                wpis.setIMG(m_path);
                wpisz(wpis);
           }
      txt.close();
      pliki.close();
}

void dane::zapisz(){
    QFile txt("Pamietnik.txt");
    txt.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&txt);
    for(int i=0; i<lista.size();i++) {
           out<<lista[i].getTekst()+"\n";            //  \n is for new line.
           out<<lista[i].getNewFont().toString()+"\n";
           out<<lista[i].getDate().toString()+"\n";
           out<<lista[i].getFontColor().name()+"\n";
           out<<lista[i].getIMG()+"\n";
       }
    txt.close();

}
void dane::zapiszcopy(){
    QString Path;
    QFile file("Pamietnik.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    Path = "Recovery.txt";
    QFile RecoveryFile(Path);
    RecoveryFile.open( QIODevice::WriteOnly| QIODevice::Text );
      QTextStream stream(&file);
       QTextStream out(&RecoveryFile);
       while (!stream.atEnd()) {
           out<<stream.readLine()+"\n";
       }
       RecoveryFile.close();
       file.close();

}

void dane::usun(){

    if(lista.size()>1 && us->getPozycja()<=lista.length()){
        lista.removeAt(us->getPozycja());
        std::sort(lista.begin(),lista.end());
        if(us->getPozycja()>0){
            us->setPozycja(us->getPozycja()-1);
        }
    }
    else if(lista.empty()){
        us->setPozycja(0);

    }
    if(!lista.empty())us->wypisz();
}

QList<wpisy> dane::getPamietnik(){
    return lista;
}


