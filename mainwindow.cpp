#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<client.h>
#include <QApplication>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include "arduino.h"        // Assurez-vous que ce chemin est correct pour votre classe Arduino

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->pushButtonCompare, &QPushButton::clicked, this, &MainWindow::on_pushButton_compare_clicked);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_5_clicked()
{
    hide();
    secDialog = new SecDialog(this);
    secDialog->show();
    secDialog->setCurrentPage(20); // Assuming page_5 is at index 4

}

void MainWindow::on_pushButton_9_clicked()
{
    hide();
    secDialog = new SecDialog(this);
    secDialog->show();
    secDialog->setCurrentPage(19); // Assuming page_5 is at index 4

}
void MainWindow::on_pushButton_8_clicked()
{
    hide();
    secDialog = new SecDialog(this);
    secDialog->show();
    secDialog->setCurrentPage(21); // Assuming page_5 is at index 4

}
void MainWindow::on_pushButton_10_clicked()
{
    hide();
    secDialog = new SecDialog(this);
    secDialog->show();
    secDialog->setCurrentPage(18); // Assuming page_5 is at index 4

}
void MainWindow::on_pushButton_11_clicked()
{
    hide();
    secDialog = new SecDialog(this);
    secDialog->show();
    secDialog->setCurrentPage(23); // Assuming page_5 is at index 4

}
void MainWindow::on_pushButton_12_clicked()
{
    hide();
    secDialog = new SecDialog(this);
    secDialog->show();
    secDialog->setCurrentPage(22); // Assuming page_5 is at index 4

}


float MainWindow::getTempMaxFromDB(int salleId)
{
    QSqlQuery query;
    query.prepare("SELECT temp_max FROM salle WHERE id_salle = :id");
    query.bindValue(":id", salleId);

    if (!query.exec()) {
        qDebug() << "Failed to query database:" << query.lastError();
        return -1; // return an error value
    }

    if (query.next()) {
        return query.value(0).toFloat();
    } else {
        qDebug() << "No record found for salle ID:" << salleId;
        return -1; // return an error value
    }
}

/*void MainWindow::on_pushButton_compare_clicked() {
    int salleId = ui->lineEditSalleId->text().toInt();
    float tempMax = getTempMaxFromDB(salleId);
    float currentTemp = A.readTemperature(); // Utilisez votre objet Arduino pour lire la température


    if (tempMax == -1) {
        ui->labelResult->setText("ID de la salle non trouvé ou erreur de base de données.");
    } else if (currentTemp > tempMax) {
        ui->labelResult->setText("La température est supérieure à la limite. Il faut démarrer le ventilateur.");
    } else {
        ui->labelResult->setText("La température est normale.");
    }
}*/

void MainWindow::on_pushButton_readTemperature_clicked() {
    int salleId = ui->lineEditSalleId->text().toInt();
    float maxTemp = getTempMaxFromDB(salleId);
    float currentTemperature = A.readTemperature();

    qDebug() << "Max Temp from DB:" << maxTemp << "Current Temp:" << currentTemperature;

    if (maxTemp == -1) {
        ui->labelResult->setText("ID de la salle non trouvé ou erreur de base de données.");
    } else if (std::isnan(currentTemperature)) {
        ui->labelResult->setText("Erreur de lecture de la température.");
    } else if (currentTemperature > maxTemp) {
        ui->labelResult->setText("La température est supérieure à la température maximale. Il faut démarrer le ventilateur.");
    } else {
        ui->labelResult->setText("La température est dans les limites normales.");
    }
}
