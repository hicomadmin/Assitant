/*******************************************************
文  件  名 ： phoneThinkResultListItem.h
描      述 ： 联想结果
*******************************************************/
#ifndef PHONETHINKRESULTLISTITEM_H
#define PHONETHINKRESULTLISTITEM_H

#include <QAbstractListModel>

class phoneThinkResultListItem
{
public:
    phoneThinkResultListItem();
    phoneThinkResultListItem(QString name, QString number);

    QString name() const;
    QString number() const;

private:
    QString m_name;
    QString m_number;
};

class phoneThinkResultListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit phoneThinkResultListModel(QObject *parent =0);
    enum phoneThinkResulRoles
    {
        NameRole =  Qt::UserRole + 1,
        NumberRole
    };

    void addItem(phoneThinkResultListItem &item);
    Q_INVOKABLE void clear();
    QVariant get(int index, QString role);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::UserRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<phoneThinkResultListItem> m_phoneThinkResultItem;

};

#endif // PHONETHINKRESULTLISTITEM_H
