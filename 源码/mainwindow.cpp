#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <Eigen\Dense>
#include <QObject>

using namespace std;
using namespace Eigen;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->calculate,SIGNAL(clicked()),this,SLOT(samp1_click()));
    connect(ui->button1,SIGNAL(clicked()),this,SLOT(setbutton()));
    connect(ui->button2,SIGNAL(clicked()),this,SLOT(setbutton()));
    connect(ui->button3,SIGNAL(clicked()),this,SLOT(setbutton()));
}

void MainWindow::setbutton()   //这里是确认是哪种计算方式
{
    if (ui->button1->isChecked())
        ui->label_button->setText("1");
    else if (ui->button2->isChecked())
        ui->label_button->setText("2");
    else if (ui->button3->isChecked())
        ui->label_button->setText("3");
    else
        ui->label_button->setText("1");
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool ItemEmpty(QTableWidget *t, int x, int y)
{
    if (t->item(x,y) == NULL)
        return true;
    return (t->item(x,y)->text() == QObject::tr(""));
}

void MainWindow::on_samp1_clicked()
{
    ui->matrix->clear();
    ui->seed->clear();
    ui->res1->clear();
    ui->offset->setText("");
    ui->matrix->setItem(0,0,new QTableWidgetItem("-1"));
    ui->matrix->setItem(0,1,new QTableWidgetItem("2"));
    ui->matrix->setItem(0,2,new QTableWidgetItem("1"));
    ui->matrix->setItem(1,0,new QTableWidgetItem("2"));
    ui->matrix->setItem(1,1,new QTableWidgetItem("-4"));
    ui->matrix->setItem(1,2,new QTableWidgetItem("1"));
    ui->matrix->setItem(2,0,new QTableWidgetItem("1"));
    ui->matrix->setItem(2,1,new QTableWidgetItem("1"));
    ui->matrix->setItem(2,2,new QTableWidgetItem("-6"));
    ui->seed->setItem(0,0,new QTableWidgetItem("1"));
    ui->seed->setItem(0,1,new QTableWidgetItem("1"));
    ui->seed->setItem(0,2,new QTableWidgetItem("1"));
    ui->precision->setText("0.00001");
}

void MainWindow::on_samp2_clicked()
{
    ui->matrix->clear();
    ui->seed->clear();
    ui->res1->clear();
    ui->offset->setText("");
    int SAMP2[36] = {4,-2,7,3,-1,8,-2,5,1,1,4,7,7,1,7,2,3,5,3,1,2,6,5,1,-1,4,3,5,3,2,8,7,5,1,2,4};
    for(int i=0;i<6;i++)
        for (int j=0;j<6;j++)
            ui->matrix->setItem(i,j,new QTableWidgetItem(QString::number(SAMP2[6*i+j])));
    ui->seed->setItem(0,0,new QTableWidgetItem("1"));
    ui->seed->setItem(0,1,new QTableWidgetItem("0"));
    ui->seed->setItem(0,2,new QTableWidgetItem("1"));
    ui->seed->setItem(0,3,new QTableWidgetItem("0"));
    ui->seed->setItem(0,4,new QTableWidgetItem("0"));
    ui->seed->setItem(0,5,new QTableWidgetItem("1"));
    ui->precision->setText("0.00001");
}

void MainWindow::on_samp3_clicked()
{
    ui->matrix->clear();
    ui->seed->clear();
    ui->res1->clear();
    ui->offset->setText("");
    int SAMP3[25] = {2,-1,0,0,0,-1,2,-1,0,0,0,-1,2,-1,0,0,0,-1,2,-1,0,0,0,-1,2};
    for(int i=0;i<5;i++)
        for (int j=0;j<5;j++)
            ui->matrix->setItem(i,j,new QTableWidgetItem(QString::number(SAMP3[5*i+j])));
    ui->seed->setItem(0,0,new QTableWidgetItem("1"));
    ui->seed->setItem(0,1,new QTableWidgetItem("1"));
    ui->seed->setItem(0,2,new QTableWidgetItem("1"));
    ui->seed->setItem(0,3,new QTableWidgetItem("1"));
    ui->seed->setItem(0,4,new QTableWidgetItem("1"));
    ui->precision->setText("0.0001");
}

void MainWindow::on_samp4_clicked()
{
    ui->matrix->clear();
    ui->seed->clear();
    ui->res1->clear();
    ui->offset->setText("");
    int SAMP4[16] = {2,1,3,4,1,-3,1,5,3,1,6,-2,4,5,-2,-1};
    for(int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            ui->matrix->setItem(i,j,new QTableWidgetItem(QString::number(SAMP4[4*i+j])));
    ui->seed->setItem(0,0,new QTableWidgetItem("1"));
    ui->seed->setItem(0,1,new QTableWidgetItem("1"));
    ui->seed->setItem(0,2,new QTableWidgetItem("1"));
    ui->seed->setItem(0,3,new QTableWidgetItem("1"));
    ui->precision->setText("0.01");

}

void MainWindow::on_samp5_clicked()
{
    ui->matrix->clear();
    ui->seed->clear();
    ui->res1->clear();
    ui->offset->setText("");
    int SAMP5[9] = {-1,2,1,2,-4,1,1,1,-6};
    for(int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            ui->matrix->setItem(i,j,new QTableWidgetItem(QString::number(SAMP5[3*i+j])));
    ui->seed->setItem(0,0,new QTableWidgetItem("1"));
    ui->seed->setItem(0,1,new QTableWidgetItem("1"));
    ui->seed->setItem(0,2,new QTableWidgetItem("1"));
    ui->precision->setText("0.0001");
    ui->offset->setText("-6.42");
}

void MainWindow::on_clear_clicked()
{
    ui->matrix->clear();
    ui->seed->clear();
    ui->res1->clear();
    ui->precision->setText("");
    ui->offset->setText("");
}

void MainWindow::on_calculate_clicked()
{
   //自动计算n和防止出错机制
   int n=0;
   for (int i=0;i<7;i++)
      if (!ItemEmpty(ui->matrix,i,i))
          n = i+1;
   if (ui->matrix->item(0,0) == NULL)
       return;
   for (int i=0;i<n;i++)
       for (int j=0;j<n;j++)
          if (ui->matrix->item(i,j) == NULL)
              return;
   for (int i=0;i<n;i++)
       for (int j=0;j<n;j++)
          if (ui->matrix->item(i,j)->text() == "")
              return;
   if (ui->label_button->text()=="3"&&ui->offset->toPlainText()=="")
       return;
   //读取并初始化矩阵
   MatrixXd A(n,n);
   for (int i=0;i<n;i++)
      for (int j=0;j<n;j++)
         A(i,j)=ui->matrix->item(i,j)->text().toDouble();
   if (ui->label_button->text()=="3"){
       double p = ui->offset->toPlainText().toDouble();
       MatrixXd I(n,n);
       for (int i=0;i<n;i++)
          for (int j=0;j<n;j++)
             I(i,j)=0;
       for (int i=0;i<n;i++)
             I(i,i)=1.0;
       A = A-p*I;
       A = A.inverse();
   }
   if (ui->label_button->text()=="2")
      A = A.inverse();
   VectorXd X(n);
   VectorXd Y(n);
   for (int i=0;i<n;i++)
      X(i) = ui->seed->item(0,i)->text().toDouble();
   double last = X.maxCoeff()+10; //精度总不会超过10吧。。。
   double precision0 = ui->precision->toPlainText().toDouble();
   int ite = 0;
   while (1)
   {
      Y = X/max(X.maxCoeff(),-X.minCoeff());
      X = A*Y;
      //cout<<"Y:"<<endl<<Y<<endl;
      //cout<<"X:"<<endl<<X<<endl;
      //以下代码判断是否继续循环
      for (int i=0;i<n;i++)
         if (abs(Y(i))==1) ite = i;  //找到最大特征值的位置
      if (abs((abs(X(ite))-abs(last)))<precision0)
          break;
      last = X(ite);
   }
   int verse = 1;
   for (int i=0;i<n;i++)
      if (last*X(ite)<0) verse = -1;  //判断特征值是否为负
   for (int i=0;i<n;i++)
      ui->res1->setItem(0,i,new QTableWidgetItem(QString::number(Y(i))));
   if (ui->label_button->text()=="1")
      ui->res0->setText(QString::number(verse*max(X.maxCoeff(),-X.minCoeff())));
   else if(ui->label_button->text()=="2")
      ui->res0->setText(QString::number(verse/max(X.maxCoeff(),-X.minCoeff())));
   else
      ui->res0->setText(QString::number(ui->offset->toPlainText().toDouble()+verse/max(X.maxCoeff(),-X.minCoeff())));
}
//A[i][j] = ui->matrix->item(i,j)->text().toDouble();
//ui->res1->setText("-6.42106");
//ui->res2->setItem(0,0,new QTableWidgetItem("-0.046152"));

