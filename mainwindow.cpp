#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <QDebug>
#include<dialog_point.h>
#include<dialog_line.h>
#include<dialog_rectangle.h>
#include<dialog_circular.h>
#include<fstream>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    _lpress = false;//初始鼠标左键未按下
    _drawType = 0;//初始为什么都不画
    _colorType=0;//默认为黑色
    _styleType=0;//默认不间断
    _widthType=1;//默认为一
    _drag = 0;//默认非拖拽模式
    _begin = pos();//拖拽的参考坐标，方便计算位移
    _openflag = 0;//初始不打开图片
    _tEdit = new QTextEdit(this);//初始化文本输入框
    _tEdit->hide();//隐藏
    this->setGeometry(350,200,600,400);//设置窗体大小、位置
    setMouseTracking(true);//开启鼠标实时追踪，监听鼠标移动事件，默认只有按下时才监听
    ui->setupUi(this);
    connect(_tEdit, SIGNAL(textChanged()), this, SLOT(AddTexts()));

    point->setWindowIcon(QIcon(":/new/prefix1/images/paint.png"));
    rectangle->setWindowIcon(QIcon(":/new/prefix1/images/paint.png"));
    circular->setWindowIcon(QIcon(":/new/prefix1/images/paint.png"));
    line->setWindowIcon(QIcon(":/new/prefix1/images/paint.png"));

    point->setWindowTitle("坐标长度精准绘制");
    rectangle->setWindowTitle("坐标长度精准绘制");
    circular->setWindowTitle("坐标长度精准绘制");
    line->setWindowTitle("坐标长度基准绘制");

    line_edit->setWindowIcon(QIcon(":/new/prefix1/images/edit.png"));
    rec->setWindowIcon(QIcon(":/new/prefix1/images/edit.png"));
    cir->setWindowIcon(QIcon(":/new/prefix1/images/edit.png"));

    line_edit->setWindowTitle("编辑与分析");
    rec->setWindowTitle("编辑与分析");
    cir->setWindowTitle("编辑与分析");
    //w.setWindowTitle("2DPainter");






    //对话框的数据传输
    connect(point,SIGNAL(send(double,double)),this,SLOT(drawpoint(double,double)));
    connect(rectangle,SIGNAL(send(double,double,double,double)),this,SLOT(drawrectangle(double,double,double,double)));
    connect(line,SIGNAL(send(double,double,double,double)),this,SLOT(drawline(double,double,double,double)));
    connect(circular,SIGNAL(send(double,double,double,double)),this,SLOT(drawcircular(double,double,double,double)));
    //对话框数据修改
    connect(this,SIGNAL(send(double)),line_edit,SLOT(handle(double)));
    connect(line_edit,SIGNAL(send(int,double,double,double,double)),this,SLOT(edit_line(int,double,double,double,double)));
    connect(this,SIGNAL(send_rec_num(double)),rec,SLOT(show_num(double)));
    connect(rec,SIGNAL(send(int,double,double,double,double)),this,SLOT(edit_rec(int,double,double,double,double)));
    connect(this,SIGNAL(send_cir_num(double)),cir,SLOT(show_num(double)));
    connect(cir,SIGNAL(send_cir(int,double,double,double,double)),this,SLOT(edit_cir(int, double, double, double, double)));
    //对话框分析
    connect(line_edit,SIGNAL(send_cacu(int)),this,SLOT(cacu_line(int)));
    connect(this,SIGNAL(send_lenth(double)),line_edit,SLOT(show_lenth(double)));
    connect(rec,SIGNAL(send_cacu(int)),this,SLOT(cacu_rec(int)));
    connect(this,SIGNAL(send_c_s(double,double)),rec,SLOT(shou_c_s(double,double)));
    connect(cir,SIGNAL(send_cacu(int)),this,SLOT(cacu_cir(int)));
    connect(this,SIGNAL(cir_send_c_s(double,double)),cir,SLOT(show_c_s(double,double)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    if(_openflag == 0)//不是打开图片的，每一次新建一个空白的画布
    {
        _pixmap = QPixmap(size());//新建pixmap
        _pixmap.fill(Qt::white);//背景色填充为白色
    }
    QPixmap pix = _pixmap;//以_pixmap作为画布
    QPainter p(&pix);//将_pixmap作为画布
    unsigned int i1=0,i2=0,i3=0,i4=0,i5=0;//各种图形的索引

    for(int c = 0;c<_shape.size();++c)//控制用户当前所绘图形总数
    {
        if(_shape.at(c) == 1)//线条
        {
            const QVector<QPoint>& line = _lines.at(i1++);//取出一条线条
            for(int j=0; j<line.size()-1; ++j)//将线条的所有线段描绘出
            {
                if(_colorType==1){//满足颜色

                    QPen pen(QColor(255,0,0));
                    if(_styleType==1){//满足颜色且满足线条形状（继承颜色if )
                        pen.setStyle(Qt::DashLine);
                        if(_widthType==2){//满足颜色且满足线条形状且满足线条宽度（三个条件都满足）(继承颜色if=>继承形状if)
                            pen.setWidth(2);
                        }
                    }
                    if(_widthType==2){//满足颜色且满足线条宽度（只满足两个）(承颜色if）
                        pen.setWidth(2);
                    }
                    p.setPen(pen);

                }
                else if(_colorType==2){
                    QPen pen(QColor(0,128,0));
                    if(_styleType==1){
                        pen.setStyle(Qt::DashLine);
                        if(_widthType==2){
                            pen.setWidth(2);
                        }
                    }
                    if(_widthType==2){
                        pen.setWidth(2);
                    }
                    p.setPen(pen);
                }
                else if(_colorType==3){
                    QPen pen(QColor(255,255,0));
                    if(_styleType==1){
                        pen.setStyle(Qt::DashLine);
                        if(_widthType==2){
                            pen.setWidth(2);
                        }
                    }
                    if(_widthType==2){
                        pen.setWidth(2);
                    }
                    p.setPen(pen);
                }
                else if(_colorType==4){
                    QPen pen(QColor(128,0,128));
                    if(_styleType==1){
                        pen.setStyle(Qt::DashLine);
                        if(_widthType==2){
                            pen.setWidth(2);
                        }
                    }
                    if (_widthType==2){
                        pen.setWidth(2);
                    }
                    p.setPen(pen);
                }
                else{
                    if(_styleType==1){//不满足线条颜色 满足线条形状
                        QPen pen;
                        pen.setStyle(Qt::DashLine);
                        if(_widthType==2){//不满足线条颜色 满足线条形状 满足线条宽度（继承了形状if)
                            pen.setWidth(2);
                        }
                        p.setPen(pen);
                    }
                    else{//不满足线条颜色 不满足线条形状 满足线条宽度（只满足一个）
                        if(_widthType==2){
                            QPen pen;
                            pen.setWidth(2);
                            p.setPen(pen);
                        }
                    }
                }
                p.drawLine(line.at(j), line.at(j+1));

            }
        }
        else if(_shape.at(c) == 2)//矩形
        {
            if(_colorType==1){//满足颜色

                QPen pen(QColor(255,0,0));
                if(_styleType==1){//满足颜色且满足线条形状（继承颜色if )
                    pen.setStyle(Qt::DashLine);
                    if(_widthType==2){//满足颜色且满足线条形状且满足线条宽度（三个条件都满足）(继承颜色if=>继承形状if)
                        pen.setWidth(2);
                    }
                }
                if(_widthType==2){//满足颜色且满足线条宽度（只满足两个）(承颜色if）
                    pen.setWidth(2);
                }
                p.setPen(pen);

            }
            else if(_colorType==2){
                QPen pen(QColor(0,128,0));
                if(_styleType==1){
                    pen.setStyle(Qt::DashLine);
                    if(_widthType==2){
                        pen.setWidth(2);
                    }
                }
                if(_widthType==2){
                    pen.setWidth(2);
                }
                p.setPen(pen);
            }
            else if(_colorType==3){
                QPen pen(QColor(255,255,0));
                if(_styleType==1){
                    pen.setStyle(Qt::DashLine);
                    if(_widthType==2){
                        pen.setWidth(2);
                    }
                }
                if(_widthType==2){
                    pen.setWidth(2);
                }
                p.setPen(pen);
            }
            else if(_colorType==4){
                QPen pen(QColor(128,0,128));
                if(_styleType==1){
                    pen.setStyle(Qt::DashLine);
                    if(_widthType==2){
                        pen.setWidth(2);
                    }
                }
                if (_widthType==2){
                    pen.setWidth(2);
                }
                p.setPen(pen);
            }
            else{
                if(_styleType==1){//不满足线条颜色 满足线条形状
                    QPen pen;
                    pen.setStyle(Qt::DashLine);
                    if(_widthType==2){//不满足线条颜色 满足线条形状 满足线条宽度（继承了形状if)
                        pen.setWidth(2);
                    }
                    p.setPen(pen);
                }
                else{//不满足线条颜色 不满足线条形状 满足线条宽度（只满足一个）
                    if(_widthType==2){
                        QPen pen;
                        pen.setWidth(2);
                        p.setPen(pen);
                    }
                }
            }
            p.drawRect(_rects.at(i2++));
        }
        else if(_shape.at(c) == 3)//椭圆
        {
            if(_colorType==1){//满足颜色

                QPen pen(QColor(255,0,0));
                if(_styleType==1){//满足颜色且满足线条形状（继承颜色if )
                    pen.setStyle(Qt::DashLine);
                    if(_widthType==2){//满足颜色且满足线条形状且满足线条宽度（三个条件都满足）(继承颜色if=>继承形状if)
                        pen.setWidth(2);
                    }
                }
                if(_widthType==2){//满足颜色且满足线条宽度（只满足两个）(承颜色if）
                    pen.setWidth(2);
                }
                p.setPen(pen);

            }
            else if(_colorType==2){
                QPen pen(QColor(0,128,0));
                if(_styleType==1){
                    pen.setStyle(Qt::DashLine);
                    if(_widthType==2){
                        pen.setWidth(2);
                    }
                }
                if(_widthType==2){
                    pen.setWidth(2);
                }
                p.setPen(pen);
            }
            else if(_colorType==3){
                QPen pen(QColor(255,255,0));
                if(_styleType==1){
                    pen.setStyle(Qt::DashLine);
                    if(_widthType==2){
                        pen.setWidth(2);
                    }
                }
                if(_widthType==2){
                    pen.setWidth(2);
                }
                p.setPen(pen);
            }
            else if(_colorType==4){
                QPen pen(QColor(128,0,128));
                if(_styleType==1){
                    pen.setStyle(Qt::DashLine);
                    if(_widthType==2){
                        pen.setWidth(2);
                    }
                }
                if (_widthType==2){
                    pen.setWidth(2);
                }
                p.setPen(pen);
            }
            else{
                if(_styleType==1){//不满足线条颜色 满足线条形状
                    QPen pen;
                    pen.setStyle(Qt::DashLine);
                    if(_widthType==2){//不满足线条颜色 满足线条形状 满足线条宽度（继承了形状if)
                        pen.setWidth(2);
                    }
                    p.setPen(pen);
                }
                else{//不满足线条颜色 不满足线条形状 满足线条宽度（只满足一个）
                    if(_widthType==2){
                        QPen pen;
                        pen.setWidth(2);
                        p.setPen(pen);
                    }
                }
            }
            p.drawEllipse(_ellipse.at(i3++));
        }
        else if(_shape.at(c) == 4)//直线
        {
            if(_colorType==1){//满足颜色

                QPen pen(QColor(255,0,0));
                if(_styleType==1){//满足颜色且满足线条形状（继承颜色if )
                    pen.setStyle(Qt::DashLine);
                    if(_widthType==2){//满足颜色且满足线条形状且满足线条宽度（三个条件都满足）(继承颜色if=>继承形状if)
                        pen.setWidth(2);
                    }
                }
                if(_widthType==2){//满足颜色且满足线条宽度（只满足两个）(承颜色if）
                    pen.setWidth(2);
                }
                p.setPen(pen);

            }
            else if(_colorType==2){
                QPen pen(QColor(0,128,0));
                if(_styleType==1){
                    pen.setStyle(Qt::DashLine);
                    if(_widthType==2){
                        pen.setWidth(2);
                    }
                }
                if(_widthType==2){
                    pen.setWidth(2);
                }
                p.setPen(pen);
            }
            else if(_colorType==3){
                QPen pen(QColor(255,255,0));
                if(_styleType==1){
                    pen.setStyle(Qt::DashLine);
                    if(_widthType==2){
                        pen.setWidth(2);
                    }
                }
                if(_widthType==2){
                    pen.setWidth(2);
                }
                p.setPen(pen);
            }
            else if(_colorType==4){
                QPen pen(QColor(128,0,128));
                if(_styleType==1){
                    pen.setStyle(Qt::DashLine);
                    if(_widthType==2){
                        pen.setWidth(2);
                    }
                }
                if (_widthType==2){
                    pen.setWidth(2);
                }
                p.setPen(pen);
            }
            else{
                if(_styleType==1){//不满足线条颜色 满足线条形状
                    QPen pen;
                    pen.setStyle(Qt::DashLine);
                    if(_widthType==2){//不满足线条颜色 满足线条形状 满足线条宽度（继承了形状if)
                        pen.setWidth(2);
                    }
                    p.setPen(pen);
                }
                else{//不满足线条颜色 不满足线条形状 满足线条宽度（只满足一个）
                    if(_widthType==2){
                        QPen pen;
                        pen.setWidth(2);
                        p.setPen(pen);
                    }
                }
            }
            p.drawLine(_line.at(i4).topLeft(),_line.at(i4).bottomRight());
            i4++;
        }
        else if(_shape.at(c) == 5)//文本
        {
            if(_colorType==1){//满足颜色

                QPen pen(QColor(255,0,0));
                if(_styleType==1){//满足颜色且满足线条形状（继承颜色if )
                    pen.setStyle(Qt::DashLine);
                    if(_widthType==2){//满足颜色且满足线条形状且满足线条宽度（三个条件都满足）(继承颜色if=>继承形状if)
                        pen.setWidth(2);
                    }
                }
                if(_widthType==2){//满足颜色且满足线条宽度（只满足两个）(承颜色if）
                    pen.setWidth(2);
                }
                p.setPen(pen);

            }
            else if(_colorType==2){
                QPen pen(QColor(0,128,0));
                if(_styleType==1){
                    pen.setStyle(Qt::DashLine);
                    if(_widthType==2){
                        pen.setWidth(2);
                    }
                }
                if(_widthType==2){
                    pen.setWidth(2);
                }
                p.setPen(pen);
            }
            else if(_colorType==3){
                QPen pen(QColor(255,255,0));
                if(_styleType==1){
                    pen.setStyle(Qt::DashLine);
                    if(_widthType==2){
                        pen.setWidth(2);
                    }
                }
                if(_widthType==2){
                    pen.setWidth(2);
                }
                p.setPen(pen);
            }
            else if(_colorType==4){
                QPen pen(QColor(128,0,128));
                if(_styleType==1){
                    pen.setStyle(Qt::DashLine);
                    if(_widthType==2){
                        pen.setWidth(2);
                    }
                }
                if (_widthType==2){
                    pen.setWidth(2);
                }
                p.setPen(pen);
            }
            else{
                if(_styleType==1){//不满足线条颜色 满足线条形状
                    QPen pen;
                    pen.setStyle(Qt::DashLine);
                    if(_widthType==2){//不满足线条颜色 满足线条形状 满足线条宽度（继承了形状if)
                        pen.setWidth(2);
                    }
                    p.setPen(pen);
                }
                else{//不满足线条颜色 不满足线条形状 满足线条宽度（只满足一个）
                    if(_widthType==2){
                        QPen pen;
                        pen.setWidth(2);
                        p.setPen(pen);
                    }
                }
            }
            p.drawText(_tpoint.at(i5),_text.at(i5));
            i5++;
        }

    }
    p.drawEllipse(QRect(p_x,p_y,p_a,p_b));
    p.end();
    p.begin(this);//将当前窗体作为画布
    p.drawPixmap(0,0,pix);//将pixmap                            hv画到窗体
}



void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)//当鼠标左键按下
    {
        if(_drawType == 1)//线条(铅笔)
        {
            _lpress = true;//左键按下标志
            QVector<QPoint> line;//鼠标按下，新的线条开始
            _lines.append(line);//将新线条添加到线条集合
            QVector<QPoint>& lastLine = _lines.last();//拿到新线条
            lastLine.append(e->pos());//记录鼠标的坐标(新线条的开始坐标)
            _shape.append(1);
        }
        else if(_drawType == 2)//矩形
        {
            _lpress = true;//左键按下标志
            if(!_drag)//非拖拽模式
            {
                QRect rect;//鼠标按下，矩形开始
                _rects.append(rect);//将新矩形添加到矩形集合
                QRect& lastRect = _rects.last();//拿到新矩形
                lastRect.setTopLeft(e->pos());//记录鼠标的坐标(新矩形的左上角坐标)
                 _shape.append(2);
            }
            else if(_rects.last().contains(e->pos()))//拖拽模式、如果在矩形内按下
            {
                _begin = e->pos();//记录拖拽开始的坐标位置,方便计算位移

            }

        }
        else if(_drawType == 3)//椭圆
        {
            _lpress = true;//左键按下标志
            if(!_drag)//非拖拽模式
            {
                QRect rect;//鼠标按下，椭圆开始
                _ellipse.append(rect);//将新椭圆添加到椭圆集合
                QRect& lastEllipse = _ellipse.last();//拿到新椭圆
                lastEllipse.setTopLeft(e->pos());//记录鼠标的坐标(新椭圆的左上角坐标)
                 _shape.append(3);
            }
            else if(_ellipse.last().contains(e->pos()))//如果在椭圆内按下
            {
                _begin = e->pos();//记录拖拽开始的坐标位置

            }
        }
        else if(_drawType == 4)//直线
        {
            _lpress = true;//左键按下标志
            QRect rect;//鼠标按下，直线一端开始
            _line.append(rect);//将新直线添加到直线集合
            QRect& lastLine = _line.last();//拿到新直线
            lastLine.setTopLeft(e->pos());//记录鼠标的坐标(新直线开始一端坐标)
            _shape.append(4);
        }
        else if(_drawType == 5)//文字
        {
            update();//触发窗体重绘
            QPoint p;//鼠标按下，文字开始
            _tpoint.append(p);//将文字坐标添加到文字位置集合
            QPoint& lastp = _tpoint.last();//拿到新文字
            lastp = e->pos();//记录鼠标的坐标
            _tEdit->setGeometry(lastp.x()-6,lastp.y()-17,90,90);//设置文本框的位置、大小

            _tEdit->show();//显示文本输入框
            _text.append("");//添加文本到文本集合
            _tEdit->clear();//因为全局只有一个，所以使用之前要清空
            _shape.append(5);
        }

    }
}

