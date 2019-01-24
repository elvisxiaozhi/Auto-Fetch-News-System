#include "database.h"
#include <QSqlError>
#include <QSqlQuery>

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

QSqlQueryModel *Database::readData()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT *FROM articles");
    query.exec();
    model->setQuery(query);

    return model;
}

void Database::writeData(QString date, QString title, QString link, QString keywords, int views, int likes, int comments)
{
    QSqlQuery query;
    query.prepare("INSERT INTO articles"
                  "(publication_date, title, link, keywords, views, likes, comments)"
                  "VALUES"
                  "(:dateValue, :titleValue, :linkValue, :keywordsValue, :viewsValue, :likesValue, :commentsValue);");
    query.bindValue(":dateValue", date);
    query.bindValue(":titleValue", title);
    query.bindValue(":linkValue", link);
    query.bindValue(":keywordsValue", keywords);
    query.bindValue(":viewsValue", views);
    query.bindValue(":likesValue", likes);
    query.bindValue(":commentsValue", comments);
    query.exec();
}
