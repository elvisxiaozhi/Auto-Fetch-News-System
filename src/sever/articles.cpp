#include "articles.h"
#include "ui_articles.h"
#include "database.h"

Articles::Articles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Articles)
{
    ui->setupUi(this);

    Database::readData();
    for (int i = 0; i < Database::titleList.size(); ++i) {
        ui->titleList->addItem(Database::titleList[i]);
    }
}

Articles::~Articles()
{
    delete ui;
}
