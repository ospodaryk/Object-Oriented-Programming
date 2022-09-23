#include "optimizedarray.h"

OptimizedArray::OptimizedArray() : OptimizedArray(SIZE) {
}
OptimizedArray::OptimizedArray(int initialBlockSize) :
    currentBlockSize(initialBlockSize) {
    alloc(initialBlockSize);
}

OptimizedArray::~OptimizedArray() {
    if (array == nullptr)
        return;
    free(array);
}
int OptimizedArray::operator[](int index) const {
    checkBounds(index);
    return array[index];
}


int OptimizedArray::operator[](int index) {
    checkBounds(index);
    return array[index];
}

void OptimizedArray::clear() {
    length = 0;
}

void OptimizedArray::setElementAtPosition(int index, int element) {
    array[index] = element;
}
void OptimizedArray::changeSize(int expectedCapacity) {
    if (expectedCapacity > capacity) {
        alloc(expectedCapacity);
    }
}
void OptimizedArray::alloc(int expectedCapacity) {
    int tempCapacity = capacity;
    while (tempCapacity < expectedCapacity) {
        tempCapacity += currentBlockSize;
        currentBlockSize++;
    }
    if (array == nullptr) {
        array = (int *) calloc(tempCapacity, sizeof (int));
    } else {
        array = (int *) realloc(array, tempCapacity * sizeof (int));
    }
    capacity = tempCapacity;
    QMessageBox::information(NULL, "INFORAMTION","Кількість об'єктів\n"+ QString::number(capacity));
}

void OptimizedArray::add(int newElement) {
    changeSize(length + 1);
    setElementAtPosition(length, newElement);
    ++length;
}
void OptimizedArray::InsertElementAtPosition( int element,int position) {
    int arrr[length];
    for(int i=position;i<length;i++){
        arrr[i]= array[i];
    }
    array[position] = element;
    changeSize(length + 1);
    for(int i=position;i<length;i++){
        array[i+1]=arrr[i];
    }
    length++;
}
void OptimizedArray::print() const {
    printData();
}
