/*******************************************************
文  件  名：phonebooklistitem.h
描      述 ： 电话簿列表
*******************************************************/
#ifndef PHONEBOOKLISTITEM_H
#define PHONEBOOKLISTITEM_H
#include <QDebug>
#include <QAbstractListModel>


class PhonebookListItem
{
public:
    PhonebookListItem();
    PhonebookListItem(const QString &name, const QString &number, const QString &type, const QString &nameSZM, const QString &nameGroup);
    QString name() const;
    QString number() const;
    QString type() const;
    QString nameSZM() const;
    QString nameGroup() const;


private:
    QString m_name;
    QString m_number;
    QString m_type;
    QString m_nameSZM;
    QString m_nameGroup;

};

class PhonebookListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit PhonebookListModel(QObject *parent = 0);
    enum PhonebookListItemRoles{
        NameRole = Qt::UserRole + 1,
        NumberRole,
        TypeRole,
        NameSZMRole,
        NameGroupRole,
        IconRole
    };

    void addContactItem(const PhonebookListItem &contactItem);
    Q_INVOKABLE void clear();
    unsigned int getSearchResultIndex(QString ch);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::UserRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<PhonebookListItem> m_contactItems;

};


#endif // PHONEBOOKLISTITEM_H
