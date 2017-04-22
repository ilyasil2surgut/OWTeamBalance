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
    else errormessage("Недостаточно игроков");
}

void MainWindow::on_pushButton_add_clicked()
{
    if(balance->getsize()<12){
        if((ui->lineEdit_SR->text().toInt()>5000)||(ui->lineEdit_SR->text().toInt()<=0)) errormessage("Недопустимое значение SR");
        else balance->addPlayer(ui->lineEdit_name->text(),ui->lineEdit_SR->text().toInt());
    }
    else errormessage("Слишком много игроков");
}

void MainWindow::on_comboBox_calcmethod_currentIndexChanged(int index)
{
    balance->setcalculatemethod(index);
    qDebug()<<"Calcmethod:"<<index;
}

void MainWindow::on_pushButton_clear_clicked()
{
    balance->clear();
}

void MainWindow::on_pushButton_swap_clicked()
{
    balance->swap(ui->listWidget_team1->currentRow(),ui->listWidget_team2->currentRow());
}

void MainWindow::errormessage(QString text)
{
    QMessageBox a(this);
    a.setText(text);
    a.addButton(QString("ok"),QMessageBox::AcceptRole);
    a.setWindowTitle(QString("Ошибка"));
    a.exec();
}

void MainWindow::on_pushButton_remove_clicked()
{
    balance->remove(balance->getteam1()->pop(ui->listWidget_team1->currentRow()));
}

void MainWindow::on_pushButton_remove2_clicked()
{
    balance->remove(balance->getteam2()->pop(ui->listWidget_team2->currentRow()));
}
