#include "dialog_circular_edit.h"
#include "ui_dialog_circular_edit.h"

Dialog_circular_edit::Dialog_circular_edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_circular_edit)
{
    ui->setupUi(this);
}

Dialog_circular_edit::~Dialog_circular_edit()
{
    delete ui;
}
void Dialog_circular_edit::show_num(double number ){
    QString S_number=QString::number(number);
    ui->label_7->setText(S_number);
}

void Dialog_circular_edit::on_pushButton_clicked()
{
    QString number=ui->lineEdit->text();
    QString x=ui->lineEdit_2->text();
    QString y=ui->lineEdit_3->text();
    QString x1=ui->lineEdit_4->text();
    QString y1=ui->lineEdit_5->text();
    int dnumber=number.toInt();
    double dx=x.toDouble();
    double dy=y.toDouble();
    double dx1=x1.toDouble();
    double dy1=y1.toDouble();
    emit send_cir(dnumber,dx,dy,dx1,dy1);
}

void Dialog_circular_edit::on_pushButton_2_clicked()
{
    QString number=ui->lineEdit_6->text();
    int dnumber=number.toInt();
    emit send_cacu(dnumber);
}
void Dialog_circular_edit::show_c_s(double c, double s){
    QString S_c=QString::number(c);
    QString S_s=QString::number(s);
    ui->label_11->setText(S_c);
    ui->label_12->setText(S_s);
}
