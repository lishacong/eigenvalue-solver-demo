#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_calculate_clicked();
    void on_samp1_clicked();
    void on_samp2_clicked();
    void on_samp3_clicked();
    void on_samp4_clicked();
    void on_samp5_clicked();
    void on_clear_clicked();
    void setbutton();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
