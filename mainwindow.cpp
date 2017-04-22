#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Балансировщик команд");
    setWindowIcon(QIcon(QPixmap(":/icon/icon.png")));
    ui->label_team1SR->setText(QString("0"));
    ui->label_team2SR->setText(QString("0"));
    balance=new Balancer(new Team(ui->listWidget_team1,ui->label_team1SR),new Team(ui->listWidget_team2,ui->label_team2SR));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_balance_clicked()
{
    if(balance->getsize()==12){
        balance->BalanceTeams();
    }
    else{
        QMessageBox a(this);
        a.setText("Недостаточно игроков");
        a.addButton(QString("ok"),QMessageBox::AcceptRole);
        a.setWindowTitle(QString("Ошибка"));
        a.exec();
    }
}

void MainWindow::on_pushButton_add_clicked()
{
    if(balance->getsize()<12){
        balance->addPlayer(ui->lineEdit_name->text(),ui->lineEdit_SR->text().toInt());
    }
    else{
        QMessageBox a(this);
        a.setText("Слишком много игроков");
        a.addButton(QString("ok"),QMessageBox::AcceptRole);
        a.setWindowTitle(QString("Ошибка"));
        a.exec();
    }
}

void MainWindow::on_comboBox_calcmethod_currentIndexChanged(int index)
{
    balance->setcalculatemethod(index);
    qDebug()<<"Calcmethod:"<<index;
}
