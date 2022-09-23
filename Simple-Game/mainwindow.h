#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT
    int cur_time;
    QTimer *timer;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
int second=10;
int win=1;
int lose=0;
private slots:
    void on_pushButton_clicked();
    void on_tableWidget_cellClicked(int row, int column);
    void on_pushButton_easy_clicked();
    void on_pushButton_medium_clicked();
    void on_pushButton_Hard_clicked();
private:
    Ui::MainWindow *ui;
public slots:
    void your_time();
};
#endif // MAINWINDOW_H
