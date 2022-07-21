#ifndef DIALOG_CIRCULAR_EDIT_H
#define DIALOG_CIRCULAR_EDIT_H

#include <QDialog>

namespace Ui {
class Dialog_circular_edit;
}

class Dialog_circular_edit : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_circular_edit(QWidget *parent = 0);
    ~Dialog_circular_edit();

private:
    Ui::Dialog_circular_edit *ui;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void show_num(double);
    void show_c_s(double,double);

signals:
    void send_cacu(int);
    void send_cir(int,double,double,double,double);
};

#endif // DIALOG_CIRCULAR_EDIT_H
