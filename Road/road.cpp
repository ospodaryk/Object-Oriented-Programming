#include "road.h"
#include <iostream>
#include<vector>
#include<fstream>
#include<cstdlib>
#include<string>
#include<utility>
#include<QMessageBox>

using namespace std;

QString ReadFromTable(QTableWidget *list) {
    QString data;

    for (int i = 0; i < list->rowCount(); i++) {
        for (int j = 0; j < list->columnCount(); j++) {
            data+=list->item(i,j)->text()+",";
        }
        data+='\n';
    }
}
//-----------------------------Конструктор без параметрів------------------------------------------------------------------------------------------------------------------------
Road::Road()
{
   this->alldata="Oksana-Ode,a,9,6,+,+|BKuix-Ode,a,8,3,-,-| CKuix-Ode,b,7,2,+,+|DKuix-Ode,c,6,6,+,+| EKuix-Ode,b,5,6,+,+|FKuix-Ode,c,4,6,+,+| GKuix-Ode,a,3,6,+,+|EKuix-Ode,b,2,6,+,+| Huix-Ode,a,1,6,-,+|";
              this->rowainformation =   this->alldata.split('|');
            for (int j = 0; j < row; j++) {
                this->  dataforeachelement[j] =   this->rowainformation[j].split(',');
            }

            for (int i = 0; i < row; i++) {
                 this-> lengthofroad[i]=  this->dataforeachelement[i][2].toLong();
            }
            for (int i = 0; i < row; i++) {
                 this-> countofroad[i]=  this->dataforeachelement[i][3].toLong();
            }

}
//-----------------------------Конструктор з параметрами------------------------------------------------------------------------------------------------------------------------

Road::Road(QTextEdit *edit,QTableWidget *list)
{
     this-> rowainformation = edit->toPlainText().split('\n');
    for (int j = 0; j < row; j++) {
          this->dataforeachelement[j] =   this->rowainformation[j].split(',');
    }

    for (int i = 0; i < row; i++) {
        this->  lengthofroad[i]=  this->dataforeachelement[i][2].toLong();
    }
    for (int i = 0; i < row; i++) {
        this->  countofroad[i]=  this->dataforeachelement[i][3].toLong();
    }
     this-> checkinitialisation=true;
    Print(list);
}

//-----------------------------Конструктор копіювання------------------------------------------------------------------------------------------------------------------------

