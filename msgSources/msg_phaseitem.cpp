#include "../msgHeaders/msg_phaseitem.h"



Msg_PhaseItem::Msg_PhaseItem(QString content) : m_content(content)
{

}

QString Msg_PhaseItem::content() const
{
    return m_content;
}
void Msg_PhaseItem::setContent(QString content)
{
    m_content = content;
}


//model
Msg_PhaseModel::Msg_PhaseModel(QObject *parent) : QAbstractListModel(parent)
{
    Msg_PhaseItem item("");


    item = Msg_PhaseItem(tr("您好，我正在开车，稍后与您联系！"));
    addItem(item);
    item = Msg_PhaseItem(tr("路上堵车，晚点到！"));
    addItem(item);
    item = Msg_PhaseItem(tr("我很快就到，请稍微等一会。"));
    addItem(item);
    item = Msg_PhaseItem(tr("你现在在哪里？"));
    addItem(item);
    item = Msg_PhaseItem(tr("当前正忙，请稍后联系我，谢谢！"));
    addItem(item);

}
void Msg_PhaseModel::addItem(Msg_PhaseItem &item)
{
    beginInsertRows(QModelIndex(), rowCount(),rowCount());
    m_phaseItems << item;
    endInsertRows();
}

void Msg_PhaseModel::clear()
{
    beginResetModel();
    m_phaseItems.clear();
    endResetModel();
}

int Msg_PhaseModel::rowCount(const QModelIndex & parent ) const
{
    Q_UNUSED(parent);
    return m_phaseItems.count();
}

QVariant Msg_PhaseModel::data(const QModelIndex & index, int role ) const
{
    if (index.row() < 0 || index.row() >= m_phaseItems.count())
        return QVariant();

    const Msg_PhaseItem &item = m_phaseItems[index.row()];
    if (role == ContentRole)
        return item.content();
    else
        return QVariant();
}

 QHash<int, QByteArray> Msg_PhaseModel::roleNames() const
 {
     QHash<int, QByteArray> roles;
     roles[ContentRole] = "content";

     return roles;
 }



