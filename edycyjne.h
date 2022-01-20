#ifndef EDYCYJNE_H
#define EDYCYJNE_H
#include <QDialog>
#include <QFileDialog>
#include "wpisy.h"
#include "uslugi.h"

namespace Ui {
class Edycyjne;
}
class uslugi;
class Edycyjne : public QDialog
{
    Q_OBJECT

public:
    explicit Edycyjne(QWidget *parent=nullptr,uslugi *us=nullptr);
    ~Edycyjne();

private slots:
    void on_pushButtonIMG_clicked();
    void on_buttonBox_accepted();

private:
    wpisy wpis;
    Ui::Edycyjne *ui = nullptr;
    uslugi *us = nullptr;
};


#endif // EDYCYJNE_H
