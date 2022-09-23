#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDebug>
#include <QIntValidator>
#include <QListWidget>
#include <array.h>
#include <fstream>

#define SIZE 1

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private
    slots:

    void on_B_simple_new_clicked();

    void on_optimizedadd_clicked();

    void on_B_simpleelementpos_clicked();

    void on_optimizedelementpos_clicked();

    void on_B_simpleelementpos_2_clicked();

    void on_B_simpleelementpos_3_clicked();

    void on_pushButton_clicked();

    void on_actionSve_triggered();

private:
    Ui::MainWindow *ui;
    Array *array1;
    Array *array2;

    void addItemToList(int item, QListWidget *list,int position);

    QString getSelectedFile(const QFileDialog &dialog);

};

QListWidget *operator<<(QListWidget *output, const Array &toOutput);

#endif // MAINWINDOW_H
