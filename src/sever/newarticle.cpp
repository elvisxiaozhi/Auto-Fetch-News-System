#include "newarticle.h"
#include "ui_newarticle.h"
#include <QCloseEvent>
#include "database.h"

NewArticle::NewArticle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewArticle)
{
    ui->setupUi(this);
}

NewArticle::~NewArticle()
{
    delete ui;
}

void NewArticle::closeEvent(QCloseEvent *)
{
    deleteLater();
}

void NewArticle::on_pushButton_clicked()
{
    Database::writeData(ui->dateEdit->text(), ui->titleEdit->text(), ui->linkEdit->text(),
                        ui->viewsEdit->text().toInt(), ui->likesEdit->text().toInt(), ui->commentsEdit->text().toInt(),
                        ui->keywordsEdit->text(), ui->commentsEdit->text());

    emit dataWritten();
    close();
}
