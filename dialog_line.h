#ifndef DIALOG_LINE_H
#define DIALOG_LINE_H

#include <QDialog>

namespace Ui {
class Dialog_Line;
}

class Dialog_Line : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Line(QWidget *parent = 0);
    ~Dialog_Line();
signals:
    void send(double,double,double,double);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_Line *ui;
};

#endif // DIALOG_LINE_H
