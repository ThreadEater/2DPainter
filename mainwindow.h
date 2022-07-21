#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"dialog_line.h"
#include"dialog_point.h"
#include"dialog_circular.h"
#include"dialog_rectangle.h"
#include"dialog_line_edit.h"
#include"dialog_rectangle_edit.h"
#include"dialog_circular_edit.h"
#include <QMainWindow>
#include <QMainWindow>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <QVector>
#include <QPoint>
#include <QToolBar>
#include <QAction>
#include <QPalette>
#include <QColor>
#include <QMenu>
#include <QFileDialog>
#include <QTextEdit>
#include <QDialog>
#include <QInputDialog>
#include <fstream>
#include<cmath>
using namespace std;
namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    void paintEvent(QPaintEvent *);//重写窗体重绘事件
    void mousePressEvent(QMouseEvent *);//重写鼠标按下事件
    void mouseReleaseEvent(QMouseEvent *);//重写鼠标释放事件
    void mouseMoveEvent(QMouseEvent *);//重写鼠标移动事件
    void contextMenuEvent(QContextMenuEvent *);//重写菜单事件
    void keyPressEvent(QKeyEvent *e); //重写按键事件
public:

private:
    bool _lpress;//左键按下标志
    int _drag;//拖拽标志
    int _drawType;//描绘类型
    int _colorType;//默认黑色
    int _styleType;//默认不间断
    int _widthType;//线条宽度
    QMenu *_Rmenu;//右键菜单
    int _openflag;//打开图片
    QPixmap _pixmap;//画布图片
    QTextEdit *_tEdit;//文本输入框
public:
    QVector<QVector<QPoint> > _lines;//线条集合(一条线条可包含多个线段)
    QVector<QRect> _rects;//矩形集合
    QVector<QRect> _ellipse;//椭圆集合
    QVector<QRect>  _line;//直线集合
    QVector<QString>  _text;//文字集合
    QVector<QPoint>  _tpoint;//文字位置集合
    QVector<int>  _shape;//图形类型集合，用于撤回功能
    QPoint _begin;//鼠标按下坐标、用于最后一个图形移动

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public://对话框：用于坐标输入的一些参数和图形对象的初始化
    //点
    Dialog_point *point=new Dialog_point;
    double p_x=0;
    double p_y=0;
    double p_a=0;
    double p_b=0;
    //直线
    Dialog_Line *line=new Dialog_Line;
    //矩形
    Dialog_rectangle *rectangle=new Dialog_rectangle;
    //（椭）圆
    Dialog_circular *circular=new Dialog_circular;
    //直线编辑界面显示
    Dialog_line_edit *line_edit = new Dialog_line_edit;
    Dialog_rectangle_edit *rec=new Dialog_rectangle_edit;
    Dialog_circular_edit *cir=new Dialog_circular_edit;

private slots://对话框：窗口显示的槽 绘图的槽函数
   void on_actionaa_triggered();//点输入窗口显示
   void drawpoint(double,double);//点绘制函数
   void on_Line_triggered();//线坐标输入窗口显示
   void drawline(double,double,double,double);//线绘制函数
   void on_actionaa_3_triggered();//矩形坐标输入窗口显示
   void drawrectangle(double,double,double,double);//矩形绘制函数
   void on_actionaa_4_triggered();//(椭)圆坐标输入窗口显示
   void drawcircular(double,double,double,double);//椭圆绘制函数
   //直线编辑函数
   void edit_line(int,double,double,double,double);
   //直线接受参数计算函数
   void cacu_line(int);
   //矩形编辑函数
   void edit_rec(int,double,double,double,double);
   //矩形接收参数计算函数
   void cacu_rec(int);
   //圆形矩形编辑函数
   void edit_cir(int, double, double, double, double);
   //圆形接收参数计算函数
   void cacu_cir(int);

private slots:
    void AddTexts();//添加文字
    void on_action_Open_triggered();

    void on_action_Rectangle_triggered();

    void on_action_Circle_triggered();

    void on_action_Pen_triggered();

    void on_action_Line_triggered();

    void on_action_Text_triggered();

    void on_action_Save_triggered();

    void on_action_LineWidth_triggered();

    void on_action_New_triggered();

    void on_action_BrushStyle_triggered();

    void on_action_Colour_triggered();

    void on_action_Saave_triggered();

    void on_actionSquareCap_triggered();

    void on_actionFlatCap_triggered();

    void on_actionRoundCap_triggered();

    void on_actionSolidLine_triggered();

    void on_actionDashLine_triggered();

    void on_actionDotline_triggered();

    void on_actionDashDotLine_triggered();

    void on_actionDashDotDotLine_triggered();

    void on_actionCustomDashLine_triggered();

    void on_actionBevelJoin_triggered();

    void on_actionMiterJoin_triggered();

    void on_actionRoundJoin_triggered();

    void on_actionOddEvenFill_triggered();

    void on_actionWindingFill_triggered();

    void on_actionPadSpread_triggered();

    void on_actionPepeatSpread_triggered();

    void on_actionReflectSpread_triggered();

    void on_actionPenPurple_triggered();

    void on_actionPenYellow_triggered();

    void on_actionPenGreen_triggered();

    void on_actionPenRed_triggered();

    void on_actionBrushPurple_triggered();

    void on_actionBrushYellow_triggered();

    void on_actionBrushGreen_triggered();

    void on_actionBrushRed_triggered();

    void on_actionaa_2_triggered();

    void on_action_import_triggered();

    void on_action_export_triggered();

    void on_actionBlack_triggered();

    void on_action_triggered();

    void on_pushButton_clicked();

    void on_action_2_triggered();

    void on_actionju_triggered();

    void on_actionQ_triggered();

private:
    Ui::MainWindow *ui;
signals:
    void send(double);//发送线条个数
    void send_lenth(double);//发送线条长度
    void send_rec_num(double);//发送矩形个数
    void send_c_s(double,double);//发送矩形周长面积
    void send_cir_num(double);//发送圆形个数
    void cir_send_c_s(double,double);//发送椭圆周长和面积
};
#endif // MAINWINDOW_H
