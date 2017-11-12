#ifndef MSG_DETAILLISTITEM_H
#define MSG_DETAILLISTITEM_H
#include <QAbstractListModel>

class Msg_DetailListItem
{
public:
    Msg_DetailListItem();
    Msg_DetailListItem(QString content, QString time, QString name, QString number,QString msgID, bool isSend, int sendFlag, int rank);

    QString content() const;
    QString time() const;
    QString name() const;
    QString number() const;
    QString msgID() const;
    int rank() const;
    bool isSend() const;
    int sendFlag() const;
    void setContent(QString content);
    void setTime(QString time);
    void setIsSend(bool flag);
    void setSendFlag(int flag);

private:
    QString m_content, m_time, m_name, m_number, m_msgID;
    bool m_isSend;
    int m_sendFlag;
    int m_rank;
};

class Msg_DetailListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit Msg_DetailListModel(QObject *parent = 0);

    enum ListRoles {
        ContentRole = Qt::UserRole + 1,
        TimeRole,
        NameRole,
        NumberRole,
        IsSendRole,
        SendFlagRole,
        MsgIdRole,
        RankRole
    };

    void addItem(Msg_DetailListItem &item);
    Q_INVOKABLE void clear();
    QVariant get(int index, QString role);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::UserRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<Msg_DetailListItem> m_detailItems;

};

#endif // MSG_DETAILLISTITEM_H
