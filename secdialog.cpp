#include "secdialog.h"
#include "ui_secdialog.h"
#include <client.h>
#include <QApplication>
#include <QMessageBox>
#include <QPrinter>
#include <QPainter>
#include <QDebug>
#include "smtp.h"
#include <QRegularExpression>
#include <QtCharts>
#include <QPrinter>
#include <QChart>
#include <QChartView>
#include <QDesktopServices>
#include <QUrl>
#include <QPixmap>
#include <QImage>
#include <QFileDialog>
#include <QColor>
#include <QDate>
SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{

    ui->setupUi(this);
    ui->tableView->setModel(client.afficher());
    //ui->tablesalle->setModel(salles.afficher());

    //ui->tableView->horizontalHeader()->setSectionResizeMode(8, QHeaderView::ResizeToContents);
    connect(ui->pushButton_selectImage, &QPushButton::clicked, this, &SecDialog::on_pushButton_selectImage_clicked);

    connect(ui->loadImageButton, &QPushButton::clicked, this, &SecDialog::on_loadImageButton_clicked);

}

void SecDialog::setCurrentPage(int index) {
    ui->stackedWidget->setCurrentIndex(index);

}
SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::on_pushButton_144_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->listeclient);
}


void SecDialog::on_pushButton_145_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ajoutclient);

}

void SecDialog::on_pushButton_146_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->statclient);

}

void SecDialog::on_pushButton_84_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->employe);

}

void SecDialog::on_pushButton_85_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->equipement);

}

void SecDialog::on_pushButton_86_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->projet);

}

void SecDialog::on_pushButton_87_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->client);

}

void SecDialog::on_pushButton_93_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->salle);

}

void SecDialog::on_pushButton_88_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->formation);

}

void SecDialog::on_pushButton_147_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->listeprojet);

}
void SecDialog::on_pushButton_148_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ajoutprojet);

}
void SecDialog::on_pushButton_149_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->statprojet);

}

void SecDialog::on_pushButton_150_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->listeemploye);

}
void SecDialog::on_pushButton_151_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ajoutemploye);

}
void SecDialog::on_pushButton_152_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->statemploye);

}

void SecDialog::on_pushButton_153_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->listeequipement);

}
void SecDialog::on_pushButton_154_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ajoutequipement);

}
void SecDialog::on_pushButton_155_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->statequipement);

}

void SecDialog::on_pushButton_156_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->listeformation);

}
void SecDialog::on_pushButton_157_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ajoutformation);

}
void SecDialog::on_pushButton_158_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->statformation);

}

void SecDialog::on_pushButton_159_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->listesalle);

}
void SecDialog::on_pushButton_160_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ajoutsalle);

}
void SecDialog::on_pushButton_161_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->statsalle);

}

void SecDialog::on_pushButton_97_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ajoutprojet);

}

void SecDialog::on_pushButton_98_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->statprojet);

}

void SecDialog::on_pushButton_92_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->listeprojet);

}

void SecDialog::on_pushButton_95_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->statprojet);

}

void SecDialog::on_pushButton_90_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ajoutprojet);

}

void SecDialog::on_pushButton_89_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->listeprojet);

}

void SecDialog::on_pushButton_142_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ajoutclient);

}

void SecDialog::on_pushButton_143_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->statclient);

    // Récupérer les données de statistiques sur les clients par sexe
    QSqlQuery query;
    query.exec("SELECT email, COUNT(*) FROM Clients GROUP BY email ORDER BY email"); // Sélectionner les clients par sexe

    // Créer un modèle de données pour le sexe
    QBarSeries *series = new QBarSeries();

    while (query.next()) {
        QString email = query.value(0).toString();
        int count = query.value(1).toInt();

        QBarSet *set = new QBarSet(email);
        *set << count; // Ajouter le nombre de clients de chaque sexe
        series->append(set);
    }

    // Créer un graphique
    QChart *chart = new QChart();
    chart->setTitle("Statistiques des clients par adresse");
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Créer des axes
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    QValueAxis *axisY = new QValueAxis();

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    series->attachAxis(axisX);
    series->attachAxis(axisY);

    // Créer une vue graphique pour le graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Ajuster les plages des axes
    axisY->setRange(0, query.size()); // Supposition: ajuster selon le nombre maximum de clients d'un sexe
    axisY->setTickCount(10); // Ajuster selon le besoin

    // Afficher le graphique
    ui->stackedWidget->addWidget(chartView);
    ui->stackedWidget->setCurrentWidget(chartView);
}





