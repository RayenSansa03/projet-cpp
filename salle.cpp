#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QPrinter>
#include <QDate>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlQueryModel>
#include <salle.h>

Salle::Salle() {}

Salle::Salle(int capacite, const QString& etat, double prixJour, int tempMax)
    : capacite(capacite), etat(etat), prixJour(prixJour), tempMax(tempMax) {}

// Setters
void Salle::setCapacite(int capacite) { this->capacite = capacite; }
void Salle::setEtat(const QString& etat) { this->etat = etat; }
void Salle::setPrixJour(double prixJour) { this->prixJour = prixJour; }
void Salle::setTempMax(int tempMax) { this->tempMax = tempMax; }

// Getters
int Salle::getId() const { return id; }
int Salle::getCapacite() const { return capacite; }
QString Salle::getEtat() const { return etat; }
double Salle::getPrixJour() const { return prixJour; }
int Salle::getTempMax() const { return tempMax; }

// Opérations CRUD
bool Salle::creer() {
    QSqlQuery query;
    query.prepare("INSERT INTO SALLE (CAPACITE, ETAT, PRIX_JOUR, TEMP_MAX) "
                  "VALUES (:capacite, :etat, :prixJour, :tempMax)");
    query.bindValue(":capacite", capacite);
    query.bindValue(":etat", etat);
    query.bindValue(":prixJour", prixJour);
    query.bindValue(":tempMax", tempMax);
    return query.exec();
}
QSqlQueryModel* Salle::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_SALLE, CAPACITE, ETAT, PRIX_JOUR, TEMP_MAX FROM SALLE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Capacité"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("État"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix Jour"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Température maximale"));
    return model;
}

bool Salle::lire(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM SALLE WHERE ID_SALLE = :id");
    query.bindValue(":id", id);
    if (query.exec() && query.first()) {
        this->id = query.value("ID_SALLE").toInt();
        capacite = query.value("CAPACITE").toInt();
        etat = query.value("ETAT").toString();
        prixJour = query.value("PRIX_JOUR").toDouble();
        tempMax = query.value("TEMP_MAX").toInt();
        return true;
    }
    return false;
}

bool Salle::mettreAJour() {
    QSqlQuery query;
    query.prepare("UPDATE SALLE SET CAPACITE = :capacite, ETAT = :etat, "
                  "PRIX_JOUR = :prixJour, TEMP_MAX = :tempMax WHERE ID_SALLE = :id");
    query.bindValue(":id", id);
    query.bindValue(":capacite", capacite);
    query.bindValue(":etat", etat);
    query.bindValue(":prixJour", prixJour);
    query.bindValue(":tempMax", tempMax);
    return query.exec();
}

bool Salle::supprimer() {
    QSqlQuery query;
    query.prepare("DELETE FROM SALLE WHERE ID_SALLE = :id");
    query.bindValue(":id", id);
    return query.exec();
}
/*
bool verifierTemperatureSalle(int id_salle, double temperature) {
    QSqlQuery query;
    query.prepare("SELECT temp_max FROM salles WHERE id_salle = :id");
    query.bindValue(":id", id_salle);

    if (query.exec() && query.next()) {
        double temp_max = query.value(0).toDouble();
        return temperature >= temp_max;
    } else {
        // Erreur lors de l'exécution de la requête ou la salle n'existe pas
        // Vous pouvez ajouter ici du code pour gérer cette situation, par exemple :
        qDebug() << "Erreur lors de la récupération de la température maximale de la salle avec l'ID" << id_salle;
        return false;
    }
}
*/
