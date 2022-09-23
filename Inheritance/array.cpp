#include "array.h"
#include <QMessageBox>


int Array::getLength() const {
    return length;
}

int Array::findElement(int position) const {
    checkBounds(position);
    return (*this)[position];
}


void Array::print() const {
    printData();
}


Array &Array::operator+=(int element) {
    this->add(element);
    return *this;
}

void Array::printData() const {
    if (getLength() > 0) {
        for (int i = 0; i < getLength() - 1; ++i) {
            cout << (*this)[i] << ", ";
        }
        cout << (*this)[getLength() - 1];
    }
}

void Array::checkBounds(int index) const {
    if (index < 0 || index >= getLength()) {
        QMessageBox::warning(NULL, "ERROR", "Виходить за межі масиву");
    }
}

std::ostream &operator<<(std::ostream &output, const Array &toWrite) {
    output << "[";
    const int len = toWrite.getLength();

    if (len != 0) {
        output << toWrite[0];
        for (int i = 1; i < len; ++i) {
            output << "," << toWrite[i];
        }
    }
    output << ']' << endl;
    return output;
}
