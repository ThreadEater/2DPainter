#include "dialog_rectangle.h"
#include "ui_dialog_rectangle.h"

Dialog_rectangle::Dialog_rectangle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_rectangle)
{
    ui->setupUi(this);
}

Dialog_rectangle::~Dialog_rectangle()
{
    delete ui;
}

void Dialog_rectangle::on_pushButton_clicked()
{
    QString x=ui->lineEdit->text();
    QString y=ui->lineEdit_2->text();
    QString x1=ui->lineEdit_3->text();
    QString y1=ui->lineEdit_4->text();
    double dx=x.toDouble();
    double dy=y.toDouble();
    double dx1=x1.toDouble();
    double dy1=y1.toDouble();
    emit send(dx,dy,dx1,dy1);
}
