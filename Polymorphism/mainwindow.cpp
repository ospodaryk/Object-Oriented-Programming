#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settext.h"
#include "simplearray.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_BaddSimple_clicked() {
    SimpleArray *pArr;
    pArr = new SimpleArray;
    pArr->ReadString(ui->SimpleArray);
    pArr->Add(ui->add_simple->toPlainText().toInt());
    pArr->DisplayString(ui->SimpleArray);
}

void MainWindow::on_B_simpleelementpos_2_clicked() {
    SimpleArray *pArr;
    pArr = new SimpleArray;
    pArr->ReadString(ui->SimpleArray);
    int position = pArr->GetPosition(ui->value_simple->toPlainText().toInt());
    ui->position_simple->setText(QString::number(position));
}




void MainWindow::on_optimizedadd_clicked() {
    SetArray *pArr;
    pArr = new SetArray;
    pArr->ReadString(ui->SetArray);
    pArr->Add(ui->add_set->toPlainText().toInt());
    pArr->DisplayString(ui->SetArray);
}






void MainWindow::on_B_simpleelementpos_3_clicked() {
    SetArray *pArr;
    pArr = new SetArray;
    pArr->ReadString(ui->SetArray);
    int position = pArr->GetPosition(ui->value_set->toPlainText().toInt());
    ui->position_set->setText(QString::number(position));
}

void MainWindow::on_B_simpleelementpos_4_clicked()
{
    SimpleArray *pArr;
    pArr = new SimpleArray;
    pArr->ReadString(ui->SimpleArray);
    ui->size_simple->setText(QString::number(pArr->getLength()));
}

void MainWindow::on_B_simpleelementpos_5_clicked()
{
    SetArray *pArr;
    pArr = new SetArray;
    pArr->ReadString(ui->SetArray);
    ui->size_set->setText(QString::number(pArr->getLength()));
}
