#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // 设置窗口为无边框和无窗口模式
    w.setWindowTitle("颜色设置");
    w.resize(1600, 900);
    w.show();
    return a.exec();
}
