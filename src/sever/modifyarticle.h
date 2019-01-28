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

private:
    Ui::ArticleData *ui;
};

#endif // MODIFYARTICLE_H
