#include "array.h"
#include"simplearray.h"
#include"plural.h"
Array::Array()  {

}

Array::Array(int a)  {
    arr = new int[length];
    if (arr == nullptr) {
        QMessageBox::warning(NULL, "Error", "Memory couldn't be allocated");
    }
}


Array::Array(const Array &a) {
    length = a.length;
    arr = new int[length];
    for (int i = 0; i < length; i++) {
        arr[i] = a.arr[i];
    }
}

Array::~Array() {
    delete[]arr;
};

int Array::getLength() const {
    return length;
}


void Array::ReadString(QTextEdit *edit) {
    QStringList split = edit->toPlainText().split(',');
    length = split.size();
    arr = new int[length];
    for (int i = 0; i < length; i++) {
        arr[i] = split[i].toInt();
    }
}

void Array::DisplayString(QTextEdit *edit) const {
    QString str = "";
        for (int i = 0; i < length; i++) {
            str += QString::number(arr[i]);
            if (i != length - 1) {
                str += ",";
            }
        }

    edit->setPlainText(str);
}

void Array::Add(int value) {
    int *arr_new = new int[length + 1];
    for (int i = 0; i < length + 1; i++) {
        arr_new[i] = arr[i];
        if (i == length) {
            arr_new[i] = value;
        }
    }
    delete[] arr;
    length++;
    arr = arr_new;
}

int Array::GetPosition(int value) const {
    for (int i = 0; i < length; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return 404;
}
