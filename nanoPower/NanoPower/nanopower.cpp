#include "nanopower.h"
#include "ui_nanopower.h"

NanoPower::NanoPower(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NanoPower)
{
    ui->setupUi(this);
}

NanoPower::~NanoPower()
{
    delete ui;
}