void MainWindow::AddTexts()//当输入框文本改变时调用
{
    QString& last = _text.last();//拿到最后一个文本
    last = _tEdit->toPlainText();//将输入框文本作为文本
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(_drag && ((_drawType == 2 && _rects.last().contains(e->pos()))
            || (_drawType == 3 && _ellipse.last().contains(e->pos()) )))
    {
        setCursor(Qt::SizeAllCursor);//拖拽模式下，并且在拖拽图形中，将光标形状改为十字
    }
    else
    {
        setCursor(Qt::ArrowCursor);//恢复原始光标形状
        _drag = 0;
    }

    if(_lpress)
    {
        if(_drawType == 1)//铅笔画线
        {
            if(_lines.size()<=0) return;//线条集合为空，不画线
            QVector<QPoint>& lastLine = _lines.last();//最后添加的线条，就是最新画的
            lastLine.append(e->pos());//记录鼠标的坐标(线条的轨迹)
            update();//触发窗体重绘
        }
        else if(_drawType == 2)
        {
            if(_drag == 0)//非拖拽
            {
                QRect& lastRect = _rects.last();//拿到新矩形
                lastRect.setBottomRight(e->pos());//更新矩形的右下角坐标
            }
            else//拖拽模式
            {
                QRect& lastRect = _rects.last();//拿到最后添加的矩形
                if(lastRect.contains(e->pos()))//在矩形的内部
                {
                    int dx = e->pos().x()-_begin.x();//横向移动x
                    int dy = e->pos().y()-_begin.y();//纵向移动y
                    lastRect = lastRect.adjusted(dx,dy,dx,dy);//更新矩形的位置
                    _begin = e->pos();//刷新拖拽点起始坐标
                }

            }
            update();//触发窗体重绘

        }
        else if(_drawType == 3)
        {
            if(_drag == 0)//非拖拽
            {
                QRect& lastEllipse = _ellipse.last();//拿到新椭圆
                lastEllipse.setBottomRight(e->pos());//更新椭圆的右下角坐标)

            }
            else//拖拽
            {
                QRect& lastEllipse = _ellipse.last();//拿到最后添加的矩形
                if(lastEllipse.contains(e->pos()))//在椭圆内部
                {
                    int dx = e->pos().x()-_begin.x();//横向移动x
                    int dy = e->pos().y()-_begin.y();//纵向移动y
                    lastEllipse = lastEllipse.adjusted(dx,dy,dx,dy);
                    _begin = e->pos();//刷新拖拽点起始坐标
                }

            }
            update();//触发窗体重绘
        }
        else if(_drawType == 4)
        {
            QRect& lastLine = _line.last();//拿到新直线
            lastLine.setBottomRight(e->pos());//更新直线另一端)
            update();//触发窗体重绘
        }
    }


}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    if(_lpress)
    {
        if(_drawType == 1)
        {
            QVector<QPoint>& lastLine = _lines.last();//最后添加的线条，就是最新画的
            lastLine.append(e->pos());//记录线条的结束坐标
            _lpress = false;//标志左键释放
        }
        else if(_drawType == 2)
        {
            QRect& lastRect = _rects.last();//拿到新矩形
            if(!_drag)
            {
                lastRect.setBottomRight(e->pos());//不是拖拽时，更新矩形的右下角坐标)
                //刚画完矩形，将光标设置到新矩形的中心位置，并进入拖拽模式
                this->cursor().setPos(this->cursor().pos().x()-lastRect.width()/2,this->cursor().pos().y()-lastRect.height()/2);
                _drag = 1;

            }
            _lpress = false;

        }
        else if(_drawType == 3)
        {
            QRect& lastEllipse = _ellipse.last();//拿到新椭圆
            if(!_drag)
            {
                lastEllipse.setBottomRight(e->pos());//不是拖拽时，更新椭圆的右下角坐标)
                //刚画完椭圆，将光标设置到新椭圆的中心位置，并进入拖拽模式
                this->cursor().setPos(this->cursor().pos().x()-lastEllipse.width()/2,this->cursor().pos().y()-lastEllipse.height()/2);
                _drag = 1;

            }
            _lpress = false;
        }
        else if(_drawType == 4)
        {
            QRect& lastLine = _line.last();//拿到新矩形
            lastLine.setBottomRight(e->pos());//更新矩形的右下角坐标)
            _lpress = false;

        }
    }
}

