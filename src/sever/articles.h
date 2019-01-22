#ifndef ARTICLES_H
#define ARTICLES_H

#include <QWidget>

namespace Ui {
class Articles;
}

class Articles : public QWidget
{
    Q_OBJECT

public:
    explicit Articles(QWidget *parent = 0);
    ~Articles();

    Ui::Articles *ui;

private:
};

#endif // ARTICLES_H
