#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "database.h"
#include "articles.h"
#include "materials.h"

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
    Database *db;
    Articles *articles;
    Materials *materials;
};

#endif // WIDGET_H
