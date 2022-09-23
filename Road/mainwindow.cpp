#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "road.h"
#include <QMainWindow>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDebug>

#include <QIntValidator>
#include <QListWidget>
#include <fstream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Список Доріг"));

    QStringList list=(QStringList()<<"державна"<<"регіональна"<<"обласна"<<"місцевa");
    setCentralWidget(ui->gridLayoutWidget);
    ui->information->setColumnWidth(0,250);

    ui->information->setColumnWidth(1,200);
    ui->information->setColumnWidth(2,220);

    ui->information->setColumnWidth(4,200);
    ui->information->setColumnWidth(5,200);
    ui->result->setColumnWidth(0,250);

    ui->result->setColumnWidth(1,200);
    ui->result->setColumnWidth(2,220);

    ui->result->setColumnWidth(4,200);
    ui->result->setColumnWidth(5,200);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{


    pRoad.Task1(ui->information);

}

QString MainWindow::getSelectedFile(const QFileDialog &dialog) {
    auto selectedPaths = dialog.selectedFiles();
    return QDir::toNativeSeparators(selectedPaths.first());
}

void MainWindow::on_MAX_clicked()
{
    Road pRoad;


      if(ui->rbtable->isChecked()==true){
              Road pRoad( ui->textEdit,ui->information);}
    pRoad.Task2(ui->information,ui->max);
}


void MainWindow::on_Task3_clicked()
{
    Road pRoad;


      if(ui->rbtable->isChecked()==true){
              Road pRoad( ui->textEdit,ui->information);}
    pRoad.Task3(ui->information,ui->result);
}


void MainWindow::on_TAsk4_clicked()
{
    Road pRoad;


      if(ui->rbtable->isChecked()==true){
              Road pRoad( ui->textEdit,ui->information);}

    pRoad.Task4(ui->information,ui->result);
}


void MainWindow::on_Task5_clicked()
{
    Road pRoad;


      if(ui->rbtable->isChecked()==true){
              Road pRoad( ui->textEdit,ui->information);}

    pRoad.Task5(ui->information,ui->result);
}


void MainWindow::on_PRINT_clicked()
{
    Road pRoad;


      if(ui->rbtable->isChecked()==true){
              Road pRoad( ui->textEdit,ui->information);}

    QFileDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        auto file = getSelectedFile(dialog).toStdString();
        std::ofstream output;
        output.open(file);
        if (!output.is_open()) {
            QMessageBox::critical(this, "Error", "Could not open the file");
            return;
        }
        output  << pRoad;
        output.close();}
    //std::ofstream os("/Users/oksanaspodarik/desktop/kursova.txt");
    //os << pRoad;
}


void MainWindow::on_scan_clicked()
{        Road pRoad;
    ui->max->insertPlainText("ha");
    QFileDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        auto file = getSelectedFile(dialog).toStdString();
        ifstream input;
        input.open(file);
        if (!input.is_open()) {
            QMessageBox::critical(this, "Error", "Could not open the file");
            return;
        }
        input  >> pRoad;
        ui->max->insertPlainText("=there");

        input.close();}

    ui->max->insertPlainText(pRoad.alldata);
    pRoad.Print(ui->information);
}


void MainWindow::on_tmmpp_clicked()
{
    if(ui->rbtable->isChecked()==true){
       Road pRoad( ui->textEdit,ui->information);}

    if(ui->rbwritten->isChecked()==true){
       Road pRoad;}
}

