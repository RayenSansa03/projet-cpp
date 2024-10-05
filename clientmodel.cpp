#include "clientmodel.h"

ClientModel::ClientModel(QObject *parent) : QSqlQueryModel(parent)
{
}

QVariant ClientModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.column() == votreIndexDeColonneImage && role == Qt::DecorationRole) { // Remplacer votreIndexDeColonneImage par l'index réel de votre colonne image
        QByteArray imageData = QSqlQueryModel::data(index, Qt::DisplayRole).toByteArray();
        QPixmap pixmap;
        pixmap.loadFromData(imageData);
        return pixmap.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation); // Adaptez la taille selon vos besoins
    }

    return QSqlQueryModel::data(index, role);
}
