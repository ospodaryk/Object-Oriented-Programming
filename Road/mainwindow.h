#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "road.h"

#include <QMainWindow>
#include<QTextEdit>
#include<QStringList>
#include<QMessageBox>
#include<QString>
#include<QCheckBox>
#include<QComboBox>
#include<QFileDialog>
#include "MyException.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_MAX_clicked();

    void on_Task3_clicked();

    void on_TAsk4_clicked();

    void on_Task5_clicked();

    void on_PRINT_clicked();

    void on_scan_clicked();

    void on_tmmpp_clicked();

private   :

    QString getSelectedFile(const QFileDialog &dialog);
    Ui::MainWindow *ui;
    Road pRoad;
};
#endif // MAINWINDOW_H
