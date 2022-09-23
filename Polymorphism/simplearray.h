#ifndef SIMPLEARRAY_H
#define SIMPLEARRAY_H

#include"array.h"
#include<limits.h>
#include<QMessageBox>

class SimpleArray : public Array {
public:
    SimpleArray();

    SimpleArray(int a);

    ~SimpleArray();
};

#endif // SIMPLEARRAY_H
