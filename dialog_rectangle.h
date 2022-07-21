#ifndef DIALOG_RECTANGLE_H
#define DIALOG_RECTANGLE_H

#include <QDialog>

namespace Ui {
class Dialog_rectangle;
}

class Dialog_rectangle : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_rectangle(QWidget *parent = 0);
    ~Dialog_rectangle();
signals:
    void send(double,double,double,double);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_rectangle *ui;
};

#endif // DIALOG_RECTANGLE_H
