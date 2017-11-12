#include "../phoneHeaders/phonebooklistitem.h"
#include "../SSPLInk/ssp_assist_struct.h"
#include "../SSPLInk/ssp_assist_if.h"

PhonebookListItem::PhonebookListItem()
{
}

PhonebookListItem::PhonebookListItem(const QString &name, const QString &number, const QString &type, const QString &nameSZM, const QString &nameGroup)
    : m_name(name), m_number(number), m_type(type), m_nameSZM(nameSZM), m_nameGroup(nameGroup)
{

}


QString PhonebookListItem::name() const
{
    return m_name;
}
QString PhonebookListItem::number() const
{
    return m_number;
}
QString PhonebookListItem::type() const
{
    return m_type;
}
QString PhonebookListItem::nameSZM() const
{
    return m_nameSZM;
}
QString PhonebookListItem::nameGroup() const
{
    return m_nameGroup;
}

//Model
PhonebookListModel::PhonebookListModel(QObject *parent ) : QAbstractListModel(parent)
{

}

unsigned int PhonebookListModel::getSearchResultIndex(QString ch)
{
    for(int i = 0; i < m_contactItems.count(); i++)
    {
        if(ch == m_contactItems.at(i).nameGroup())
        {
            //qDebug() << "############### m_contactItems.at(" << i << "):" << m_contactItems.at(i).nameGroup();
            return i;
            break;
        }
    }
    return 0;
}

void PhonebookListModel::addContactItem(const PhonebookListItem &contactItem)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_contactItems << contactItem;
    endInsertRows();
}
void PhonebookListModel::clear()
{
    beginResetModel();
    m_contactItems.clear();
    endResetModel();
}
int PhonebookListModel::rowCount(const QModelIndex & parent ) const
{
    Q_UNUSED(parent);
    return m_contactItems.count();
}
QVariant PhonebookListModel::data(const QModelIndex & index, int role) const
{
    if (index.row() < 0 || index.row() >= m_contactItems.count())
        return QVariant();

    const PhonebookListItem &contactItem = m_contactItems[index.row()];
    if (role == NameRole)
        return contactItem.name();
    else if (role == NumberRole)
        return contactItem.number();
    else if (role == TypeRole)
        return contactItem.type();
    else if (role == NameSZMRole)
        return contactItem.nameSZM();
    else if (role == NameGroupRole)
        return contactItem.nameGroup();
    else
        return QVariant();
}

QHash<int, QByteArray> PhonebookListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[NumberRole] = "number";
    roles[TypeRole] = "type";
    roles[NameSZMRole] = "nameSZM";
    roles[NameGroupRole] = "nameGroup";
    return roles;
}


