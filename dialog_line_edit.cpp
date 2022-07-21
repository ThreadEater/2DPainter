#include "dialog_line_edit.h"
#include "ui_dialog_line_edit.h"

Dialog_line_edit::Dialog_line_edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_line_edit)
{
    ui->setupUi(this);
}

Dialog_line_edit::~Dialog_line_edit()
{
    delete ui;
}
void Dialog_line_edit::handle( double number){

    QString S_number=QString::number(number);
    ui->label_2->setText(S_number);
}

void Dialog_line_edit::on_pushButton_clicked()
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
   emit send(dnumber,dx,dy,dx1,dy1);
}

void Dialog_line_edit::on_pushButton_2_clicked()
{
     QString number=ui->lineEdit_6->text();
     int dnumber=number.toInt();
     emit send_cacu(dnumber);
}
void Dialog_line_edit::show_lenth(double lenth){
    QString S_lenth=QString::number(lenth);
    ui->label_10->setText(S_lenth);
}
