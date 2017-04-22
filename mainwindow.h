#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <balancer.h>
#include <QMessageBox>
#include <team.h>
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
    void on_pushButton_balance_clicked();

    void on_pushButton_add_clicked();

    void on_comboBox_calcmethod_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    Balancer* balance;

};

#endif // MAINWINDOW_H