void MainWindow::on_action_Open_triggered()
{
    //弹出文件打开对话框
    QString picPath = QFileDialog::getOpenFileName(this,tr("打开"),"","Image Files(*.jpg *.png)");
    if(!picPath.isEmpty())//用户选择了文件
    {
        QPixmap pix;
        pix.load(picPath);//加载图片
        QPainter p(&_pixmap);
        p.drawPixmap(0,60,pix);//添加工具栏的空间
        _openflag = 1;//设置文件打开标志
        update();//触发窗体重绘，将图片画到窗体
    }
}

void MainWindow::on_action_Rectangle_triggered()
{
    _drawType = 2;//矩形
    _tEdit->hide();
}

void MainWindow::on_action_Circle_triggered()
{
    _drawType = 3;//椭圆
    _tEdit->hide();
}

void MainWindow::on_action_Pen_triggered()
{
    _drawType = 1;//铅笔
    _tEdit->hide();//文本框隐藏
}

void MainWindow::on_action_Line_triggered()
{
    _drawType = 4;//直线
    _tEdit->hide();
}

void MainWindow::on_action_Text_triggered()
{
    _drawType = 5;//文字
}

void MainWindow::on_action_Save_triggered()
{
    //弹出文件保存对话框
    QString fileName = QFileDialog::getSaveFileName(this, tr("保存"), "new.jpg", "Image (*.jpg *.png *.bmp)");

    if (fileName.length() > 0)
    {
        _tEdit->hide();//防止文本输入框显示时，将文本框保存到图片
        QPixmap pixmap(size());//新建窗体大小的pixmap
        QPainter painter(&pixmap);//将pixmap作为画布
        painter.fillRect(QRect(0, 0, size().width(), size().height()), Qt::white);//设置绘画区域、画布颜色
        this->render(&painter);//将窗体渲染到painter，再由painter画到画布
        pixmap.copy(QRect(0,60,size().width(),size().height()-60)).save(fileName);//不包含工具栏
    }
}
void MainWindow::on_action_LineWidth_triggered()
{
    _widthType=2;
}

