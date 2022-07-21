#include "dialog_point.h"
#include "ui_dialog_point.h"

Dialog_point::Dialog_point(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_point)
{
    ui->setupUi(this);
}

Dialog_point::~Dialog_point()
{
    delete ui;
}

void Dialog_point::on_pushButton_clicked()
{
    QString x=ui->lineEdit->text();
    QString y=ui->lineEdit_2->text();
    double dx=x.toDouble();
    double dy=y.toDouble();
    emit send(dx,dy);
}
