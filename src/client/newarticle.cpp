#include "newarticle.h"
#include "ui_articledata.h"
#include <QCloseEvent>
#include "database.h"

NewArticle::NewArticle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ArticleData)
{
    ui->setupUi(this);

    ui->dateEdit->setDate(QDate::currentDate());

    setWindowTitle("Add Data");
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
    Database::writeData(ui->dateEdit->date().toString("yyyy-MM-dd"), ui->titleEdit->text(), ui->linkEdit->text(),
                        ui->viewsEdit->text().toInt(), ui->likesEdit->text().toInt(), ui->commentsEdit->text().toInt(),
                        ui->keywordsEdit->text(), ui->remarkEdit->text());

    emit dataWritten();
    close();
}
