#ifndef DIALOG_LINE_EDIT_H
#define DIALOG_LINE_EDIT_H

#include <QDialog>

namespace Ui {
class Dialog_line_edit;
}

class Dialog_line_edit : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_line_edit(QWidget *parent = nullptr);
    ~Dialog_line_edit();

private:
    Ui::Dialog_line_edit *ui;
signals:
    void send(int,double,double,double,double);
    void send_cacu(int);
private slots:
    void handle(double);
    void show_lenth(double);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // DIALOG_LINE_EDIT_H
