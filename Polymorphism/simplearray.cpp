#include "simplearray.h"
#include"array.h"

SimpleArray::SimpleArray() : Array() {

}

SimpleArray::SimpleArray(int a) : Array(a) {

}

SimpleArray::~SimpleArray() {
    delete[] arr;
}