Road::Road(Road *obj)
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < columns; j++) {
            this->dataforeachelement[i][j]=obj->dataforeachelement[i][j];
        }
    }

}
void Road::Print(QTableWidget *list) {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < columns; j++) {
            list->item(i,j)->setText(dataforeachelement[i][j]);
        }
    }

}
//-----------------------------Перевірка виняткових ситуацій------------------------------------------------------------------------------------------------------------------------
void Road:: CheckN()
{
    for (int j = 0; j < row; j++) {
        CheckNumber(dataforeachelement[j][2].toInt());
    }
}
void Road:: CheckStr()
{
    for (int j = 0; j < row; j++) {
        CheckString(dataforeachelement[j][0]);
    }
}
void Road:: CheckSymb(int i)
{
    for (int j = 0; j < row; j++) {
        CheckSymbol(dataforeachelement[j][i]);
    }
}
//-----------------1)Впорядкувати дороги за протяжністю.---------------------------------------------------------------------------------------------------------------------------------------------------------------
void Road::Task1(QTableWidget *list) {
    try{
        CheckN();
    }
    catch(WrongNumberData){
        QMessageBox::critical(NULL, ("Error"),
                              (WrongNumberData().GetError()));
    }    int fl = 0;
    long tmp;
    QStringList tmpdates;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row - 1; j++) {
            if (lengthofroad[j] > lengthofroad[j + 1]) {
                tmp = lengthofroad[j + 1];
                lengthofroad[j + 1] = lengthofroad[j];
                lengthofroad[j] = tmp;
                GetData(j,j+1);
                fl = 1;
            }
        }
        if (fl == 0) { break; }
    }
    Print(list);
}
//-----------2)Знайти найкоротшу дорогу, де найбільша кількість смуг.---------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Road::Task2(QTableWidget *list,QTextEdit *result) {
    try{
        CheckStr();
    }
    catch(WrongStringData){
        QMessageBox::critical(NULL, ("Error"), (WrongStringData().GetError()));
    }
    long *maxcountofroad=new long[row];
    long maxcount=countofroad[0];
    for (int i = 0; i < row; i++) {
        if (maxcount<countofroad[i]) {
            maxcount = countofroad[i];
        }

    }
    for (int i = 0; i < row; i++) {
        if (countofroad[i]==maxcount) {
            maxcountofroad[i]=lengthofroad[i];
        }else{maxcountofroad[i]=14499945;}


    }
    long minlength=lengthofroad[0];
    int minindex=0;
    for (int i = 0; i < row; i++) {
        if (minlength>maxcountofroad[i]) {
            minlength = maxcountofroad[i];
            minindex=i;
        }
    }
    QString tmp=rowainformation[minindex];
    result->insertPlainText(tmp);
}
//------------------------------3)Знайти всі дороги, в яких наявні розділювачі посередині, кількість смуг >2 та згрупувати за типом.-----------------------------------------------------------------------------------------------------------------------
void Road::Task3(QTableWidget *list, QTableWidget *result) {
    try{
        CheckSymb(5);
    }
    catch(WrongSymbolData){
        QMessageBox::critical(NULL, ("Error"),(WrongSymbolData().GetError()));
    }
    QString rowstmp[100];
    QStringList alltmp[1000];
    vector<QString> type_a;
    vector<QString> type_b;
    vector<QString> type_c;
    int step=0;
    for (int i = 0; i < row; i++) {
        if((dataforeachelement[i][5]=="+")&&(dataforeachelement[i][3].toLong()>2))
        {
            if((dataforeachelement[i][1]=="c"))
            {
                type_c.push_back(rowainformation[i]);
            }
            if((dataforeachelement[i][1]=="a"))
            {
                type_a.push_back(rowainformation[i]);

            }if((dataforeachelement[i][1]=="b"))
            {
                type_b.push_back(rowainformation[i]);
            }
            step++;
        }
    }
    QString tmpp[10000];
    int begin=0;
    int end=type_a.size();
    for (int i = begin; i < end; i++) {
        tmpp[i]=type_a[i];
    }
    begin=end;
    end+=type_b.size();
    int k=0;
    for (int i = begin; i < end; i++) {
        tmpp[i]=type_b[k];
        k++;
    }
    k=0;
    begin=end;
    end+=type_c.size();
    for (int i = begin; i < end; i++) {
        tmpp[i]=type_c[k];
        k++;
    }
    QStringList alldatatmp[end];
    for (int j = 0; j < end; j++) {
        alldatatmp[j] = tmpp[j].split(',');
    }
    for (int i = 0; i < end; i++) {
        for (int j = 0; j < columns; j++) {
            result->item(i,j)->setText(alldatatmp[i][j]);
        }
    }
}
//-----------------5)Визначити автомобільні дороги з найбільшою кількістю смуг та наявними пішохідними доріжками які належать до регіональних.---------------------------------------------------------------------------------------------------------------------------------------------------------------
void Road::Task5(QTableWidget *list, QTableWidget *result) {
    try{CheckSymb(4); }
    catch(WrongSymbolData){
        QMessageBox::critical(NULL, ("Error"), (WrongSymbolData().GetError()));
    }
    vector<QString> rowswithmaxroadsandzebra;
    QStringList alldatatmp[100];

    for (int i = 0; i < row; i++) {
        if((dataforeachelement[i][5]=="+")&&(dataforeachelement[i][1]=="a"))
        {
            rowswithmaxroadsandzebra.push_back(rowainformation[i]);
        }
    }
    for (int j = 0; j < rowswithmaxroadsandzebra.size(); j++) {
        alldatatmp[j] = rowswithmaxroadsandzebra[j].split(',');
    }
    long max=0;
    for (int i = 0; i < rowswithmaxroadsandzebra.size(); i++) {
        if(max<alldatatmp[i][3].toLong())
        {
            max=alldatatmp[i][3].toLong();
        }
    }
    int step=0;
    for (int i = 0; i < rowswithmaxroadsandzebra.size(); i++) {
        if(alldatatmp[i][3].toLong()==max)
        {
            for (int j = 0; j < columns; j++) {
                result->item(step,j)->setText(alldatatmp[i][j]);
            }
            step++;
        }
    }
}
//----------4)Визначити типи автомобільних доріг, з найбільшою протяжністю та наявністю пішохідних доріжок.-------------------------------------------------------------------------------------------------------------------------------------------
void Road::Task4(QTableWidget *list, QTableWidget *result) {
    try{
        CheckSymb(4);
    }
    catch(WrongSymbolData){
        QMessageBox::critical(NULL, ("Error"),
                              (WrongSymbolData().GetError()));
    }
    Compare(list,result,"a",0);
    Compare(list,result,"b",1);
    Compare(list,result,"c",2);
}
//------------------------Порівняти елементи до 4 лаби-----------------------------------------------------------------------------------------------------------------------------
void Road::Compare(QTableWidget *list,QTableWidget *result,QString tocompare,int step) {
    bool flag=0;
    vector<int> datatmp;
    int max=0;
    int index=0;
    for (int i = 0; i < row; i++) {
        if((dataforeachelement[i][4]=="+")&&(dataforeachelement[i][1]==tocompare))
        {
            if(max<dataforeachelement[i][2].toInt())
            {
                max=dataforeachelement[i][2].toInt();
                index=i;
            }
            flag=1;
        }
    }
    if(flag!=0) {
        for (int j = 0; j < columns; j++) {
            result->item(step,j)->setText(dataforeachelement[index][j]);
        }
    }
}
//------------------------міняємо місцями-----------------------------------------------------------------------------------------------------------------------------

