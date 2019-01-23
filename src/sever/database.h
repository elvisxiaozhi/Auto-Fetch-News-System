#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QDebug>

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);
    ~Database();
    static QStringList dateList;
    static QStringList titleList;
    static QStringList linkList;
    static QStringList keywordList;
    static QStringList viewList;
    static QStringList likeList;
    static QStringList commentList;
    static void readData();
    static void writeData(QString, QString, QString, QString, int, int, int);

private:
    QSqlDatabase db;
};

#endif // DATABASE_H
