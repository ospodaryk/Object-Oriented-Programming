#ifndef ROAD_H
#define ROAD_H

#include <QMainWindow>
#include<QTextEdit>
#include<QStringList>
#include<QMessageBox>
#include<QString>
#include<QCheckBox>
#include<QComboBox>
#include<QTableWidget>
#include<QFile>
#include <iostream>
using namespace std;
#include<QFileDialog>
#include <vector>


#include "MyException.h"

class Road
{
protected:

//    QStringList alldatainformation[10];



    int size=20;
    long *lengthofroad=new long[size ];
    long *countofroad=new long[size ];
    QString *roadwithdivide=new QString[size ];
QString temporary;

    int columns=6;

private:

QString getSelectedFile(const QFileDialog &dialog);
public:
int row=9;

void PrintInFile(QFile inputFile,Road obj);
void ReadFromFile(Road obj);
    Road();
    void  CheckN();
    void  CheckStr();
    void Divide();
bool checkinitialisation=false;
    void  CheckSymb(int i);
    QString alldata;
      QStringList rowainformation;
    QStringList dataforeachelement[10];
   Road(QTextEdit *edit, QTableWidget *list);
   Road(Road *obj);
   void Print(QTableWidget *list);
   string  GetSurname (int index) const;


    void GetData(int i, int j);
//    void SortByType(QTableWidget *result, int size);
    void Compare(QTableWidget *list,QTableWidget *result,QString tocompare,int position);


    void Task1(QTableWidget *list);
    void Task2(QTableWidget *list, QTextEdit *result);
    void Task3(QTableWidget *list, QTableWidget *result);
    void Task4(QTableWidget *list, QTableWidget *result);
    void Task5(QTableWidget *list, QTableWidget *result);


};
std::ostream & operator <<(std::ostream & output, Road const& s);
std::istream &operator>>(istream &input, Road &obj);

#endif // ROAD_H
