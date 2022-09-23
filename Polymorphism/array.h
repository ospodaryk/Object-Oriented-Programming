#ifndef ARRAY_H
#define ARRAY_H

#include<limits.h>
#include<QTextEdit>
#include<QStringList>
#include<QMessageBox>
#include<QString>

//Тут базовий клас містить методи визначення кількості елементів, додавання елемента, перевірки
//наявності елемента в масиві. SimpleArray – реалізація як масиву, тобто, add(Element) додає
//елемент в кінець, в SetArray – додає, якщо такого елемента немає. Також, SetArray зберігає
//сортовано елемнети, що пришвидшує пошук, SimpleArray – просто послідовно додає.
class Array {
protected:
    int length=0;
    int *arr;
public:
    Array();

    Array(int a);

    Array(const Array &a);

    virtual ~Array();

    int getLength() const;

    void ReadString(QTextEdit *edit);

    void DisplayString(QTextEdit *edit) const;

   virtual void Add(int value);

    int GetPosition(int value) const;


};


#endif // ARRAY_H
