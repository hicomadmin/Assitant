#include "../phoneHeaders/phonethinkresultlistitem.h"

phoneThinkResultListItem::phoneThinkResultListItem()
{
}
phoneThinkResultListItem::phoneThinkResultListItem(QString name, QString number)
    : m_name(name),m_number(number)
{
}
QString phoneThinkResultListItem::name() const
{
    return m_name;
}

QString phoneThinkResultListItem::number() const
{
    return m_number;
}


// model
phoneThinkResultListModel::phoneThinkResultListModel(QObject *parent) : QAbstractListModel(parent)
{

}

void phoneThinkResultListModel::addItem(phoneThinkResultListItem &item)
{
    beginInsertRows(QModelIndex(),rowCount(), rowCount());
    m_phoneThinkResultItem << item;
    endInsertRows();
}
void phoneThinkResultListModel::clear()
{
    beginResetModel();
    m_phoneThinkResultItem.clear();
    endResetModel();
}
QVariant phoneThinkResultListModel::get(int index, QString role)
{
    if(index < 0 ||  index >= m_phoneThinkResultItem.count())
        return QVariant();

    const phoneThinkResultListItem &item = m_phoneThinkResultItem[index];
    if(role == "name")
        return item.name();
    else if(role == "number")
        return item.number();
    else
        return QVariant();

}

int phoneThinkResultListModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);
    return m_phoneThinkResultItem.count();
}
QVariant phoneThinkResultListModel::data(const QModelIndex & index, int role) const
{
    if(index.row() < 0 || index.row() >= m_phoneThinkResultItem.count())
        return QVariant();

    const phoneThinkResultListItem &item = m_phoneThinkResultItem[index.row()];
    if(role == NameRole)
        return item.name();
    else if(role == NumberRole)
        return item.number();
    else
        return QVariant();
}

QHash<int, QByteArray> phoneThinkResultListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[NumberRole] = "number";

    return roles;
}



