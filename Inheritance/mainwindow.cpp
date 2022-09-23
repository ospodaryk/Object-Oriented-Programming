#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include "array.h"
#include "simplearray.h"
#include "optimizedarray.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    array1 = new SimpleArray();
    array2 = new OptimizedArray();
}

MainWindow::~MainWindow() {
    delete ui;
    delete array1;
    delete array2;
}

void MainWindow::addItemToList(int item, QListWidget *list,int position) {
    auto listItem = new QListWidgetItem(QString::number(item));
    listItem->setFlags(listItem->flags() | Qt::ItemIsEditable);
    list->insertItem(position,listItem);
}

QListWidget *operator<<(QListWidget *output, const Array &toOutput) {
    const int listSize = output->count(), arraySize = toOutput.getLength();
    for (int i = 0; i < listSize; ++i) {
        output->item(i)->setText(QString::number(toOutput[i]));
    }
    for (int i = listSize; i < arraySize; ++i) {
        output->addItem(QString::number(toOutput[i]));
        output->item(i)->setFlags(output->item(i)->flags() | Qt::ItemIsEditable);
    }
    return output;
}


QString MainWindow::getSelectedFile(const QFileDialog &dialog) {
    auto selectedPaths = dialog.selectedFiles();
    return QDir::toNativeSeparators(selectedPaths.first());
}


void MainWindow::on_B_simple_new_clicked() {
    int newElement = ui->simple_new->text().toInt();
    array1->add(newElement);
    addItemToList(newElement, ui->show_simle,array1->getLength());
}

void MainWindow::on_optimizedadd_clicked() {
    int newElement = ui->optimized_new->text().toInt();
    array2->add(newElement);
    addItemToList(newElement, ui->optimized_show,array2->getLength());

}

void MainWindow::on_B_simpleelementpos_clicked() {
    int position = ui->simple_position->text().toInt();
    QString element = QString::number(array1->findElement(position));

    ui->simple_elementposition->setText(element);

}

void MainWindow::on_optimizedelementpos_clicked() {
    int position = ui->optimizedposition->text().toInt();
    QString element = QString::number(array2->findElement(position));
    ui->optimizedelement_2->setText(element);

}

void MainWindow::on_B_simpleelementpos_2_clicked() {
    int position = ui->simple_position->text().toInt();
    int element = ui->smp_newelementonpos->text().toInt();
    array1->InsertElementAtPosition(element,position );
    addItemToList(element, ui->show_simle,position);

}

void MainWindow::on_B_simpleelementpos_3_clicked() {
    int position = ui->optimizedposition->text().toInt();
    int element = ui->opt_newelementonpos->text().toInt();
    array2->InsertElementAtPosition(element,position );
    addItemToList(element, ui->optimized_show,position);

}

void MainWindow::on_pushButton_clicked() {
    free(array1);
    free(array2);
}
void MainWindow::on_actionSve_triggered() {
    QFileDialog dialog(this);

    if (dialog.exec() == QDialog::Accepted) {
        auto file = getSelectedFile(dialog).toStdString();

        std::ofstream output;
        output.open(file);

        if (!output.is_open()) {
            QMessageBox::critical(this, "Error", "Could not open the file");
            return;
        }
        output << *array1;
        output << *array2;
        output.close();
    }
}
