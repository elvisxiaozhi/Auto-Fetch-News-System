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

void Database::writeData(QString date, QString title, QString link, int views, int likes, int comments, QString keywords, QString remark)
{
    QSqlQuery query;
    query.prepare("INSERT INTO articles"
                  "(publication_date, title, link, views, likes, comments, keywords, remark)"
                  "VALUES"
                  "(:dateValue, :titleValue, :linkValue, :viewsValue, :likesValue, :commentsValue, :keywordsValue, :remarkValue);");
    query.bindValue(":dateValue", date);
    query.bindValue(":titleValue", title);
    query.bindValue(":linkValue", link);
    query.bindValue(":viewsValue", views);
    query.bindValue(":likesValue", likes);
    query.bindValue(":commentsValue", comments);
    query.bindValue(":keywordsValue", keywords);
    query.bindValue(":remarkValue", remark);
    query.exec();
}

void Database::modifyData(QString id, QString date, QString title, QString link, int views, int likes, int comments, QString keywords, QString remark)
{
    QSqlQuery query;

    query.prepare("UPDATE articles SET "
                  "publication_date = :dateValue, title = :titleValue, link = :linkValue,"
                  "views = :viewsValue, likes = :likesValue, comments = :commentsValue,"
                  "keywords = :keywordsValue, remark = :remarkValue "
                  "WHERE article_id = :id;");
    query.bindValue(":dateValue", date);
    query.bindValue(":titleValue", title);
    query.bindValue(":linkValue", link);
    query.bindValue(":viewsValue", views);
    query.bindValue(":likesValue", likes);
    query.bindValue(":commentsValue", comments);
    query.bindValue(":keywordsValue", keywords);
    query.bindValue(":remarkValue", remark);
    query.bindValue(":id", id);
    query.exec();
}

void Database::deleteRow(QString id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM articles WHERE article_id = :id");
    query.bindValue(":id", id);
    query.exec();
}
