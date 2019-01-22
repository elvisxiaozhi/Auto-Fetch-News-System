#include "database.h"
#include <QSqlError>
#include <QSqlQuery>

database::database(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("password");

    if(db.open()) {
        qDebug() << "Opened";
    }
    else {
        qDebug() << db.lastError();
    }

    QSqlQuery query;
    query.exec("SELECT title FROM articles");
    while (query.next()) {
        titleList += query.value(0).toStringList();
    }

    qDebug() << titleList;
}
