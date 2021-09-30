#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <Eigen\Dense>
using namespace std;
using namespace Eigen;
int main(int argc, char *argv[])
{

    QApplication a0(argc, argv);
    MainWindow w0;
    w0.show();

    return a0.exec();
}
