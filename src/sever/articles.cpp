#include "articles.h"
#include "ui_articles.h"
#include "database.h"

Articles::Articles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Articles)
{
    ui->setupUi(this);

    addData();
}

Articles::~Articles()
{
    delete ui;
}

void Articles::addData()
{
    Database::readData();
    for (int i = 0; i < Database::titleList.size(); ++i) {
        ui->dateList->addItem(Database::dateList[i]);
        ui->titleList->addItem(Database::titleList[i]);
        ui->linkList->addItem(Database::linkList[i]);
        ui->keywordList->addItem(Database::keywordList[i]);
        ui->viewLike->addItem(Database::viewList[i]);
        ui->likeList->addItem(Database::likeList[i]);
        ui->commentList->addItem(Database::commentList[i]);
    }
}
