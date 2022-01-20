#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QKeyEvent>
#include <QMouseEvent>
#include <QMainWindow>
#include <QTextEdit>
#include <QFont>
#include <QFile>
#include <QTextStream>
#include <QImage>
#include "uslugi.h"
#include "edycyjne.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class uslugi;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr,uslugi *us=nullptr);
    ~MainWindow();

    void wyswietl(int pos);

private slots:

    void keyPressEvent(QKeyEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

    void on_pushButtonNew_clicked();
    void on_pushButton_Import_clicked();
    void on_pushButton_eksport_clicked();
    void on_pushButton_delete_clicked();

    void on_pushButtonNext_clicked();

    void on_pushButtonPrev_clicked();

private:

    Ui::MainWindow *ui=nullptr;
    uslugi *us=nullptr;
};
#endif // MAINWINDOW_H
