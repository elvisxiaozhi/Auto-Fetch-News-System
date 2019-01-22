#include "articles.h"
#include "ui_articles.h"

Articles::Articles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Articles)
{
    ui->setupUi(this);
}

Articles::~Articles()
{
    delete ui;
}
