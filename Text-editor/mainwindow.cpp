#include "mainwindow.h"
#include "ui_mainwindow.h"
QString text=NULL;

       QTextImageFormat imageFormat;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

    ,ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);
    setWindowTitle(tr("Text Editor"));
}
QImage image ;
MainWindow::~MainWindow()
{
    delete ui;
}

QString fileName;

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
     ui->textEdit->cut();
}

void MainWindow::on_actionExit_triggered()
{
   QApplication::quit();

}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();

}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
     ("Save"));
    if (fileName != "") {
     QFile file(fileName);
     if (!file.open(QIODevice::WriteOnly)) {
      QMessageBox msgBox; msgBox.setText("Can't change"); msgBox.exec();
     }
     else {
      QTextStream stream(&file);
      stream <<ui-> textEdit->toPlainText();
      stream.flush();
      file.close();
     }
    }
}

void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
     "Open the file");
     QFile file(fileName);
     if (!file.open(QIODevice::ReadOnly)) {
      QMessageBox::warning(this,"Warning", "Cannot open file : " + file.errorString());
      return;
     }
     QTextStream in(&file);
   ui->textEdit->setText(in.readAll());
     file.close();
}



void MainWindow::on_action18_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    ui->textEdit->setFontPointSize(18);
    ui->textEdit->setTextCursor( cursor );
}

void MainWindow::on_action26_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    ui->textEdit->setFontPointSize(26);
    ui->textEdit->setTextCursor( cursor );
}

void MainWindow::on_action12_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    ui->textEdit->setFontPointSize(12);
    ui->textEdit->setTextCursor( cursor );
}

void MainWindow::on_action14_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    ui->textEdit->setFontPointSize(14);
    ui->textEdit->setTextCursor( cursor );
}

void MainWindow::on_action20_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    ui->textEdit->setFontPointSize(20);
    ui->textEdit->setTextCursor( cursor );
}

void MainWindow::on_action22_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    ui->textEdit->setFontPointSize(22);
    ui->textEdit->setTextCursor( cursor );
}

void MainWindow::on_action24_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    ui->textEdit->setFontPointSize(24);
    ui->textEdit->setTextCursor( cursor );
}

void MainWindow::on_action30_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    ui->textEdit->setFontPointSize(40);
    ui->textEdit->setTextCursor( cursor );
}

void MainWindow::on_actionRed_triggered()
{
    ui->textEdit->setTextColor( QColor( "red" ) );

}

void MainWindow::on_actionGreen_triggered()
{
    ui->textEdit->setTextColor( QColor( "green" ) );

}

void MainWindow::on_actionBlue_triggered()
{
    ui->textEdit->setTextColor( QColor( "blue" ) );

}

void MainWindow::on_actionYellow_triggered()
{
    ui->textEdit->setTextColor( QColor( "yellow" ) );

}

void MainWindow::on_actionWhite_triggered()
{
    ui->textEdit->setTextColor( QColor( "white" ) );

}


void MainWindow::on_actionBold_2_triggered()
{
    ui->textEdit->setFontWeight(QFont::Bold);
}


void MainWindow::on_actionCursive_2_triggered()
{

    ui->textEdit->setFontItalic(QFont::StyleItalic);
}

void MainWindow::on_actionHelvetica_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextCharFormat fontFormat;
    fontFormat.setFont(QFont("Helvetica",30));
 cursor.mergeCharFormat(fontFormat);
    ui->textEdit->setTextCursor(cursor);
}

void MainWindow::on_actionTimes_New_Roman_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextCharFormat fontFormat;
     fontFormat.setFont(QFont("Times",30));
  cursor.mergeCharFormat(fontFormat);
    ui->textEdit->setTextCursor(cursor);
}
void MainWindow::on_actionPaste_photo_triggered()
      {
     file = QFileDialog::getOpenFileName(this, "Select an image");
     QUrl Uri ( QString ( "file://%1" ).arg ( file ) );
     QImage image = QImageReader ( file ).read();
     QTextCursor cursor = ui->textEdit->textCursor();
     QTextImageFormat imageFormat;
     double h=image.height();
     double w=image.width();
 if ((h<1000)||(w<1000)){
     imageFormat.setWidth(h );
  imageFormat.setHeight(w);

    imageFormat.setName( Uri.toString() );
     cursor.insertImage(imageFormat);
 }
     else {QMessageBox::critical(this,"ERROR","Change the size of object");
 }
}

void MainWindow::on_actionOriginal_size_triggered()
{
     print(1);
}

void MainWindow::on_actionBigger_triggered()
{
    print(2);

}

void MainWindow::on_actionSmaller_triggered()
{
   print(0.5);
}
void MainWindow::print(double s){
    QUrl Uri ( QString ( "file://%1" ).arg ( file ) );
    QImage image = QImageReader ( file ).read();
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextImageFormat imageFormat;
    double h=image.height()*s;
    double w=image.width()*s;
    imageFormat.setWidth(h );
 imageFormat.setHeight(w);

   imageFormat.setName( Uri.toString() );
    cursor.insertImage(imageFormat);

}

void MainWindow::on_actionNormal_triggered()
{
    ui->textEdit->setFontWeight(QFont::StyleNormal	);
    ui->textEdit->setFontItalic(QFont::StyleNormal);

}

