#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <QMessageBox>
#include <QTimer>
int max = 1;
int click = -1;
MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    timer = new QTimer(this);
timer->setInterval(1000);
connect(timer,SIGNAL(timeout()),this,SLOT(your_time()));
setWindowTitle(tr("Game"));
}
MainWindow::~MainWindow() {
    delete ui;
    delete timer;
}
void MainWindow::on_pushButton_clicked() {
timer->start();
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        for (int j = 0; j <ui->tableWidget->columnCount(); j++) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(lose));
            ui->tableWidget->setItem(i, j, item);
        }
    }
    int k=ui->tableWidget->rowCount();
    int f=ui->tableWidget->columnCount();
    int i = rand() %k;
    int j = rand() %f;
    QTableWidgetItem *item = new QTableWidgetItem(QString::number(win));
    ui->tableWidget->setItem(i, j, item);       
}
void MainWindow::on_tableWidget_cellClicked(int row, int column) {
    QMessageBox msgBox;
    if (ui->pushButton->isChecked() == false) {
        msgBox.setWindowTitle("Error");
        msgBox.setText("Error :\nYou didn't start the Game");
        msgBox.exec();
        return;
    }
    QTableWidgetItem *itab = ui->tableWidget->item(row, column);
    int tmp = itab->text().toInt();
    if (tmp == win) {
        timer->stop();
        msgBox.setWindowTitle("Result");
        msgBox.setText("YOU WIN");
        msgBox.exec();
        ui->pushButton->setChecked(false);
        for (int i = 0; i < ui->tableWidget->rowCount();  i++) {
            for (int j = 0; j < ui->tableWidget->columnCount(); j++) {
              QTableWidgetItem *item = ui->tableWidget->item(i, j);
                delete item;
            }
        }
        second=10;
         ui->label->setText(QString::number(second));
    } else {
        timer->stop();
        msgBox.setWindowTitle("Result");
        msgBox.setText("YOU LOSE");
        msgBox.exec();
        ui->pushButton->setChecked(false);
        for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
            for (int j = 0; j < ui->tableWidget->columnCount(); j++) {
              QTableWidgetItem *item = ui->tableWidget->item(i, j);
                delete item;
            }
        }
        second=10;
         ui->label->setText(QString::number(second));
    }
}
void MainWindow::your_time(){
    QMessageBox msgBox;
    if(second!=0){
second=second-1;  ui->label->setText(QString::number(second));}
    if(second==0){
        msgBox.setWindowTitle("EXIT");
        msgBox.setText("Time out\nYou lose");
        msgBox.exec();
        second=10;
        ui->label->setText(QString::number(second));
    }
}
void MainWindow::on_pushButton_easy_clicked()
{
    QMessageBox msgBox;
    if (ui->pushButton->isChecked() == true) {
        msgBox.setWindowTitle("Error");
        msgBox.setText("Error :\nFinish Previous Game");
        msgBox.exec();
        return;
    } else{
    second=30;
    ui->label->setText(QString::number(second));
    ui->tableWidget->setRowCount(3);
    ui->tableWidget->setColumnCount(3);
    }
}
void MainWindow::on_pushButton_medium_clicked()
{
    QMessageBox msgBox;
    if (ui->pushButton->isChecked() == true) {
        msgBox.setWindowTitle("Error");
        msgBox.setText("Error :\nFinish Previous Game");
        msgBox.exec();
        return;
    } else{
    second=10;
    ui->label->setText(QString::number(second));
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setColumnCount(5);
    }
}
void MainWindow::on_pushButton_Hard_clicked()
{
    QMessageBox msgBox;
    if (ui->pushButton->isChecked() == true) {
        msgBox.setWindowTitle("Error");
        msgBox.setText("Error :\nFinish Previous Game");
        msgBox.exec();
        return;
    } else{
    second=5;
    ui->label->setText(QString::number(second));
    ui->tableWidget->setRowCount(6);
    ui->tableWidget->setColumnCount(6);
    }
}