void MainWindow::on_action_New_triggered()
{

}

void MainWindow::on_action_BrushStyle_triggered()
{

}

void MainWindow::on_action_Colour_triggered()
{

}

void MainWindow::on_action_Saave_triggered()
{

}

void MainWindow::on_actionSquareCap_triggered()
{

}

void MainWindow::on_actionFlatCap_triggered()
{

}

void MainWindow::on_actionRoundCap_triggered()
{

}

void MainWindow::on_actionSolidLine_triggered()
{

}

void MainWindow::on_actionDashLine_triggered()
{

}

void MainWindow::on_actionDotline_triggered()
{

}

void MainWindow::on_actionDashDotLine_triggered()
{

}

void MainWindow::on_actionDashDotDotLine_triggered()
{

}

void MainWindow::on_actionCustomDashLine_triggered()
{

}

void MainWindow::on_actionBevelJoin_triggered()
{

}

void MainWindow::on_actionMiterJoin_triggered()
{

}

void MainWindow::on_actionRoundJoin_triggered()
{

}

void MainWindow::on_actionOddEvenFill_triggered()
{

}

void MainWindow::on_actionWindingFill_triggered()
{

}

void MainWindow::on_actionPadSpread_triggered()
{

}

void MainWindow::on_actionPepeatSpread_triggered()
{

}

