#ifndef OPTIMIZEDARRAY_H
#define OPTIMIZEDARRAY_H
#include <array.h>


class OptimizedArray: public Array {
public:
    OptimizedArray();
    OptimizedArray(int initialBlockSize);
    ~OptimizedArray();
    int operator[](int index) const;
    int operator [](int index);
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
     int currentBlockSize = 1;
    void alloc(int expectedCapacity);
};
#endif // OPTIMIZEDARRAY_H
