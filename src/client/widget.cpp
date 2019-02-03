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
    materials = new Materials(this);

    ui->tabWidget->addTab(articles, "Articles");
    ui->tabWidget->addTab(materials, "Materials");

    setWindowTitle("OAML Management System");
}

Widget::~Widget()
{
    delete ui;
}