void MainWindow::on_actionReflectSpread_triggered()
{

}

void MainWindow::on_actionPenPurple_triggered()
{
    _colorType=4;
}

void MainWindow::on_actionPenYellow_triggered()
{
    _colorType=3;
}

void MainWindow::on_actionPenGreen_triggered()
{
    _colorType=2;
}

void MainWindow::on_actionPenRed_triggered()
{
    _colorType=1;
}

void MainWindow::on_actionBrushPurple_triggered()
{

}

void MainWindow::on_actionBrushYellow_triggered()
{

}

void MainWindow::on_actionBrushGreen_triggered()
{

}

void MainWindow::on_actionBrushRed_triggered()
{

}

void MainWindow::keyPressEvent(QKeyEvent *e) //按键事件
{
     //Ctrl+Z撤销
     if (e->key() == Qt::Key_Z && e->modifiers() == Qt::ControlModifier)
     {
         if(_shape.size()>0)
         {
             switch(_shape.last())
             {
                 case 1: _lines.pop_back();
                         break;
                 case 2: _rects.pop_back();
                         break;
                 case 3: _ellipse.pop_back();
                         break;
                 case 4: _line.pop_back();
                         break;
             }
             _shape.pop_back();
             _drag = 0;//设置为非拖拽模式
             update();
         }
     }
     else if (e->key() == Qt::Key_S && e->modifiers() == Qt::ControlModifier)//保存
     {
        on_action_Save_triggered();
     }
}

