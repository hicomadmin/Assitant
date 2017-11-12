#ifndef LOCALMUSICLISTITEM_H
#define LOCALMUSICLISTITEM_H
#include <QAbstractListModel>
#include <QString>


class LocalMusicListItem
{
public:
    LocalMusicListItem() {}
    LocalMusicListItem(QString musicName, QString musicSinger/*,QString musicTime,
                       QString musicAddr*/,QString musicId):
        m_musicName(musicName), m_musicSinger(musicSinger),/* m_musicTime(musicTime),
        m_musicAddr(musicAddr),*/m_musicId(musicId)
    {
    }

    QString name() const;
    QString singer() const;
    //QString time()const;
    //QString addr()const;
    QString identification() const;

private:
    QString m_musicName,m_musicSinger,/*m_musicTime,m_musicAddr,*/m_musicId;
};


class LocalMusicListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit LocalMusicListModel(QObject *parent = 0):QAbstractListModel(parent)
    {
    }

    enum LocalMusicItemRoles {
        NameRole = Qt::UserRole + 1,
        SingerRole,
        //TimeRole,
        //AddrRole,
        IdRole
    };

    void addLocalMusicListItem(const LocalMusicListItem &item);

    QString getCurProgramFromIndex(int index);

    int getCurLocalMusicIndex(QString musicName);

    Q_INVOKABLE void clear();

    Q_INVOKABLE QVariant get(int index, QString role);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role) const;

    QHash<int, QByteArray> roleNames() const;

private:
    QList<LocalMusicListItem> m_localMusicItems;

};


#endif // LOCALMUSICLISTITEM_H
