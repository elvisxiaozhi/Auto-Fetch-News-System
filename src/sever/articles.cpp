#include "articles.h"
#include "ui_articles.h"
#include "database.h"

Articles::Articles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Articles)
{
    ui->setupUi(this);

    addData();

    connect(ui->deleteBtn, &QPushButton::clicked, this, &Articles::deleteRow);
}

Articles::~Articles()
{
    delete ui;
}

void Articles::addData()
{
    ui->tableView->setModel(Database::readData());
}

void Articles::deleteRow()
{
    int row = ui->tableView->currentIndex().row();
    QString id = ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toString();
    qDebug() << id;
    Database::deleteRow(id);

    addData();
}
