#include "../msgHeaders/msg_listitem.h"
#include <QDebug>



Msg_ListItem::Msg_ListItem()
{

}
Msg_ListItem::Msg_ListItem(QString name, QString number, QString content, bool unRead, int sendFlag)
                        : m_name(name), m_number(number), m_content(content), m_isUnRead(unRead), m_sendFlag(sendFlag)
{
    qDebug("< msg_list > Msg_ListItem::Msg_ListItem");
}

void Msg_ListItem::setName(QString name)
{
    m_name = name;
}
void Msg_ListItem::setNumber(QString number)
{
    m_number = number;
}
void Msg_ListItem::setContent(QString content)
{
    m_content = content;
}
void Msg_ListItem::setTime(QString time)
{
    m_time = time;
}
void Msg_ListItem::setUnReadFlag(bool flag)
{
    m_isUnRead = flag;
}
void Msg_ListItem::setSendFlag(int flag)
{
    m_sendFlag = flag;
}
QString Msg_ListItem::content() const
{
    qDebug("< msg_listitem.cpp > content");
    return m_content;
}
QString Msg_ListItem::number() const
{
    return m_number;
}
QString Msg_ListItem::name() const
{
    return m_name;
}
QString Msg_ListItem::time() const
{
    return m_time;
}
bool Msg_ListItem::unReadFlag() const
{
    return m_isUnRead;
}
int Msg_ListItem::sendFlag() const
{
    return m_sendFlag;
}

//
Msg_ListModel::Msg_ListModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

void Msg_ListModel::addItem(Msg_ListItem &item)
{
    qDebug("msg_listitem addItem");
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_messageItems << item;
    endInsertRows();
}
void Msg_ListModel::clear()
{
    qDebug("msg_listitem clearItem");
    beginResetModel();
    m_messageItems.clear();
    endResetModel();
}
QVariant Msg_ListModel::get(int index, QString role)
{
    if (index < 0 || index >= m_messageItems.count())
        return QVariant();

    const Msg_ListItem &item = m_messageItems[index];
    if (role == "content")
        return item.content();
    else if (role == "number")
        return item.number();
    else if (role == "name")
        return item.name();
    else if (role == "icon")
        return item.icon();
    else
        return QVariant();
}

int Msg_ListModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);
    return m_messageItems.count();
}

QVariant Msg_ListModel::data(const QModelIndex & index, int role) const
{
    if (index.row() < 0 || index.row() >= m_messageItems.count())
        return QVariant();

    const Msg_ListItem &item = m_messageItems[index.row()];
    if (role == ContentRole)
        return item.content();
    else if(role == NumberRole)
        return item.number();
    else if(role == NameRole)
        return item.name();
    else if(role == TimeRole)
        return item.time();
    else if(role == ReadFlagRole)
        return item.unReadFlag();
    else if(role == SendFlagRole)
        return item.sendFlag();
    else if(role == IconRole)
        return item.icon();
    else
        return QVariant();
}

QHash<int, QByteArray> Msg_ListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[NumberRole] = "number";
    roles[ContentRole] = "content";
    roles[TimeRole] = "time";
    roles[ReadFlagRole] = "unRead";
    roles[SendFlagRole] = "sendFlag";
    roles[IconRole] = "icon";

    return roles;
}

void Msg_ListItem::setIconRole(QString icon)
{
    qDebug() << "[ msg_listitem.cpp ] m_icon = icon:" << icon;
    m_icon = icon;
}
QString Msg_ListItem::icon() const
{
    qDebug() << "[ msg_listitem.cpp ] m_icon:" << m_icon;
    return m_icon;
}
