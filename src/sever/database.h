#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQueryModel>

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);
    ~Database();
    static QSqlQueryModel *readData();
    static void writeData(QString, QString, QString, int, int, int, QString, QString);
    static void deleteRow(QString);

private:
    QSqlDatabase db;
};

#endif // DATABASE_H
