#include "database.h"
#include <QSqlError>
#include <QSqlQuery>

QStringList Database::titleList;
QStringList Database::dateList;
QStringList Database::linkList;
QStringList Database::keywordList;
QStringList Database::viewList;
QStringList Database::likeList;
QStringList Database::commentList;

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
    query.exec("SELECT *FROM articles");
    while (query.next()) {
        dateList += query.value(0).toString();
        titleList += query.value(1).toString();
        linkList += query.value(2).toString();
        keywordList += query.value(3).toString();
        viewList += query.value(4).toString();
        likeList += query.value(5).toString();
        commentList += query.value(6).toString();
    }
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
