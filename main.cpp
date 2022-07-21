#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pix(":/new/prefix1/images/start.gif");
    QSplashScreen spl(pix);
    spl.show();
    a.processEvents();
    MainWindow w;
    w.setWindowIcon(QIcon(":/new/prefix1/images/1.png"));
    w.setWindowTitle("2DPainter");
    w.show();
    spl.finish(&w);
    return a.exec();
}
