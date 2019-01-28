#ifndef MODIFYARTICLE_H
#define MODIFYARTICLE_H

#include <QWidget>

namespace Ui {
class ArticleData;
}

class ModifyArticle : public QWidget
{
    Q_OBJECT
public:
    explicit ModifyArticle(QWidget *parent = nullptr);
    ~ModifyArticle();

    QString id;
    void readData(QDate, QString, QString, int, int, int, QString, QString);

private:
    Ui::ArticleData *ui;

protected:
    void closeEvent(QCloseEvent *);

signals:
    void dataModified();

private slots:
    void on_pushButton_clicked();
};

#endif // MODIFYARTICLE_H
