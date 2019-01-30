#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "database.h"
#include "articles.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    Articles *articles;
    Database *db;
};

#endif // WIDGET_H