void MainWindow::contextMenuEvent(QContextMenuEvent *)  //右键菜单事件
{
    _Rmenu->exec(cursor().pos());//在光标位置弹出菜单
}

void MainWindow::on_actionaa_2_triggered()
{

}



void MainWindow::on_actionaa_triggered()//坐标输入点
{
    point->exec();
}
//槽函数 更新数据 坐标输入画点（采用画一个小圆的办法来显示点）
void MainWindow::drawpoint(double x, double y){
    p_x=x;
    p_y=y;
    p_a=2;
    p_b=2;
    update();
}

void MainWindow::on_Line_triggered()//坐标输入直线
{

    line->exec();
}
//槽函数 更新数据 坐标输入直线
void MainWindow::drawline(double x, double y, double x1, double y1){
    QRect rect;
    QPoint p1(x,y),p2(x1,y1);
    rect.setTopLeft(p1);
    rect.setBottomRight(p2);
    _line.append(rect);
    _shape.append(4);
    update();
}

void MainWindow::on_actionaa_3_triggered()//坐标输入矩形
{
    rectangle->exec();
}
//槽函数 更新数据 坐标输入矩形
void MainWindow::drawrectangle(double x, double y, double x1, double y1){

    QRect rect;
    QPoint p1(x,y),p2(x1,y1);
    rect.setTopLeft(p1);
    rect.setBottomRight(p2);
    _rects.append(rect);
    _shape.append(2);
    update();
}

