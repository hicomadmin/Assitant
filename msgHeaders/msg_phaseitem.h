#ifndef MSG_PHASEITEM_H
#define MSG_PHASEITEM_H
#include <QAbstractListModel>

class Msg_PhaseItem
{
public:
    Msg_PhaseItem(QString content);
    QString content() const;
    void setContent(QString content);

private:
    QString m_content;
};

class Msg_PhaseModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit Msg_PhaseModel(QObject *parent = 0);

    enum ListRoles {
        ContentRole = Qt::UserRole + 1,
    };

    void addItem(Msg_PhaseItem &item);
    void clear();
    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::UserRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<Msg_PhaseItem> m_phaseItems;

};

#endif // MSG_PHASEITEM_H
