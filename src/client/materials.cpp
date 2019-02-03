#include "materials.h"
#include "ui_materials.h"

Materials::Materials(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Materials)
{
    ui->setupUi(this);
}

Materials::~Materials()
{
    delete ui;
}