void MainWindow::on_actionaa_4_triggered()//坐标输入圆
{
    circular->exec();
}
//槽函数 更新数据 坐标输入画圆
void MainWindow::drawcircular(double x, double y, double x1, double y1){
    QRect rect;
    QPoint p1(x,y),p2(x1,y1);
    rect.setTopLeft(p1);
    rect.setBottomRight(p2);
    _ellipse.append(rect);
    _shape.append(3);
    update();
}

//导入工程文件
void MainWindow::on_action_import_triggered()
{

    QString fileName = QFileDialog::getOpenFileName(this,tr("导入"),"","Engineering(*.tdp)");
    ifstream ist;
    _line.clear();
    _lines.clear();
    _rects.clear();
    _shape.clear();
    _ellipse.clear();
    if (fileName.size()>=0)
    {
        ist.open(fileName.toStdString().data());

        int linesSize,rectsSize,ellipseSize,lineSize,shapeSize;
        ist>>linesSize>>rectsSize>>ellipseSize>>lineSize>>shapeSize;

        for (int i=0;i<linesSize;i++)
        {
            int num;
            QVector<QPoint> temp;
            ist>>num;
            for (int j=0;j<num;j++)
            {
                int x,y;
                ist>>x>>y;
                QPoint temp1(x,y);
                temp.append(temp1);
            }
            _lines.append(temp);
        }

        for (int i=0;i<rectsSize;i++)
        {
            int x1,x2,y1,y2;
            ist>>x1>>y1>>x2>>y2;
            QRect temp(x1,y1,x2,y2);
            _rects.append(temp);
        }
        for (int i=0;i<ellipseSize;i++)
        {
            int x1,x2,y1,y2;
            ist>>x1>>y1>>x2>>y2;
            QRect temp(x1,y1,x2,y2);
            _ellipse.append(temp);
        }
        for (int i = 0; i <lineSize; i++)
        {
            int x1,x2,y1,y2;
            ist>>x1>>y1>>x2>>y2;
            QRect temp(x1,y1,x2,y2);
            _line.append(temp);
        }
        for (int i=0;i<shapeSize;i++)
        {
            int shapetype;
            ist>>shapetype;
            _shape.append(shapetype);
        }
        update();
    }
}

