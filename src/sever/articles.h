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

private:
    Ui::Articles *ui;
    void addData();
    void deleteRow();
};

#endif // ARTICLES_H
