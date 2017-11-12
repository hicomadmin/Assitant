#include "LocalMusicListItem.h"
#include <QDebug>

QString LocalMusicListItem :: name() const
{
	return m_musicName;
}

QString LocalMusicListItem :: singer() const
{
	return m_musicSinger;
}

//QString LocalMusicListItem :: time()const
//{
//	return m_musicTime;
//}

//QString LocalMusicListItem :: addr()const
//{
//    return m_musicAddr;
//}

QString LocalMusicListItem ::identification() const
{
    return m_musicId;
}

QString LocalMusicListModel::getCurProgramFromIndex(int index)
{
    return m_localMusicItems.at(index).name();
}

void LocalMusicListModel :: addLocalMusicListItem(const LocalMusicListItem &item)
{
	beginInsertRows(QModelIndex(), rowCount(), rowCount());
	m_localMusicItems << item;
	endInsertRows();
}

int  LocalMusicListModel :: getCurLocalMusicIndex(QString musicName)
{
    for(int i = 0; i < m_localMusicItems.count(); i++)
	{
		QString songName = m_localMusicItems.at(i).name();
		if(songName == musicName){
			return i;
			break;
		}
	}

    return 0;
}

void  LocalMusicListModel :: clear()
{
	beginResetModel();
	m_localMusicItems.clear();
	endResetModel();
}

QVariant LocalMusicListModel :: get(int index, QString role)
{
	qDebug("get");
	if (index < 0 || index >= m_localMusicItems.count())
		return QVariant();

	const LocalMusicListItem &item = m_localMusicItems[index];
	if (role == "localMusicName")
		return item.name();
	else if (role == "localMusicSinger")
		return item.singer();
    else if (role == "songId")
        return item.identification();
//	else if(role == "duration")
//		return item.time();
//    else if(role == "musicAddress")
//        return item.addr();
	else
		return QVariant();
}

int LocalMusicListModel :: rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);
    return m_localMusicItems.count();
}

QVariant  LocalMusicListModel :: data(const QModelIndex & index, int role) const
{
	if (index.row() < 0 || index.row() >= m_localMusicItems.count())
		return QVariant();

	const LocalMusicListItem &item = m_localMusicItems[index.row()];
	if (role == NameRole)
		return item.name();
	else if (role == SingerRole)
		return item.singer();
//	else if(role == TimeRole)
//		return item.time();
    else if (role == IdRole)
        return item.identification();
//    else if (role == AddrRole)
//        return item.addr();
	else
		return QVariant();
}

QHash<int, QByteArray>  LocalMusicListModel :: roleNames() const
{
	QHash<int, QByteArray> roles;
	roles[NameRole] = "localMusicName";
	roles[SingerRole] = "localMusicSinger";
    roles[IdRole] = "songId";
//	  roles[TimeRole] = "duration";
//    roles[AddrRole] = "musicAddress";

	return roles;
}

