#ifndef DIALOG_POINT_H
#define DIALOG_POINT_H

#include <QDialog>

namespace Ui {
class Dialog_point;
}

class Dialog_point : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_point(QWidget *parent = 0);
    ~Dialog_point();
signals:
    void send(double,double);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_point *ui;
};

#endif // DIALOG_POINT_H
