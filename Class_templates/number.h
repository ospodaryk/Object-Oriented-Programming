
#include <iostream>

template<class T>
class Number;

template<class T>
std::ostream &operator<<(std::ostream &, const Number<T> &current);

template<class T>
class Number {
private:
    T data;
public:
    Number();

    Number(T number);

    const Number operator+(const Number &other) const;

    const Number operator-(const Number &other) const;

    const Number operator*(const Number &other) const;

    Number &operator=(const Number &other);

    int operator<(const Number &other) const;
    friend std::ostream &operator<<<T>(std::ostream &out,const Number &current);
};
template<class T>
Number<T>::Number() {}

template<class T>
Number<T>::Number(T number) {
    this->data = number;
}

template<class T>

const Number<T> Number<T>::operator+(const Number<T> &other) const {
    return Number(this->data + other.data);
}

template<class T>
const Number<T> Number<T>::operator-(const Number<T> &other) const {
    return Number(this->data - other.data);
}

template<class T>
Number<T> &Number<T>::operator=(const Number<T> &other) {
    this->data = other.data;
    return *this;
}

template<class T>
const Number<T> Number<T>::operator*(const Number<T> &other) const {
    return Number(this->data * other.data);
}

template<class T>
int Number<T>::operator<(const Number<T> &other) const {
    if (this->data < other.data) {
        return 1;
    }
    return 0;
}

template<class T>
std::ostream &operator<<(std::ostream &out, const Number<T> &current) {
    out << current.data;
    return out;
}
