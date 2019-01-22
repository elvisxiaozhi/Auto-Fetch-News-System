#include "widget.h"
#include "ui_widget.h"
#include "ui_articles.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    db = new database(this);

    articles = new Articles(this);
    ui->tabWidget->addTab(articles, "Articles");

    for (int i = 0; i < db->titleList.size(); ++i) {
        articles->ui->titleList->addItem(db->titleList[i]);
    }
}

Widget::~Widget()
{
    delete ui;
}
