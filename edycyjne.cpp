#include "edycyjne.h"
#include "ui_edycyjne.h"

Edycyjne::Edycyjne(QWidget *parent,uslugi *us)
    : QDialog(parent),
    ui(new Ui::Edycyjne),
    us(us){

    us->setEdycyjne(this);
    ui->setupUi(this);
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

Edycyjne::~Edycyjne()
{
    delete ui;
}

void Edycyjne::on_pushButtonIMG_clicked()
{
            QString filename=QFileDialog::getOpenFileName(this,"Open Image File","","*.png *.bmp *.jpg");
            wpis.setIMG(filename);
}

void Edycyjne::on_buttonBox_accepted()
{
           wpis.setText(ui->textEdit->toPlainText());
           wpis.setFontColor(ui->fontColor->currentIndex());
           wpis.setFontStyle(ui->fontStyle->currentText());
           wpis.setdate(ui->dateTimeEdit->dateTime());
            wpis.setFontStylebyID(ui->fontStyle->currentIndex());
            us->dodajWpis(wpis);
            this->close();
}

