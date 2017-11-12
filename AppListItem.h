#ifndef APPLISTITEM_H
#define APPLISTITEM_H
#include <QAbstractListModel>
#include <QString>


class AppListItem
{
public:
    AppListItem() {}
    AppListItem(QString name, QString iconPath,int index, int pageIndex=0):
        m_name(name),m_iconPath(iconPath),m_index(index),m_pageIndex(pageIndex)
    {
    }

    QString name() const;
    QString iconPath() const;
    int index() const;
    int pageIndex() const;

private:
    QString m_name,m_iconPath;
	int m_index;
    int m_pageIndex;
};


class AppListItemModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit AppListItemModel(QObject *parent = 0):QAbstractListModel(parent)
    {
    }

    enum AppListItemRoles {
        NameRole = Qt::UserRole + 1,
        IconPathRole,
        IndexRole,
        PageIndexRole,
    };

    void addAppListItem(const AppListItem &item);

    int getCurAppListIndex(QString name);

    Q_INVOKABLE void clear();

    Q_INVOKABLE QVariant get(int index, QString role);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role) const;

    QHash<int, QByteArray> roleNames() const;

private:
    QList<AppListItem> m_AppListItem;

};


#endif // APPLISTITEM_H
