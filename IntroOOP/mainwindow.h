#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_Badd_clicked();

    void on_Bminus_clicked();

    void on_Bdobutok_clicked();

    void on_Bdivide_clicked();

    void on_Bob1_clicked();

    void on_Bob2_clicked();

    void on_Bskr1_clicked();

    void on_Bskr2_clicked();

    void on_Bskr2_2_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
