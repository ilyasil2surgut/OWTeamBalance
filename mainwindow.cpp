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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_balance_clicked()
{
    if(balance.getsize()==12){
        ui->listWidget_team1->clear();
        ui->listWidget_team2->clear();
        balance.BalanceTeams(ui->comboBox_calcmethod->currentIndex());
        for(int i=0;i<6;i++){
            ui->listWidget_team1->addItem(balance.team1[i].text());
            ui->listWidget_team2->addItem(balance.team2[i].text());
        }
        ui->label_team1SR->setText(QString::number(balance.getteam1SR()));
        ui->label_team2SR->setText(QString::number(balance.getteam2SR()));
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
    if(balance.getsize()<12){
        balance.addPlayer(ui->lineEdit_name->text(),ui->lineEdit_SR->text().toInt());
        if(balance.getsize()<=6){
            ui->listWidget_team1->addItem(ui->lineEdit_name->text()+QString(" ")+ui->lineEdit_SR->text());
        }
        else{
            ui->listWidget_team2->addItem(ui->lineEdit_name->text()+QString(" ")+ui->lineEdit_SR->text());
        }
    }
    else{
        QMessageBox a(this);
        a.setText("Слишком много игроков");
        a.addButton(QString("ok"),QMessageBox::AcceptRole);
        a.setWindowTitle(QString("Ошибка"));
        a.exec();
    }
}
