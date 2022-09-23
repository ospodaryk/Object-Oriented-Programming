#ifndef CLASS_EXCEPTION
#define CLASS_EXCEPTION

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

void CheckNumber(QString str1);

void CheckString(QString data);

void CheckSymbol(QString str1);

void CheckName(string name);

class Exception {
protected:
   QString mess;
public:
   Exception() : mess("Error!") {}

   Exception(QString m) : mess(m) {}

   ~Exception() {}

   QString GetError() const { return mess; }

   void SetMess(QString m) { mess = m; }
};

class WrongStringData : public Exception {
public:
   WrongStringData() : Exception("Wrong information!") {}

   WrongStringData(QString m) : Exception(m) {}

   ~WrongStringData() {}
};

class WrongNumberData : public Exception {

public:
   WrongNumberData() : Exception("Wrong number!") {}

   WrongNumberData(QString m) : Exception(m) {}

   ~WrongNumberData() {}
};

class WrongSymbolData : public Exception {
public:
   WrongSymbolData() : Exception("Wrong symbol!") {}

   WrongSymbolData(QString m) : Exception(m) {}

   ~WrongSymbolData() {}

   void SetInfoAboutError(char t_type, string t_number);
};
