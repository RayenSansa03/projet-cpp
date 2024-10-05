#ifndef SALLE_H
#define SALLE_H

#include <QtSql>
#include <QString>
#include <QDebug>

class Salle {
private:
    int id;
    int capacite;
    QString etat;
    double prixJour;
    int tempMax;

public:
    Salle();
    Salle(int capacite, const QString& etat, double prixJour, int tempMax);
    bool verifierTemperatureSalle(int id_salle, double temperature);


    // Setters
    void setId(int id);
    void setCapacite(int capacite);
    void setEtat(const QString& etat);
    void setPrixJour(double prixJour);
    void setTempMax(int tempMax);

    // Getters
    int getId() const;
    int getCapacite() const;
    QString getEtat() const;
    double getPrixJour() const;
    int getTempMax() const;

    // Opérations CRUD
    bool creer();
    bool lire(int id);
    bool mettreAJour();
    bool supprimer();
    QSqlQueryModel* afficher();


};

#endif // SALLE_H
