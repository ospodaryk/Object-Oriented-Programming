#include "simplearray.h"

SimpleArray::SimpleArray() : SimpleArray(SIZE)  {
}

SimpleArray::SimpleArray(int initialSize) {
    if (initialSize == 0)
        return;
    alloc(initialSize);
}

SimpleArray::~SimpleArray() {
    if (array == nullptr)
        return;
    free(array);
}

int SimpleArray::operator[](int index) const {
    checkBounds(index);
    return array[index];
}

int SimpleArray::operator[](int index) {
    checkBounds(index);

    return array[index];
}
void SimpleArray::clear()
{
    length = 0;
}
void SimpleArray::add(int newElement) {
    changeSize(length + 1);
    setElementAtPosition(length, newElement);
    ++length;
}


void SimpleArray::alloc(int expectedCapacity) {
    if (array == nullptr) {
        array = (int *) calloc(expectedCapacity, sizeof (int));
    } else {
        array = (int *) realloc(array, expectedCapacity * sizeof (int));
    }
    capacity = expectedCapacity;
}

void SimpleArray::changeSize(int requiredCapacity) {
    if (requiredCapacity > capacity) {
        alloc(requiredCapacity);
    }
}

void SimpleArray::print() const {
    cout << "SimpleArray of length " << length << " (capacity: " << capacity << ")" << endl;
    printData();
}

void SimpleArray::setElementAtPosition(int index, int element) {
    array[index] = element;
}
void SimpleArray::InsertElementAtPosition( int element,int position) {
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


