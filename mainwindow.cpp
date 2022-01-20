#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent,uslugi *us)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      us(us){
    us->setGlowne(this);
    ui->setupUi(this);
    setFocusPolicy(Qt::ClickFocus);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    us->arrows(event);
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    us->wheelmouse(event);
}

void MainWindow::wyswietl(int pos)
{
    QImage IMG;
    QSize dims = ui->label->size();
    QList<wpisy> lista = us->pobierzWpisy();
    ui->textEdit_starsze->clear();
    ui->textEdit_aktualne->clear();
    ui->textEdit_poprzednie->clear();
    if(us->getPozycja()-1<0){
        ui->textEdit_starsze->setTextColor(Qt::black);
        ui->textEdit_starsze->setFontWeight(QFont::Normal);
        ui->textEdit_starsze->append("Brak poprzedzajacych wpisow");
    }
    else{
        ui->textEdit_starsze->setTextColor(lista[pos - 1].getFontColor());
        ui->textEdit_starsze->setCurrentFont(lista[pos-1].getNewFont());
        ui->textEdit_starsze->append("KIEDY: "+lista[pos - 1].getDate().toString() );
        ui->textEdit_starsze->append("Tresc wpisu: "+lista[pos-1].getTekst());
    }
    //****************

    ui->textEdit_aktualne->setTextColor(lista[pos].getFontColor());
    ui->textEdit_aktualne->setCurrentFont(lista[pos].getNewFont());
    ui->textEdit_aktualne->append("KIEDY: "+lista[pos].getDate().toString() );
    ui->textEdit_aktualne->append("Tresc wpisu: "+lista[pos].getTekst());
    if(lista[pos].getIMG()!=""){
     IMG = QImage(lista[pos].getIMG());
     ui->label->setPixmap(QPixmap::fromImage(IMG.scaled(dims)));
    }
    else{
        ui->label->setText("NO IMG");
    }
    //****************
    if(us->getPozycja()+1>=lista.size()){
        ui->textEdit_poprzednie->setTextColor(Qt::black);
        ui->textEdit_poprzednie->setFontWeight(QFont::Normal);
        ui->textEdit_poprzednie->append("Brak pozniejszych wpisow");
    }
    else{
        ui->textEdit_poprzednie->setTextColor(lista[pos+1 ].getFontColor());
        ui->textEdit_poprzednie->setCurrentFont(lista[pos+1].getNewFont());
        ui->textEdit_poprzednie->append("KIEDY: "+lista[pos+1].getDate().toString() );
        ui->textEdit_poprzednie->append("Tresc wpisu: "+lista[pos+1].getTekst());
    }
}

void MainWindow::on_pushButtonNew_clicked(){
    us->otworzEdycyjne();
}


void MainWindow::on_pushButton_Import_clicked(){
        QString path = QFileDialog::getOpenFileName(this,"Open file...","","*.txt");
        us->Import(path);
}


void MainWindow::on_pushButton_eksport_clicked(){
        us->Eksport();
}


void MainWindow::on_pushButton_delete_clicked(){
        us->usun();
}


void MainWindow::on_pushButtonNext_clicked()
{
    us->nastepny();
}


void MainWindow::on_pushButtonPrev_clicked()
{
    us->poprzedni();
}

