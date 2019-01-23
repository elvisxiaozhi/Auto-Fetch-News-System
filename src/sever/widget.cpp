#include "widget.h"
#include "ui_widget.h"
#include "ui_articles.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    db = new Database(this);

    articles = new Articles(this);
    ui->tabWidget->addTab(articles, "Articles");
}

Widget::~Widget()
{
    delete ui;
}
