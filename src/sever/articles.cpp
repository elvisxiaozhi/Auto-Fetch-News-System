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
    ui->tableView->setModel(Database::readData());
}
