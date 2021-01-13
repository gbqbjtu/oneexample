#include "mywidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //应用程序类，每个程序有且只有之一
    QApplication a(argc, argv);
    //窗口类，默认不显示
    MyWidget w;
    w.show();

    return a.exec();
}