void SecDialog::on_pushButton_138_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->listeclient);

}

void SecDialog::on_pushButton_140_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->statclient);

}

void SecDialog::on_pushButton_136_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ajoutclient);

}

void SecDialog::on_pushButton_135_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->listeclient);

}

void SecDialog::on_pushButton_134_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->statsalle);

}

void SecDialog::on_pushButton_133_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ajoutsalle);

}

void SecDialog::on_pushButton_129_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->listesalle);

}

void SecDialog::on_pushButton_131_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->statsalle);

}

void SecDialog::on_pushButton_127_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ajoutsalle);

}

void SecDialog::on_pushButton_126_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->listesalle);

}

void SecDialog::on_pushButton_124_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ajoutemploye);

}

void SecDialog::on_pushButton_125_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->statemploye);

}

void SecDialog::on_pushButton_120_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->listeemploye);

}

void SecDialog::on_pushButton_122_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->statemploye);

}

void SecDialog::on_pushButton_117_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->listeemploye);

}

void SecDialog::on_pushButton_118_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ajoutemploye);

}

void SecDialog::on_pushButton_115_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ajoutequipement);

}

void SecDialog::on_pushButton_116_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->statequipement);

}

void SecDialog::on_pushButton_111_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->listeequipement);

}

void SecDialog::on_pushButton_113_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->statequipement);

}

void SecDialog::on_pushButton_109_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ajoutequipement);

}

void SecDialog::on_pushButton_108_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->listeequipement);

}

void SecDialog::on_pushButton_106_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ajoutformation);

}

void SecDialog::on_pushButton_107_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->statformation);

}

void SecDialog::on_pushButton_102_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->listeformation);

}

void SecDialog::on_pushButton_104_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->statformation);

}

void SecDialog::on_pushButton_100_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ajoutformation);

}

void SecDialog::on_pushButton_99_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->listeformation);

}
void SecDialog::on_pushButton_ajouter_clicked()
{
    QString nom = ui->lineEdit_nom->text().trimmed();
    QString prenom = ui->lineEdit_prenom->text().trimmed();
    // int id = ui->lineEdit_ID->text().toInt(); // Commenté si l'ID n'est pas utilisé ici
    QString sexe = ui->lineEdit_sexe->text().trimmed();
    QString adresse = ui->lineEdit_adresse->text().trimmed();
    QString email = ui->lineEdit_email->text().trimmed();

    QString dateNaissance = ui->dateEdit_DDN->text();
    QString dateInscription = ui->dateEdit_inscrit->text();

   // Contrôles de saisie
    if(nom.isEmpty() || prenom.isEmpty() || sexe.isEmpty() || adresse.isEmpty() )
    {
        QMessageBox::warning(nullptr, tr("Champs manquants"), tr("Veuillez remplir tous les champs."));
        // Arrête l'exécution si des champs requis sont vides
        return;
    }
    if (m_imageData.isEmpty()) {
          QMessageBox::warning(this, tr("Aucune image sélectionnée"), tr("Veuillez sélectionner une image avant de continuer."));
          return;
      }

      // Utilisez m_imageData pour créer l'objet Client
      Client client(0, sexe, nom, prenom, adresse, email, dateNaissance, dateInscription, m_imageData);
    bool test = client.ajouter();

    if (test)
       {
           ui->tableView->setModel(client.afficher());
           QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Ajout effectué \n Click Cancel to exist."));

           // Send Welcome Email
           Smtp* smtp = new Smtp("tassounaassoula@gmail.com", "awhc rtpj ujnd binw", "gmail.example.com", 587);
           connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString))); // Ensure you have a slot to handle the status
           QString subject = "Welcome to Our Service!";
           QString body = "Dear " + nom + ",\n\nWelcome to our service. We're glad to have you with us.\n\nBest,\nThe Team";
           smtp->sendMail("tassounaassoula@gmail.com", email, subject, body);

       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("Not ok"), QObject::tr("Ajout non effectué \n Click Cancel to exist.") );
       }
}


