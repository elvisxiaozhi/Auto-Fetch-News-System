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
        QSqlQuery query;
        query.exec("SELECT title FROM articles");
        query.first();
        qDebug() << query.value(0).toString();
    }
    else {
        qDebug() << db.lastError();
    }
}
