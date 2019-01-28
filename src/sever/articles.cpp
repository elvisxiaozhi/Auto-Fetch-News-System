#include "articles.h"
#include "ui_articles.h"
#include "database.h"
#include "newarticle.h"
#include "modifyarticle.h"

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

void Articles::on_deleteBtn_clicked()
{
    int row = ui->tableView->currentIndex().row();
    QString id = ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toString();
    Database::deleteRow(id);

    addData();
}

void Articles::on_addBtn_clicked()
{
    NewArticle *mWidget = new NewArticle();
    mWidget->show();
    connect(mWidget, &NewArticle::dataWritten, [this](){ addData(); });
}

void Articles::on_modifyBtn_clicked()
{
    ModifyArticle *mWidget = new ModifyArticle();
    mWidget->show();
}
