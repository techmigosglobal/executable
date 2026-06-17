#include "swinfo_read.h"
#include "ui_swinfo_read.h"

SwInfo_read::SwInfo_read(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SwInfo_read)
{
    ui->setupUi(this);
}

SwInfo_read::~SwInfo_read()
{
    delete ui;
}
