#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString historry=NULL;
    QString Label = NULL;
    double Number1 = 0, Number2 = 0, result = 0;
    QString Sign;
    void PLUS(double Number1, double Number2, double *result) {
        *result = Number1 + Number2;
    }
    void MULT(double Number1, double Number2, double *result) {
        *result = Number1 * Number2;
    }
    void MINUS(double Number1, double Number2, double *result) {
        *result = Number1 - Number2;
    }
    void SQRT(double Number1, double *result) {
        *result = sqrt(Number1);
    }
    void DIV(double Number1, double Number2, double *result) {
        *result = Number1 / Number2;
    }
    void RESULT() {
        Number2 = Label.toDouble();
        if (Sign == "+") {
            PLUS(Number1, Number2, &result);
            Label = QString::number(result, 'g', 10);
        } else if (Sign == "X") {
            MULT(Number1, Number2, &result);
            Label = QString::number(result, 'g', 10);
        } else if (Sign == "-") {
            MINUS(Number1, Number2, &result);
            Label = QString::number(result, 'g', 10);
        } else if (Sign == "√") {
            if (Number1 >= 0) {
                SQRT(Number1, &result);
                Label = QString::number(result, 'g', 10);
            } else Label = "ERROR";

        } else if (Sign == "÷") {
            if (Number2 != 0) {
                DIV(Number1, Number2, &result);
                Label = QString::number(result, 'g', 10);
            } else Label = "ERROR";
        }
        Number1 = 0;
    }
private:
    Ui::MainWindow *ui;
private
    slots:
    void digit();
    void history();
    void on_pushButton_dot_released();
    void on_pushButton_change_clicked();
    void on_pushButton_sin_clicked();
    void on_pushButton_divide_clicked();
    void on_pushButton_minus_clicked();
    void on_pushButton_dobutok_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_res_clicked();
    void on_pushButton_plus_clicked();
};
#endif // MAINWINDOW_H
