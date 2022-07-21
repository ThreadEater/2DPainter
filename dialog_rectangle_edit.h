#ifndef DIALOG_RECTANGLE_EDIT_H
#define DIALOG_RECTANGLE_EDIT_H

#include <QDialog>

namespace Ui {
class Dialog_rectangle_edit;
}

class Dialog_rectangle_edit : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_rectangle_edit(QWidget *parent = 0);
    ~Dialog_rectangle_edit();    
signals:
    void send(int,double,double,double,double);
    void send_cacu(int);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void show_num(double);
    void shou_c_s(double,double);

private:
    Ui::Dialog_rectangle_edit *ui;
};

#endif // DIALOG_RECTANGLE_EDIT_H
