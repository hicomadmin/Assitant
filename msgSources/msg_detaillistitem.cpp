#include "../msgHeaders/msg_detaillistitem.h"
#include <QDebug>

Msg_DetailListItem::Msg_DetailListItem()
{
}

Msg_DetailListItem::Msg_DetailListItem(QString content, QString time, QString name, QString number,QString msgID, bool isSend, int sendFlag, int rank)
 : m_content(content), m_time(time), m_name(name), m_number(number), m_msgID(msgID), m_isSend(isSend), m_sendFlag(sendFlag), m_rank(rank)
{

}
QString Msg_DetailListItem::content() const
{
    return m_content;
}
QString Msg_DetailListItem::time() const
{
    return m_time;
}
QString Msg_DetailListItem::name() const
{
    return m_name;
}
QString Msg_DetailListItem::number() const
{
    return m_number;
}
QString Msg_DetailListItem::msgID() const
{
    return m_msgID;
}
int Msg_DetailListItem::rank() const
{
    return m_rank;
}
bool Msg_DetailListItem::isSend() const
{
    return m_isSend;
}
int Msg_DetailListItem::sendFlag() const
{
    return m_sendFlag;
}
void Msg_DetailListItem::setContent(QString content)
{
    m_content = content;
}
void Msg_DetailListItem::setTime(QString time)
{
    m_time = time;
}
void Msg_DetailListItem::setIsSend(bool flag)
{
    m_isSend = flag;
}
void Msg_DetailListItem::setSendFlag(int flag)
{
    m_sendFlag = flag;
}

Msg_DetailListModel::Msg_DetailListModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

void Msg_DetailListModel::addItem(Msg_DetailListItem &item)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_detailItems << item;
    endInsertRows();
}
void Msg_DetailListModel::clear()
{
    beginResetModel();
    m_detailItems.clear();
    endResetModel();
}
QVariant Msg_DetailListModel::get(int index, QString role)
{
    if (index < 0 || index >= m_detailItems.count())
        return QVariant();

    const Msg_DetailListItem &item = m_detailItems[index];
    if (role == "content")
        return item.content();
    else if (role == "number")
        return item.number();
    else if (role == "name")
        return item.name();
    else if(role == "msgID")
        return item.msgID();
    else if(role == "rank")
        return item.rank();
    else
        return QVariant();
}

int Msg_DetailListModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);
    return m_detailItems.count();
}

QVariant Msg_DetailListModel::data(const QModelIndex & index, int role) const
{
    if (index.row() < 0 || index.row() >= m_detailItems.count())
        return QVariant();

    const Msg_DetailListItem &item = m_detailItems[index.row()];
    if (role == ContentRole)
        return item.content();
    else if(role == TimeRole)
        return item.time();
    else if (role == NameRole)
        return item.name();
    else if(role == NumberRole)
        return item.number();
    else if(role == IsSendRole)
        return item.isSend();
    else if(role == SendFlagRole)
        return item.sendFlag();
    else if(role == MsgIdRole)
        return item.msgID();
    else if(role == RankRole)
        return item.rank();
    else
        return QVariant();
}

QHash<int, QByteArray> Msg_DetailListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ContentRole] = "content";
    roles[TimeRole] = "time";
    roles[NameRole] = "name";
    roles[NumberRole] = "number";
    roles[IsSendRole] = "isSend";
    roles[SendFlagRole] = "sendFlag";
    roles[MsgIdRole] = "msgID";
    roles[RankRole] = "rank";

    return roles;
}