void Road::GetData(int p1,int p2) {
    QString texttmp;
    for (int i = 0; i < columns; i++) {
        texttmp=dataforeachelement[p1][i];
        dataforeachelement[p1][i]=dataforeachelement[p2][i];
        dataforeachelement[p2][i]=texttmp;
    }
}
//------------------------оператор виводу-----------------------------------------------------------------------------------------------------------------------------
std::ostream & operator <<(std::ostream & output, Road const& obj)
{

    for (int i = 0; i < obj.row; i++) {

        QString str1 = obj.rowainformation[i];
        QByteArray ba = str1.toLocal8Bit();
        const char *c_str2 = ba.data();
        output <<  c_str2<<"\n";

    }

    return output;
}
//------------------------оператор ввводу-----------------------------------------------------------------------------------------------------------------------------
std::istream &operator>>(istream &stream,  Road &obj) {
    std::string temp;
    //    try{
    //        long file_size;
    //        stream.seekg(0, ios::end);
    //        file_size = stream.tellg();
    //        if (file_size == 0)
    //            throw CEmptyFile ();
    //                stream.seekg(0);
    //                while(!stream.eof())
    //                {
    //                    getline(stream, temp);
    //                }
    //                //        QString qstr = QString::fromStdString(temp);
    //                obj.bls = QString::fromStdString(temp);
    //                cout<<temp;
    //    }
    //    catch (CEmptyFile &ef)
    //    {
    //        QMessageBox::critical(NULL, ("Error"),
    //                              ("EmptyFile"));
    //    }
vector<string> tmpp;


        std::getline(stream, temp); // getline from <string>

   //QString qstr = QString::fromStdString(temp);
int count=0;

    int n = temp.length();

    // declaring character array
    char char_array[n + 1];

    // copying the contents of the
    // string to char array
    strcpy(char_array, temp.c_str());
    for (int i = 0; i < n+1; i++) {
if(char_array[i]=='|'){
count++;}

    }
      obj.row=count;
   obj.alldata=QString::fromStdString(temp);

obj.Divide();
obj.checkinitialisation=true;
      return stream;
}
//    QFile inputFile(fileName);
//    if (inputFile.open(QIODevice::ReadOnly))
//    {
//       QTextStream in(&inputFile);
//       while (!in.atEnd())
//       {
//          QString line = in.readLine();
//          ...
//       }
//       inputFile.close();
//    }


void Road::Divide()
{
    this->rowainformation = this->alldata.split('|');
    for (int j = 0; j <this-> row; j++) {
   this->dataforeachelement[j] =this->rowainformation[j].split(',');
    }

    for (int i = 0; i <this->row; i++) {
      this->lengthofroad[i]=this->dataforeachelement[i][2].toLong();
    }
    for (int i = 0; i <this-> row; i++) {
     this-> countofroad[i]=this->dataforeachelement[i][3].toLong();
    }
}
void Road::ReadFromFile(Road obj) {
    //    QString filename="/Users/oksanaspodarik/Desktop/kursova.txt";
    //    QFile inputFile( filename );

    //    QTextStream in(&inputFile);
    //    while (!in.atEnd())
    //    {
    //        all = in.readLine();
    //    }
    //    inputFile.close();

    //    rowainformation = all.split('\n');


    //    for (int j = 0; j < row; j++) {
    //        obj.dataforeachelement[j] = rowainformation[j].split(',');
    //    }
}










