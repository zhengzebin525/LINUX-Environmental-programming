#include "softkey.h"
#include "ui_softkey.h"

softkey::softkey(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::softkey)
{
    ui->setupUi(this);
}

softkey::~softkey()
{
    delete ui;
}
