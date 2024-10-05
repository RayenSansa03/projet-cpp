#ifndef CLIENTMODEL_H
#define CLIENTMODEL_H


#include <QSqlQueryModel>
#include <QPixmap>

class ClientModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit ClientModel(QObject *parent = nullptr);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};


#endif // CLIENTMODEL_H
