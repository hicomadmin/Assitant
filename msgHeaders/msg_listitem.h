#ifndef MSG_LISTITEM_H
#define MSG_LISTITEM_H
#include <QAbstractListModel>

class Msg_ListItem
{
public:
    Msg_ListItem();
    Msg_ListItem(QString name, QString number, QString content, bool unRead, int sendFlag);
    void setName(QString name);
    void setNumber(QString number);
    void setContent(QString content);
    void setTime(QString time);
    void setUnReadFlag(bool flag);
    void setSendFlag(int flag);
    void setIconRole(QString icon);
    QString name() const;
    QString number() const;
    QString content() const;
    QString time() const;
    bool unReadFlag() const;
    int sendFlag() const;
    QString icon() const;
private:
    QString m_name, m_number, m_content, m_time, m_icon;
    bool m_isUnRead;
    int m_sendFlag;
};

class Msg_ListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit Msg_ListModel(QObject *parent = 0);

    enum ListRoles {
        NameRole = Qt::UserRole + 1,
        NumberRole,
        ContentRole,
        TimeRole,
        ReadFlagRole,
        SendFlagRole,
        IconRole
    };

    void addItem(Msg_ListItem &item);
    void clear();
    QVariant get(int index, QString role);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::UserRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<Msg_ListItem> m_messageItems;


};

#endif // MSG_LISTITEM_H
