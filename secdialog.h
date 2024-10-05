#ifndef SECDIALOG_H
#define SECDIALOG_H
#include<client.h>
#include<salle.h>

#include <QDialog>
#include<salle.h>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>



namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = nullptr);
    void setCurrentPage(int index); // Declaration of the function

    ~SecDialog();

private slots:
    void on_pushButton_144_clicked();


    void on_pushButton_145_clicked();

    void on_pushButton_146_clicked();

    void on_pushButton_84_clicked();

    void on_pushButton_85_clicked();

    void on_pushButton_86_clicked();

    void on_pushButton_87_clicked();

    void on_pushButton_93_clicked();

    void on_pushButton_88_clicked();

    void on_pushButton_147_clicked();

    void on_pushButton_150_clicked();

    void on_pushButton_153_clicked();

    void on_pushButton_156_clicked();

    void on_pushButton_159_clicked();
    void on_pushButton_148_clicked();

    void on_pushButton_149_clicked();

    void on_pushButton_151_clicked();

    void on_pushButton_152_clicked();

    void on_pushButton_154_clicked();

    void on_pushButton_155_clicked();

    void on_pushButton_157_clicked();

    void on_pushButton_158_clicked();

    void on_pushButton_160_clicked();
    void on_pushButton_161_clicked();


    void on_pushButton_97_clicked();

    void on_pushButton_98_clicked();

    void on_pushButton_92_clicked();

    void on_pushButton_95_clicked();

    void on_pushButton_90_clicked();

    void on_pushButton_89_clicked();

    void on_pushButton_142_clicked();

    void on_pushButton_143_clicked();

    void on_pushButton_138_clicked();

    void on_pushButton_140_clicked();

    void on_pushButton_136_clicked();

    void on_pushButton_135_clicked();

    void on_pushButton_134_clicked();

    void on_pushButton_133_clicked();

    void on_pushButton_129_clicked();

    void on_pushButton_131_clicked();

    void on_pushButton_127_clicked();

    void on_pushButton_126_clicked();

    void on_pushButton_124_clicked();

    void on_pushButton_125_clicked();

    void on_pushButton_120_clicked();

    void on_pushButton_122_clicked();

    void on_pushButton_117_clicked();

    void on_pushButton_118_clicked();

    void on_pushButton_115_clicked();

    void on_pushButton_116_clicked();

    void on_pushButton_111_clicked();

    void on_pushButton_113_clicked();

    void on_pushButton_109_clicked();

    void on_pushButton_108_clicked();

    void on_pushButton_106_clicked();

    void on_pushButton_107_clicked();

    void on_pushButton_102_clicked();

    void on_pushButton_104_clicked();

    void on_pushButton_100_clicked();

    void on_pushButton_99_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();
    void on_pushButton_modifier_clicked();
    //void on_pushButton_up_clicked();
void on_pushButton_exportClient_clicked();
void on_pushButton_trier_client_clicked();
void on_pushButton_chercher_client_clicked();
void on_pushButton_chatbot_clicked();
void on_loadImageButton_clicked();
void on_pushButton_selectImage_clicked();
void on_pushButton_selectImage_up_clicked();

void on_ajouter_salle_clicked();

void on_pushButton_modifsalle_2_clicked();

void on_modifiersalle_clicked();

void on_pushButton_up_clicked();

private:
    Ui::SecDialog *ui;
Client client;
Salle salles;

QByteArray m_imageData;  // Private member to store image data
QByteArray mCurrentImageData;  // Private member to store image data

};

#endif // SECDIALOG_H
