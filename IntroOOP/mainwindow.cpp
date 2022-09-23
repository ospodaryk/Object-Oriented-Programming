#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "drib.h"
unsigned int Fraction::numberOfFraction =0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}
MainWindow::~MainWindow()
{
    delete ui;
}


void operator<<(QLineEdit *line, Fraction &fraction)
{
    line->setText(fraction.toString());
}

void operator>>(QLineEdit *line, Fraction &fraction)
{
    fraction.fromString(line->text());
}

bool operator>(const Fraction &a, const Fraction &b)
{

    if(a.numerator*b.denumerator>b.numerator*a.denumerator)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator<(const Fraction &a, const Fraction &b)
{
    if(a.numerator*b.denumerator<b.numerator*a.denumerator)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool operator==(const Fraction &a, const Fraction &b)
{

    if(a.numerator == b.numerator
       &&  a.denumerator == b.denumerator )
    {
        return  true;
    }
    else{
        return false;
    }
}
void MainWindow::on_Badd_clicked()
{
    Fraction a;
    Fraction b;
    Fraction c;
    ui->drib1>>(a);
    ui->drib2>>(b);
    c = a+b;
    ui->text_add<<((c.toString(),c));
    ui->label_drib->setText("Кількість створених об’єктів "+QString::number(Fraction::numberOfFraction));

}

void MainWindow::on_Bminus_clicked()
{
    Fraction a;
    Fraction b;
    Fraction c;
    ui->drib1>>(a);
    ui->drib2>>(b);
    c = a-b;
    ui->text_minus<<((c.toString(),c));
    ui->label_drib->setText("Кількість створених об’єктів "+QString::number(Fraction::numberOfFraction));

}

void MainWindow::on_Bdobutok_clicked()
{
    Fraction a;
    Fraction b;
    Fraction c;
    ui->drib1>>(a);
    ui->drib2>>(b);
    c = a*b;
    ui->text_dobutok<<(c.toString(),c);
    ui->label_drib->setText("Кількість створених об’єктів "+QString::number(Fraction::numberOfFraction));

}

void MainWindow::on_Bdivide_clicked()
{
    Fraction a;
    Fraction b;
    Fraction c;
    ui->drib1>>(a);
    ui->drib2>>(b);
    c = a/b;
    ui->text_divide<<(c.toString(),c);
    ui->label_drib->setText("Кількість створених об’єктів "+QString::number(Fraction::numberOfFraction));

}

void MainWindow::on_Bob1_clicked()
{
    Fraction a;
    Fraction c;
    ui->drib1>>(a);
    c =  !a;
    ui->text_inv1<<(c.toString(),c);
    ui->label_drib->setText("Кількість створених об’єктів "+QString::number(Fraction::numberOfFraction));


}

void MainWindow::on_Bob2_clicked()
{
    Fraction b;
    Fraction c;
    ui->drib2>>(b);
    c =  !b;
    ui->text_inv2<<(c.toString(),c);
    ui->label_drib->setText("Кількість створених об’єктів "+QString::number(Fraction::numberOfFraction));

}

void MainWindow::on_Bskr1_clicked()
{
    Fraction a;
    ui->drib1>>(a);
    a.reduce();
    ui->text_skr1<<(a.toString(),a);
    ui->label_drib->setText("Кількість створених об’єктів "+QString::number(Fraction::numberOfFraction));

}

void MainWindow::on_Bskr2_clicked()
{
    Fraction b;
    ui->drib2>>(b);
    b.reduce();
    ui->text_skr2<<(b.toString(),b);
    ui->label_drib->setText("Кількість створених об’єктів "+QString::number(Fraction::numberOfFraction));

}

void MainWindow::on_Bskr2_2_clicked()
{
    ui->drib1->setText("");
    ui->drib2->setText("");
    ui->text_add->setText("");
    ui->text_minus->setText("");
    ui->text_divide->setText("");
    ui->text_dobutok->setText("");
    ui->text_inv1->setText("");
    ui->text_inv2->setText("");
    ui->text_skr1->setText("");
    ui->text_skr2->setText("");
    ui->lineEdit->setText("");
    ui->label_drib->setText("Кількість створених об’єктів 0");
    Fraction:: numberOfFraction =0;

}

void MainWindow::on_pushButton_2_clicked()
{
    Fraction a;
    Fraction b;
    bool c;
    ui->drib1>>(a);
    ui->drib2>>(b);
    a.reduce();
    b.reduce();

     c = a==b;
    if(c)
    ui->lineEdit->setText("True");
    else
    ui->lineEdit->setText("False");
    ui->label_drib->setText("Кількість створених об’єктів "+QString::number(Fraction::numberOfFraction));


}

void MainWindow::on_pushButton_3_clicked()
{
    Fraction a;
    Fraction b;
    bool c;
    ui->drib1>>(a);
    ui->drib2>>(b);
     c = a>b;
    if(c)
    ui->lineEdit->setText("True");
    else
    ui->lineEdit->setText("False");
    ui->label_drib->setText("Кількість створених об’єктів "+QString::number(Fraction::numberOfFraction));

}

void MainWindow::on_pushButton_clicked()
{
    Fraction a;
    Fraction b;
    bool c;
    ui->drib1>>(a);
    ui->drib2>>(b);
     c = a<b;
    if(c)
    ui->lineEdit->setText("True");
    else
    ui->lineEdit->setText("False");
    ui->label_drib->setText("Кількість створених об’єктів "+QString::number(Fraction::numberOfFraction));

}
