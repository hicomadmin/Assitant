#include "AppListItem.h"

QString AppListItem::name() const
{
	return m_name;
}
QString AppListItem::iconPath() const
{
	return m_iconPath;
}
int AppListItem::index() const
{
	return m_index;
}

int AppListItem::pageIndex() const
{
    return m_pageIndex;
}


void AppListItemModel :: addAppListItem(const AppListItem &item)
{
	beginInsertRows(QModelIndex(), rowCount(), rowCount());
	m_AppListItem << item;
	endInsertRows();
}

int  AppListItemModel :: getCurAppListIndex(QString name)
{
    for(int i = 0; i < m_AppListItem.count(); i++)
	{
		QString AppName = m_AppListItem.at(i).name();
		if(AppName == name){
			return i;
			break;
		}
	}

    return 0;
}

void  AppListItemModel :: clear()
{
	beginResetModel();
	m_AppListItem.clear();
	endResetModel();
}

QVariant AppListItemModel :: get(int index, QString role)
{
	if (index < 0 || index >= m_AppListItem.count())
		return QVariant();

	const AppListItem &item = m_AppListItem[index];
	if (role == "AppListName")
		return item.name();
	else if (role == "AppListIconPath")
		return item.iconPath();
    else if (role == "AppListIndex")
        return item.index();
    else if (role == "AppListPageIndex")
        return item.pageIndex();
	else
		return QVariant();
}

int AppListItemModel :: rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);
    return m_AppListItem.count();
}

QVariant  AppListItemModel :: data(const QModelIndex & index, int role) const
{
	if (index.row() < 0 || index.row() >= m_AppListItem.count())
		return QVariant();

	const AppListItem &item = m_AppListItem[index.row()];
	if (role == NameRole)
		return item.name();
	else if (role == IconPathRole)
		return item.iconPath();
    else if (role == IndexRole)
        return item.index();
    else if (role == PageIndexRole)
        return item.pageIndex();
	else
		return QVariant();
}

QHash<int, QByteArray>  AppListItemModel :: roleNames() const
{
	QHash<int, QByteArray> roles;
	roles[NameRole] = "AppListName";
	roles[IconPathRole] = "AppListIconPath";
    roles[IndexRole] = "AppListIndex";
    roles[PageIndexRole] = "AppListPageIndex";

	return roles;
}
