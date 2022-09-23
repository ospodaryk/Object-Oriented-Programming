#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QImageReader>
#include <QTextBlock>
#include <QTextEdit>


#include <QLineEdit>

#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString file;
     QUrl Uri;
      QImage image;
       QTextDocument * textDocument;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionExit_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionSave_triggered();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionPaste_photo_triggered();


    void on_action18_triggered();

    void on_action26_triggered();

    void on_action12_triggered();

    void on_action14_triggered();

    void on_action20_triggered();

    void on_action22_triggered();

    void on_action24_triggered();

    void on_action30_triggered();

    void on_actionRed_triggered();

    void on_actionGreen_triggered();

    void on_actionBlue_triggered();

    void on_actionYellow_triggered();

    void on_actionWhite_triggered();

    void on_actionBold_2_triggered();

    void on_actionOriginal_size_triggered();


    void on_actionCursive_2_triggered();

    void on_actionHelvetica_triggered();

    void on_actionTimes_New_Roman_triggered();

    void on_actionBigger_triggered();

    void on_actionSmaller_triggered();
    void print(double s);

    void on_actionNormal_triggered();


private:
    Ui::MainWindow *ui;
    QString currentFile;
};
#endif // MAINWINDOW_H
