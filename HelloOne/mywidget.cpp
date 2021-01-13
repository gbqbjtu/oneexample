#include "mywidget.h"
#include "mybutton.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    //初始化
    //父窗口显示时子窗口会随之显示
    b2=new QPushButton("Hello, qt",this);
    //b2->setText("Hello one");
    //b2->show();

    b1.setParent(this);
    b1.setText("two");

    //改变位置
    b1.move(100,100);
    b1.resize(30,10);

    // 内存自动回收适用于
    //1.从QObject派生的类，直接派生和间接派生
    //2.指定父类，父亲析构时，先析构他的孩子

    //创建自定义的窗口对象
    MyButton* btn=new MyButton(this);
    btn->move(50,50);
    btn->setText("444");

    this->setWindowTitle("wowowo");
    this->resize(300,200);
    //this->setFixedSize(300,200);
//    this->setWindowIcon(1);

    //需求 b1-->关闭窗口

    //连接
    // connect(b1,发出的信号，this,处理的槽函数）
    //&b1:信号的发出者，此参数为一个指针，不是指针时需要取地址
    //&QPushButton::clicked,格式：&+信号发出类的名字+::+信号名字
    //this-->捕捉信号者
    //&MyWidget::close-->格式：&+类的名字+::+标准槽名字

    connect(&b1,&QPushButton::clicked,this,&MyWidget::showMaximized);

}

MyWidget::~MyWidget()
{

}
