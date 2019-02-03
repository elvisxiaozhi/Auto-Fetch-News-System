#ifndef MATERIALS_H
#define MATERIALS_H

#include <QWidget>

namespace Ui {
class Materials;
}

class Materials : public QWidget
{
    Q_OBJECT

public:
    explicit Materials(QWidget *parent = 0);
    ~Materials();

private:
    Ui::Materials *ui;
};

#endif // MATERIALS_H
