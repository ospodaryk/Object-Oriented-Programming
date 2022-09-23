#ifndef SETTEXT_H
#define SETTEXT_H

#include"array.h"
#include"simplearray.h"

#include<QMessageBox>


class SetArray : public SimpleArray {
public:
    SetArray();

    SetArray(int a);

    ~SetArray();

    void Add(int value);

     private:

    void Sort();

    void swap(int *xp, int *yp);

    int Check(int value)const;

};


#endif // SETTEXT_H
