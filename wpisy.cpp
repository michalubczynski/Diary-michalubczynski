#include "wpisy.h"

wpisy::wpisy(){
    setText("");
}

void wpisy::setFontColor(int id){
    if(id==0){
       kolor=Qt::red;
    }
    if(id==1){
       kolor=Qt::green;
    }
   if(id==2){
       kolor=Qt::blue;
   }

}

void wpisy::setFontStylebyID(int id_font)
{
    if(id_font==0){
    new_Font = QFont("Times New Roman",12,QFont::Normal,false);
    }
    if(id_font==1){
    new_Font = QFont("Times New Roman",12,QFont::Normal,true);
    }
    if(id_font==2){
    new_Font = QFont("Times New Roman",12,QFont::Bold,false);
    }
}

void wpisy::setColor(QColor m_color){
    kolor=m_color;
}

bool wpisy::operator==(wpisy &instacja){

    return this->getDate()==instacja.getDate();
}

bool wpisy::operator<(wpisy &instacja){

    return this->getDate()>instacja.getDate();
}
