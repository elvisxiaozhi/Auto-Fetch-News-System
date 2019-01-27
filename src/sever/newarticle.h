#ifndef NEWARTICLE_H
#define NEWARTICLE_H

#include <QWidget>

namespace Ui {
class NewArticle;
}

class NewArticle : public QWidget
{
    Q_OBJECT

public:
    explicit NewArticle(QWidget *parent = 0);
    ~NewArticle();

private:
    Ui::NewArticle *ui;

protected:
    void closeEvent(QCloseEvent *);

signals:
    void dataWritten();

private slots:
    void on_pushButton_clicked();
};

#endif // NEWARTICLE_H
