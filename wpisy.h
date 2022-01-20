#ifndef WPISY_H
#define WPISY_H
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QList>
#include <QDate>
#include <QImage>
#include <QColorDialog>
#include <QFileDialog>
#include <QFont>
#include <QStringList>
class wpisy{

    QString tekst, font, IMG, colorName;
    QFont new_Font;
    QDateTime date;
    QColor kolor;
public:
    wpisy();

    void setText(QString m_tekst){tekst=m_tekst;}
    void setdate(QDateTime m_date){date=m_date;}
    void setFontColor(int id_color);
    void setFontStylebyID(int id_font);
     void setFontStyle(QString m_font){font=m_font;}
     void setIMG(QString m_path){IMG=m_path;}
     void setColor(QColor m_color);
     void setNewFont(QFont m_font){new_Font=m_font;}

     QString getTekst(){return tekst;}
     QDateTime getDate(){return date;}
     QColor getFontColor(){return kolor;}
     QString getFontStyle(){return font;}
     QString getIMG(){return IMG;}
     QString getColorName(){return colorName;}
     QFont getNewFont(){return new_Font;}


      bool operator==(wpisy &instacja);
      bool operator<(wpisy &instacja);
 };

#endif // WPISY_H
