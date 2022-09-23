#ifndef SIMPLEARRAY_H
#define SIMPLEARRAY_H
#include <array.h>


class SimpleArray: public Array {
public:

    SimpleArray();
    SimpleArray(int initialSize);
    ~SimpleArray();
    int operator[](int index) const;
    int operator[](int index);
    void add(int newElement);
    void clear();
    void print() const;
    void setElementAtPosition(int index, int element);
    void InsertElementAtPosition( int element,int position);

protected:
    void changeSize(int capacity);

private:
    int capacity = 0;
    int *array = nullptr;
    void alloc(int expectedCapacity);
};

#endif // SIMPLEARRAY_H