//导出工程文件
void MainWindow::on_action_export_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("导出"), "new.tdp", "Engineering (*.tdp)");
    if (fileName.size()>=0)
    {
        ofstream ost;
        ost.open(fileName.toStdString().data());
        ost<<_lines.size()<<" "<<_rects.size()<<" "<<_ellipse.size()<<" "
           <<_line.size()<<" "<<_shape.size()<<endl;


        for (QVector<QVector<QPoint>>::iterator it=_lines.begin();it!=_lines.end();it++)
        {
            ost<<it->size()<<endl;
            for (QVector<QPoint>::iterator it1=it->begin();it1!=it->end();it1++)
            {
                ost<<it1->x()<<" "<<it1->y()<<endl;
            }
        }

        for (QVector<QRect>::iterator it=_rects.begin();it!=_rects.end();it++)
        {
            ost<<it->left()<<" "<<it->top()<<" "<<it->width()<<" "<<it->height()<<endl;
        }

        for (QVector<QRect>::iterator it=_ellipse.begin();it!=_ellipse.end();it++)
        {
            ost<<it->left()<<" "<<it->top()<<" "<<it->width()<<" "<<it->height()<<endl;
        }

        for (QVector<QRect>::iterator it=_line.begin();it!=_line.end();it++)
        {
            ost<<it->left()<<" "<<it->top()<<" "<<it->width()<<" "<<it->height()<<endl;
        }

        for (QVector<int>::iterator it=_shape.begin();it!=_shape.end();it++)
        {
            ost<<*it<<endl;
        }
        ost.close();


    }
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_actionBlack_triggered()
{
    _colorType = 0;
}

void MainWindow::on_action_triggered()
{
    _lines.clear();
    _rects.clear();
    _ellipse.clear();
    _line.clear();
    _text.clear();
    _tpoint.clear();
    _shape.clear();
    update();
}

void MainWindow::on_action_2_triggered()//分析和编辑界面的显示
{
    emit send(_line.size());
    line_edit->exec();
}
void MainWindow::edit_line(int number,double x,double y,double x1,double y1){//接受对话框参数，修改

    QPoint p1(x,y),p2(x1,y1);
    _line[number-1].setTopLeft(p1);
    _line[number-1].setBottomRight(p2);
    update();
}
void MainWindow::cacu_line(int number){
    double c=sqrt(pow(_line[number-1].width(),2)+pow(_line[number-1].height(),2));
    emit send_lenth(c);
}

void MainWindow::on_actionju_triggered()
{
    emit send_rec_num(_rects.size());
    rec->exec();
}
void MainWindow::edit_rec(int number,double x,double y,double x1,double y1){
    QPoint p1(x,y),p2(x1,y1);
    _rects[number-1].setTopLeft(p1);
    _rects[number-1].setBottomRight(p2);
    update();
}
void MainWindow::cacu_rec(int number){
    double c=2*(_rects[number-1].width()+_rects[number-1].height());
    double s=_rects[number-1].width()*_rects[number-1].height();
    emit send_c_s(c,s);
}

void MainWindow::on_actionQ_triggered()
{
    emit send_cir_num(_ellipse.size());
    cir->exec();
}
void MainWindow::edit_cir(int number,double x,double y,double x1,double y1){
    QPoint p1(x,y),p2(x1,y1);
    _ellipse[number-1].setTopLeft(p1);
    _ellipse[number-1].setBottomRight(p2);
    update();
}
void MainWindow::cacu_cir(int number){
    double c=2*3.14*_ellipse[number-1].height()+4*(_ellipse[number-1].width()-_ellipse[number-1].height());
    double s=3.14*_ellipse[number-1].height()*_ellipse[number-1].width();
    emit cir_send_c_s(c,s);
}
