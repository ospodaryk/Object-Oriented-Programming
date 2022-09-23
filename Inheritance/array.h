#ifndef ARRAY_H
#define ARRAY_H
#include <QMessageBox>
#include <QTableWidgetItem>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>
#define SIZE 5
using std::cout;
using std::endl;

class Array
{
public:

    virtual ~Array() { };
    Array &operator=(const Array &other) = delete;
    virtual int findElement(int position)const;
    virtual int operator[](int index) const = 0;
    virtual int operator[](int index) = 0;
    virtual void add(int newElement)=0;
    virtual void clear() = 0;
    virtual int  getLength() const;
    virtual void print() const;
    Array &operator+=(int element);
    virtual void setElementAtPosition(int index, int element) = 0;
    virtual void InsertElementAtPosition( int element,int position)=0;

protected:
    virtual void changeSize(int capacity) = 0;
    void checkBounds(int index) const;
    void printData() const;
    int length = 0;
};

std::ostream &operator<<(std::ostream &output, const Array &toWrite);


#endif // ARRAY_H
