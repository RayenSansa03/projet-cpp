#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secdialog.h"
#include "arduino.h"
#include "salle.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    float getTempMaxFromDB(int salleId);

private slots:
    void on_pushButton_5_clicked();
    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_readTemperature_clicked();  // Make sure this line is present

    //void on_pushButton_compare_clicked() ;


private:
    Ui::MainWindow *ui;
    SecDialog *secDialog;
    QByteArray data;
    Arduino A; // objet temporaire
    // variable contenant les données reçues
    void updateTemperatureDisplay();

};
#endif // MAINWINDOW_H
