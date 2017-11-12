#include "../phoneHeaders/phonerecordlistitem.h"

PhoneRecordListItem::PhoneRecordListItem()
{
}

PhoneRecordListItem::PhoneRecordListItem(QString date, int type, QString name, QString number)
    :m_date(date), m_type(type), m_name(name), m_number(number)
{

}

QString PhoneRecordListItem::name() const
{
    return m_name;
}
QString PhoneRecordListItem::number() const
{
    return m_number;
}

QString PhoneRecordListItem::date() const
{
    return m_date;
}
int PhoneRecordListItem::type() const
{
    return m_type;
}



//model
PhoneRecordListModel::PhoneRecordListModel(QObject *parent ) :QAbstractListModel(parent)
{
}

void PhoneRecordListModel::addItem(PhoneRecordListItem &item)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_PhoneRecordItem << item;
    endInsertRows();
}

void PhoneRecordListModel::clear()
{
    beginResetModel();
    m_PhoneRecordItem.clear();
    endResetModel();
}

QVariant PhoneRecordListModel::get(int index, QString role)
{
    if(index < 0 ||  index >= m_PhoneRecordItem.count())
        return QVariant();

    const PhoneRecordListItem &item = m_PhoneRecordItem[index];
    if (role == "number")
        return item.number();
    else if (role == "name")
        return item.name();
    else if(role ==  "date")
        return item.date();
    else if(role == "type")
        return item.type();
    else
        return QVariant();
}

int PhoneRecordListModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);
    return m_PhoneRecordItem.count();
}
QVariant PhoneRecordListModel::data(const QModelIndex &index, int role ) const
{
    if(index.row() < 0 ||  index.row() >= m_PhoneRecordItem.count())
        return QVariant();

    const PhoneRecordListItem &item = m_PhoneRecordItem[index.row()];
    if (role == NameRole)
        return item.name();
    else if(role == NumberRole)
        return item.number();
    else if(role == DateRole)
        return item.date();
    else if(role == TypeRole)
        return item.type();
    else
        return QVariant();

}

QHash<int, QByteArray> PhoneRecordListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[NumberRole] = "number";
    roles[DateRole] = "date";
    roles[TypeRole] = "type";

    return roles;
}



