#include "modifyarticle.h"
#include "ui_articledata.h"
#include "database.h"
#include <QCloseEvent>

ModifyArticle::ModifyArticle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ArticleData)
{
    ui->setupUi(this);

    setWindowTitle("Modify Data");
}

ModifyArticle::~ModifyArticle()
{
    delete ui;
}

void ModifyArticle::readData(QDate date, QString title, QString link, int views, int likes, int comments, QString keywords, QString remark)
{
    ui->dateEdit->setDate(date);
    ui->titleEdit->setText(title);
    ui->linkEdit->setText(link);
    ui->viewsEdit->setText(QString::number(views));
    ui->likesEdit->setText(QString::number(likes));
    ui->commentsEdit->setText(QString::number(comments));
    ui->keywordsEdit->setText(keywords);
    ui->remarkEdit->setText(remark);
}

void ModifyArticle::closeEvent(QCloseEvent *)
{
    deleteLater();
}

void ModifyArticle::on_pushButton_clicked()
{
    Database::modifyData(id, ui->dateEdit->date().toString("yyyy-MM-dd"), ui->titleEdit->text(), ui->linkEdit->text(),
                         ui->viewsEdit->text().toInt(), ui->likesEdit->text().toInt(), ui->commentsEdit->text().toInt(),
                         ui->keywordsEdit->text(), ui->remarkEdit->text());

    emit dataModified();
    close();
}
