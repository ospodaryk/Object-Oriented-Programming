#include "settext.h"
#include"array.h"

SetArray::SetArray() : SimpleArray()  {

}

SetArray::SetArray(int a) : SimpleArray(a) {

}

SetArray::~SetArray() {
    delete[] arr;
}









void SetArray::Add(int value){
    int check=this->Check(value);
    if (check == 1) {
        int *arr_new = new int[length + 1];
        for (int i = length+1; i >0; i--) {
            arr_new[i]=arr[i];
            if (value<=arr[i]){
                for(int k=length+1; k>i; k--)
                {   arr_new[k] = arr[k-1];}
                arr_new[i]=value;
            }else{ arr_new[length]=value;
            }}

        delete[] arr;
        length++;
        arr = arr_new;}
}




void SetArray::Sort() {
    int *arr_new = new int[length];
    for (int i = 0; i < length; i++) {
        arr_new[i] = arr[i];
    }
    int temp = 0;
    for (int i = 0; i < length - 2; i++)
        for (int j = 0; j < length - i - 1; j++) {
            if (arr_new[j] > arr_new[j + 1]) {
                temp = arr_new[j];
                arr_new[j] = arr_new[j + 1];
                arr_new[j + 1] = temp;
            }
        }
    delete[] arr;
    arr = arr_new;
}

int SetArray::Check(int value) const {
    int k = 1;
    for (int i = 0; i < length; i++) {
        if (arr[i] == value) {
            k = 0;
            break;
        }
    }
    return k;
}
