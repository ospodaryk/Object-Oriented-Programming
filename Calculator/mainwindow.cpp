#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>
QString Label=NULL;
QString historry=NULL;
    int check;
    double Number1=0,Number2=0,result=0;
    QString Sign;
QString newLabel;
MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(digit()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(digit()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(digit()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(digit()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(digit()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(digit()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(digit()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(digit()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(digit()));
    connect(ui->pushButton_0, SIGNAL(released()), this, SLOT(digit()));
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(history()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(history()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(history()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(history()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(history()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(history()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(history()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(history()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(history()));
    connect(ui->pushButton_0, SIGNAL(released()), this, SLOT(history()));
    connect(ui->pushButton_plus, SIGNAL(released()), this, SLOT(history()));
    connect(ui->pushButton_res, SIGNAL(released()), this, SLOT(history()));
    connect(ui->pushButton_change, SIGNAL(released()), this, SLOT(history()));
    connect(ui->pushButton_minus, SIGNAL(released()), this, SLOT(history()));
    connect(ui->pushButton_dobutok, SIGNAL(released()), this, SLOT(history()));
    connect(ui->pushButton_divide, SIGNAL(released()), this, SLOT(history()));
    connect(ui->pushButton_sin, SIGNAL(released()), this, SLOT(history()));
    connect(ui->pushButton_change, SIGNAL(released()), this, SLOT(change()));
    connect(ui->pushButton_plus, SIGNAL(released()), this, SLOT(plus()));
    connect(ui->pushButton_res, SIGNAL(released()), this, SLOT(res()));
}

MainWindow::~MainWindow() {
    delete ui;
}
void MainWindow::history() {
    QPushButton *button = (QPushButton *) sender();
   historry += (button->text());
    ui->history->setText(historry);
}
void MainWindow::digit() {
    QPushButton *button = (QPushButton *) sender();
   Label += (button->text());
    ui->label->setText(Label);
}
void MainWindow::on_pushButton_dot_released() {
    if (!(ui->label->text().contains("."))) {
        ui->label->setText(ui->label->text() + ".");
    }
}
void MainWindow::on_pushButton_change_clicked() {
    result =Label.toDouble();
    result = result * -1;
    Label = QString::number(result, 'g', 15);
    ui->label->setText(Label);
}
void MainWindow::on_pushButton_plus_clicked() {
    RESULT();
    Number1 = Label.toDouble();
    Label.clear();
    Sign = "+";
    ui->label->setText(Sign);
}
void MainWindow::on_pushButton_minus_clicked() {
    RESULT();
     Number1 = Label.toDouble();
     Label.clear();
     Sign = "-";
     ui->label->setText(Sign);
}
void MainWindow::on_pushButton_dobutok_clicked() {
    RESULT();
     Number1 = Label.toDouble();
     Label.clear();
     Sign = "X";
     ui->label->setText(Sign);
}
void MainWindow::on_pushButton_divide_clicked() {
    RESULT();
     Number1 = Label.toDouble();
     Label.clear();
     Sign = "÷";
     ui->label->setText(Sign);
}
void MainWindow::on_pushButton_sin_clicked() {
    RESULT();

     Number1 = Label.toDouble();
     Label.clear();
     Sign = "√";
     ui->label->setText(Sign);
}
void MainWindow::on_pushButton_clear_clicked() {
    Label.clear();
    ui->label->clear();
    historry.clear();
    ui->history->clear();
}
void MainWindow::on_pushButton_res_clicked() {
    RESULT();
    Sign = NULL;
    ui->label->setText(Label);
    historry += Label;
     ui->history->setText(historry);
}
