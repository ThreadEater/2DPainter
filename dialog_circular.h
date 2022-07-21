#ifndef DIALOG_CIRCULAR_H
#define DIALOG_CIRCULAR_H

#include <QDialog>

namespace Ui {
class Dialog_circular;
}

class Dialog_circular : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_circular(QWidget *parent = 0);
    ~Dialog_circular();
signals:
    void send(double,double,double,double);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_circular *ui;
};

#endif // DIALOG_CIRCULAR_H
