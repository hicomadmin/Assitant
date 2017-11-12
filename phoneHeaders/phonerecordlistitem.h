/*******************************************************
文  件  名：phonerecordlistitem.h
描      述 ： 最近通话记录列表
*******************************************************/
#ifndef PHONERECORDLISTITEM_H
#define PHONERECORDLISTITEM_H
#include <QAbstractListModel>
#include <QString>

class PhoneRecordListItem
{
public:
    PhoneRecordListItem();
    PhoneRecordListItem(QString date, int type, QString name, QString number);



    QString name() const;
    QString number() const;
    QString date() const;
    int type() const;

private:
    QString m_date;
    int m_type;
    QString m_name;
    QString m_number;

};

//Model
class PhoneRecordListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit PhoneRecordListModel(QObject *parent = 0);
    enum PhoneRecordListRoles{
        NameRole =  Qt::UserRole + 1,
        NumberRole,
        DateRole,
        TypeRole
    };

    void addItem(PhoneRecordListItem &item);
    void clear();
    QVariant get(int index, QString role);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::UserRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<PhoneRecordListItem> m_PhoneRecordItem;

};


#endif // PHONERECORDLISTITEM_H