void SecDialog::on_pushButton_supprimer_clicked()
{
    int id = ui->lineEdit_4->text().toInt();
    Client client;
    bool test = client.supprimer(id);

    if (test)
    {
        ui->tableView->setModel(client.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
            QObject::tr("Supprimer effectué \n"
                        "Click Cancel to exist."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not ok"),
            QObject::tr("Suppression non effectué \n"
                        "Click Cancel to exist."), QMessageBox::Cancel);
    }
}
void SecDialog::on_pushButton_modifier_clicked()
{
    // Récupérer l'ID du client depuis l'interface graphique
    int id = ui->lineEdit_10->text().toInt(); // Assume this is the lineEdit for ID input

    // Vérifier si l'ID du client existe dans la base de données
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT NOM, PRENOM, SEXE,EMAIL, ADRESSE,DATE_DE_NAISSANCE, DATE_DINSCRIPTION, IMAGE FROM CLIENTS WHERE ID = :id");
    checkQuery.bindValue(":id", id);


    if (checkQuery.exec() && checkQuery.next()) {
        // L'ID existe, extraire les valeurs de la requête
        QString nom = checkQuery.value(0).toString();
        QString prenom = checkQuery.value(1).toString();
        QString sexe = checkQuery.value(2).toString();
        QString email = checkQuery.value(4).toString();
        QString adresse = checkQuery.value(3).toString();
        QString dateNaissance = checkQuery.value(5).toString();
        QString dateInscription = checkQuery.value(6).toString();
        QByteArray image = checkQuery.value(7).toByteArray();

        QDate dateDeNaissanceDate = QDate::fromString(dateNaissance, "yyyy-MM-dd");
        QDate dateInscriptionDate = QDate::fromString(dateInscription, "yyyy-MM-dd");


        // Mettre à jour les champs de l'interface graphique avec les valeurs précédentes
        ui->lineEdit_sexe_up->setText(sexe);
        ui->lineEdit_nom_up->setText(nom);
        ui->lineEdit_prenom_up->setText(prenom);
        ui->dateEdit_DDN_up->setDate(dateDeNaissanceDate);
        ui->lineEdit_adresse_up->setText(adresse);
        ui->lineEdit_email_up->setText(email);
        ui->dateEdit_inscrit_up->setDate(dateInscriptionDate);

        // Rendre le champ ID en lecture seule pour éviter des modifications
        ui->lineEdit_id_up->setReadOnly(true); // Assumer que c'est le champ pour l'ID

        // Changer vers la page de modification pour un client
        // Assumer que vous avez un widget empilé pour la navigation, et "modifClient" est la page de modification du client
        ui->stackedWidget->setCurrentWidget(ui->modifClient);
    } else {
        // L'ID n'existe pas, afficher un avertissement
        QMessageBox::warning(nullptr, "Erreur", "ID de client non trouvé dans la base de données !");
    }
}
/*void SecDialog::on_pushButton_up_clicked()
{
    int id = ui->lineEdit_10->text().toInt();

    // Récupérer les anciennes valeurs depuis l'interface graphique

    QString anciennom = ui->lineEdit_nom->text();
    QString ancienprenom = ui->lineEdit_prenom->text();
    QString ancienemail = ui->lineEdit_email->text();
    QString ancienadresse = ui->lineEdit_adresse->text();
    QString anciensexe = ui->lineEdit_sexe->text();

    QString anciendateNaissance = ui->dateEdit_DDN->text();
    QString anciendateInscription = ui->dateEdit_inscrit->text();

    // Récupérer les nouvelles valeurs depuis l'interface graphique
     QString nouvnom = ui->lineEdit_nom_up->text();
     QString nouvprenom = ui->lineEdit_prenom_up->text();
     QString nouvemail = ui->lineEdit_email_up->text();
     QString nouvadresse = ui->lineEdit_adresse_up->text();
     QString nouvsexe = ui->lineEdit_sexe_up->text();
QString nouvdateInscription= ui->dateEdit_inscrit_up->text();
QString nouvdateDeNaissanceDate= ui->dateEdit_DDN_up->text();



    // Vérifier s'il y a eu une modification
    if (anciennom != nouvnom || ancienprenom != nouvprenom || ancienemail != nouvemail|| ancienadresse != nouvadresse|| anciensexe != nouvsexe|| anciendateNaissance != nouvdateDeNaissanceDate|| anciendateInscription != nouvdateInscription) {
        // Il y a eu une modification, mettre à jour les détails de la salle dans la base de données
        Client client(id, nouvnom, nouvprenom,nouvsexe,nouvemail, nouvadresse,nouvdateDeNaissanceDate,nouvdateInscription);
        bool modificationReussie = client.modifier(id, nouvnom, nouvprenom,nouvsexe,nouvemail, nouvadresse,nouvdateDeNaissanceDate,nouvdateInscription);

        if (modificationReussie) {
            // Rafraîchir les données affichées (si nécessaire)
            ui->tableView->setModel(client.afficher());

            // Optionnellement, afficher un message de succès ou effectuer d'autres actions
            QMessageBox::information(nullptr, "Succès", "client modifiée avec succès !");

            ui->stackedWidget->setCurrentWidget(ui->modifClient);
        } else {
            // Gérer le cas où la modification de la salle a échoué
            QMessageBox::warning(nullptr, "Erreur", "Erreur lors de la modification de client !");
        }
    } else {
        // Aucune modification n'a été apportée
        QMessageBox::critical(nullptr, "Information", "Aucune modification n'a été apportée.");
    }
}*/
void SecDialog::on_pushButton_exportClient_clicked()
{
    // Récupérer l'ID de l'équipement à exporter
    int id = ui->lineEdit_search_cl->text().toInt();

    // Récupérer les informations de l'équipement depuis la base de données
    QSqlQuery query;
    query.prepare("SELECT  nom, prenom, sexe, email, adresse, date_de_naissance, date_dinscription FROM CLIENTS WHERE id = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération des informations de l'équipement pour l'exportation.";
        return;
    }

    if (!query.next()) {
        qDebug() << "Aucun équipement trouvé avec l'ID spécifié.";
        return;
    }
    QString nom = query.value(0).toString();
    QString prenom = query.value(1).toString();
    QString email = query.value(3).toString();

    QString sexe = query.value(2).toString();
    QString adresse = query.value(4).toString();
    QString dateNaissance = query.value(5).toString();
       QString dateInscription = query.value(6).toString();
    // Définir le nom du fichier PDF
    QString fileName = "C:/Users/rayen/OneDrive/Documents/GestionProjet1/client_info_" + QString::number(id) + ".pdf";

    // Créer le périphérique d'impression
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    // Créer un painter associé au périphérique d'impression
    QPainter painter;
    painter.begin(&printer);

    // Dessiner les informations de l'équipement sur le painter
    painter.drawText(100, 100, "sexe: " + sexe);
    painter.drawText(100, 120, "nom: " + nom);
    painter.drawText(100, 140, "prenom: " + prenom);
    painter.drawText(100, 160, "adresse: " + adresse);
    painter.drawText(100, 180, "email: " + email);
    painter.drawText(100, 200, "dateNaissance: " + dateNaissance);
    painter.drawText(100, 220, "dateInscription: " + dateInscription);


    // Fin du dessin
    painter.end();

    qDebug() << "Informations de l'équipement exportées avec succès vers le fichier PDF: " << fileName;
}
/*void SecDialog::on_pushButton_trier_client_clicked()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID, nom, prenom, sexe, adresse, email, date_de_naissance, date_dinscription FROM clients ORDER BY date_dinscription DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date de naissance"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Date d'inscription"));
    // Mettre à jour le modèle de la vue
    ui->tableView->setModel(model);
}*/

/*void SecDialog::on_pushButton_chercher_client_clicked()
{
    // Récupérer le nom de l'équipement à rechercher
    QString nom = ui->lineEdit_search_cl->text();

    // Préparer la requête SQL avec une clause WHERE pour rechercher par nom
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT sexe, nom, prenom, adresse, email, date_de_naissance,date_dinscription FROM clients WHERE nom LIKE :nom");
    query.bindValue(":nom", "%" + nom + "%"); // Utilisation de LIKE pour trouver les correspondances partielles
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête de recherche.";
        return;
    }

    // Mettre à jour le modèle de la vue avec les résultats de la recherche
    model->setQuery(query);
    model->setQuery("SELECT ID, sexe, nom, prenom, adresse, email, date_de_naissance, date_dinscription FROM clients");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date de naissance"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Date d'inscription"));

    // Mettre à jour le modèle de la vue
    ui->tableView->setModel(model);
}*/



void SecDialog::on_pushButton_chatbot_clicked()
{
    // Chemin absolu vers le fichier chatbot.html sur votre bureau
    QString filePath = "file:///C:/Users/rayen/OneDrive/Bureau/chatbot.html";

    // Convertir le chemin du fichier en un objet URL
    QUrl url = QUrl::fromLocalFile(filePath);

    // Ouvrir le fichier avec l'application par défaut, typiquement un navigateur web
    QDesktopServices::openUrl(url);
}
void SecDialog::on_loadImageButton_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    if (fileName.isEmpty())
        return;

    QImage image(fileName);

    // Display original image
    ui->originalImageLabel->setPixmap(QPixmap::fromImage(image).scaled(ui->originalImageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // Apply contrast adjustment and convert to high-contrast black and white
    QImage scannedImage = image.convertToFormat(QImage::Format_RGB32);
    int contrastFactor = 255;
    for (int y = 0; y < scannedImage.height(); ++y) {
        for (int x = 0; x < scannedImage.width(); ++x) {
            QRgb pixel = scannedImage.pixel(x, y);
            int gray = qGray(pixel);
            if (gray < 128) gray = 0;
            else gray = 255;
            int contrastedGray = ((gray - 128) * contrastFactor / 255) + 128;
            contrastedGray = qBound(0, contrastedGray, 255);
            scannedImage.setPixel(x, y, qRgb(contrastedGray, contrastedGray, contrastedGray));
        }
    }

    // Display "scanned" image
    ui->scannedImageLabel->setPixmap(QPixmap::fromImage(scannedImage).scaled(ui->scannedImageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    int borderHeight = 50;

    // 2. Créer une nouvelle image avec la hauteur supplémentaire pour la bordure
    QImage borderedImage(scannedImage.width(), scannedImage.height() + borderHeight, QImage::Format_RGB32);

    borderedImage.fill(Qt::black);

    QPainter painter(&borderedImage);
    painter.drawImage(0, 0, scannedImage);
    painter.end();

    // Utiliser borderedImage à la place de scannedImage pour l'affichage et la sauvegarde
    ui->scannedImageLabel->setPixmap(QPixmap::fromImage(borderedImage).scaled(ui->scannedImageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    // Ask user for file path to save the "scanned" image
    QString saveFileName = QFileDialog::getSaveFileName(this,
                                                        tr("Save Image"), "",
                                                        tr("PNG Image (*.png);;JPEG Image (*.jpg *.jpeg);;Bitmap Image (*.bmp)"));
    if (!saveFileName.isEmpty()) {
        // Save the image to the specified path
        scannedImage.save(saveFileName);
    }
}


void SecDialog::on_pushButton_selectImage_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choisir une image"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly)) {
            m_imageData = file.readAll();  // Stocker les données d'image

            // Afficher l'image
            QPixmap pixmap;
            pixmap.loadFromData(m_imageData);
            ui->label_imagePreview->setPixmap(pixmap.scaled(ui->label_imagePreview->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            QMessageBox::critical(this, tr("Erreur"), tr("Impossible d'ouvrir le fichier image."));
        }
    } else {
        QMessageBox::warning(this, tr("Aucune image sélectionnée"), tr("Aucune image n'a été sélectionnée."));
    }
}
void SecDialog::on_pushButton_selectImage_up_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));

    if (!fileName.isEmpty()) {
        QImage image(fileName);
        if (image.isNull()) {
            QMessageBox::information(this, tr("Image Loader"), tr("Cannot load %1.").arg(fileName));
            return;
        }

        ui->label_imagePreview->setPixmap(QPixmap::fromImage(image).scaled(ui->label_imagePreview->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

        // Convertir l'image en QByteArray pour stockage dans la BD
        QByteArray imageData;
        QBuffer buffer(&imageData);
        buffer.open(QIODevice::WriteOnly);
        image.save(&buffer, "PNG"); // sauvegarde l'image dans le format PNG dans le buffer

        // Stocker le QByteArray dans une variable membre pour l'utiliser lors de la mise à jour
        mCurrentImageData = imageData;
    }
}
void SecDialog::on_pushButton_trier_client_clicked() {
    Client client;
    QSqlQueryModel* model = client.trierClientsParDateInscription();
    if (!model) {
        qDebug() << "Erreur lors de la mise à jour du modèle de vue.";
        return;
    }
    ui->tableView->setModel(model);
}
void SecDialog::on_pushButton_chercher_client_clicked() {
    QString nom = ui->lineEdit_search_cl->text();
    Client client;
    QSqlQueryModel* model = client.chercherClient(nom);
    if (!model) {
        qDebug() << "Erreur lors de la mise à jour du modèle de vue.";
        return;
    }
    ui->tableView->setModel(model);
}

void SecDialog::on_ajouter_salle_clicked()
{
    int capacite = ui->spinBoxsalle->value();
    double prix_jour = ui->doubleSpinBoxsalle->value();
    QString etat = ui->comboBox->currentText();
    int temp_max = ui->spinBoxsalle_temp->value();

    // Vérification de la capacité et du prix
    if (capacite <= 0 || prix_jour <= 0.0) {
        QMessageBox::critical(this, "Erreur", "La capacité et le prix doivent être supérieurs à zéro !");
        return; // Annuler l'opération si l'entrée est invalide
    }

    // Création de l'objet Salle
    Salle salle;
    salle.setCapacite(capacite);
    salle.setPrixJour(prix_jour);
    salle.setEtat(etat);
    salle.setTempMax(temp_max);

    // Ajout de la salle
    bool success = salle.creer();

    if(success)
    {
        // Mise à jour de l'affichage des salles dans le TableView

        QMessageBox::information(this, "Succès", "Salle ajoutée avec succès !");
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout de la salle !");
    }
}

/*void SecDialog::on_pushButton_modifsalle_2_clicked()
{
    int id_salle = ui->lineEdit_37->text().toInt();

      QSqlQuery checkQuery;
      checkQuery.prepare("SELECT capacite, prix_jour, etat FROM salle WHERE id_salle = :id_salle");
      checkQuery.bindValue(":id_salle", id_salle);

      if (checkQuery.exec() && checkQuery.next()) {
          int capacite = checkQuery.value(0).toInt();
          double prix_jour = checkQuery.value(1).toDouble();
          QString etat = checkQuery.value(2).toString();

          ui->lineEditIdSalle_3->setText(QString::number(id_salle));
          ui->spinBoxsalle_3->setValue(capacite);
          ui->doubleSpinBoxsalle_3->setValue(prix_jour);
          ui->comboBoxsalle_3->setCurrentText(etat);

          ui->lineEditIdSalle_3->setReadOnly(true);

          ui->stackedWidget->setCurrentWidget(ui->modifsalle);
      } else {
          QMessageBox::warning(this, "Erreur", "ID de salle non trouvé dans la base de données !");
      }
}*/

/*void SecDialog::on_modifiersalle_clicked()
{
    Salle salle;

        QList<Salle> salles = salle.getSallesFromDatabase(); // Appelez la fonction membre
       int idSalleModifiee = ui->lineEdit_10->text().toInt();

       int nouvelleCapacite = ui->spinBoxsalle_3->value();
       double nouveauPrixJour = ui->doubleSpinBoxsalle_3->value();
       QString nouvelEtat = ui->comboBoxsalle_3->currentText();

       if (nouvelleCapacite <= 0 || nouveauPrixJour <= 0.0) {
           QMessageBox::warning(this, "Erreur", "La capacité et le prix doivent être supérieurs à zéro !");
           return;
       }

       QFile file("C:/Users/mello/OneDrive - ESPRIT/Bureau/QT/modifier.txt");
       if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
           QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le fichier pour l'écriture !");
           return;
       }

       QStringList lines;
       QTextStream in(&file);
       while (!in.atEnd()) {
           lines << in.readLine();
       }

       QDateTime dateTime = QDateTime::currentDateTime();

       for (int i = 0; i < lines.size(); ++i) {
           QString line = lines.at(i);
           QStringList fields = line.split(",");
           if (!fields.isEmpty() && fields.size() > 4) {
               int id = fields.at(0).split(":").last().trimmed().toInt();
               if (id == idSalleModifiee) {
                   QString nombreModificationsStr = fields.last().trimmed();
                   int nombreModifications = nombreModificationsStr.split(":").last().trimmed().toInt();
                   if (nombreModifications > 0) {
                       lines[i] = "ID: " + QString::number(idSalleModifiee) + ", capacite: " + QString::number(nouvelleCapacite) + ", etat: " + nouvelEtat + ", prix_jour: " + QString::number(nouveauPrixJour) + ", nombre_modifications: " + QString::number(nombreModifications + 1) + ", date_derniere_modification: " + dateTime.toString("yyyy-MM-dd hh:mm:ss");
                   } else {
                       lines[i] = "ID: " + QString::number(idSalleModifiee) + ", capacite: " + QString::number(nouvelleCapacite) + ", etat: " + nouvelEtat + ", prix_jour: " + QString::number(nouveauPrixJour) + ", nombre_modifications: 1, date_derniere_modification: " + dateTime.toString("yyyy-MM-dd hh:mm:ss");
                   }
                   break;
               }
           }
       }

       file.resize(0); // Efface le contenu du fichier
       QTextStream out(&file);
       for (const QString& line : lines) {
           out << line << "\n";
       }

       // Fermer le fichier
       file.close();


       bool modificationReussie = salle.modifier(idSalleModifiee, nouvelleCapacite, nouveauPrixJour, nouvelEtat);

       if (modificationReussie) {
           ui->tablesalle->setModel(salle.afficher());

           QMessageBox::information(this, "Succès", "Salle modifiée avec succès !");

           ui->stackedWidget->setCurrentWidget(ui->modifsalle);
       } else {
           QMessageBox::warning(this, "Erreur", "Erreur lors de la modification de la salle !");
       }

}*/

void SecDialog::on_pushButton_up_clicked()
{
    // Récupérer les valeurs mises à jour à partir des champs de l'interface graphique
    int id = ui->lineEdit_id_up->text().toInt(); // Assumer que c'est le champ pour l'ID
    QString nom = ui->lineEdit_nom_up->text();
    QString prenom = ui->lineEdit_prenom_up->text();
    QString sexe = ui->lineEdit_sexe_up->text();
    QString email = ui->lineEdit_email_up->text();
    QString adresse = ui->lineEdit_adresse_up->text();
    QString dateNaissance = ui->dateEdit_DDN_up->date().toString("yyyy-MM-dd");
    QString dateInscription = ui->dateEdit_inscrit_up->date().toString("yyyy-MM-dd");
    //QByteArray image; // Ajoutez le code pour récupérer l'image si nécessaire

    // Créer une instance de la classe Client
    Client client;

    // Appeler la fonction modifier() sur cette instance
    bool success = client.modifier(id, nom, prenom, sexe, email, adresse, dateNaissance, dateInscription);

    if (success) {
        // Afficher un message de réussite si la modification a réussi
        QMessageBox::information(nullptr, "Succès", "Les informations du client ont été mises à jour avec succès !");
    } else {
        // Afficher un message d'erreur si la modification a échoué
        QMessageBox::critical(nullptr, "Erreur", "La mise à jour des informations du client a échoué !");
    }

    // Revenir à la page précédente ou à la page d'accueil après la modification
    // Assumer que vous avez un widget empilé pour la navigation
   // ui->stackedWidget->setCurrentIndex(/* index de la page précédente ou de la page d'accueil */);
}
