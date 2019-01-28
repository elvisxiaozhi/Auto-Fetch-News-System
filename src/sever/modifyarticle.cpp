#include "modifyarticle.h"
#include "ui_articledata.h"

ModifyArticle::ModifyArticle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ArticleData)
{
    ui->setupUi(this);
}

ModifyArticle::~ModifyArticle()
{
    delete ui;
}
