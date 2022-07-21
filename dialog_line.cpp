#include "dialog_line.h"
#include "ui_dialog_line.h"
#include<QDebug>
Dialog_Line::Dialog_Line(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Line)
{
    ui->setupUi(this);
}

Dialog_Line::~Dialog_Line()
{
    delete ui;
}

void Dialog_Line::on_pushButton_clicked()
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
