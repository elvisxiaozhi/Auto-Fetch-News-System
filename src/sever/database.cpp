#include "database.h"
#include <QSqlError>
#include <QSqlQuery>

QStringList Database::titleList;

Database::Database(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("password");

    if(!db.open()) {
        qDebug() << db.lastError();
    }
}

Database::~Database()
{
    db.close();
}

void Database::readData()
{
    QSqlQuery query;
    query.exec("SELECT title FROM articles");
    while (query.next()) {
        titleList += query.value(0).toStringList();
    }
}
