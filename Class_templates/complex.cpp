#include "Complex.h"
#include <cmath>
#include <iostream>
#include <string>

Complex::Complex() {
    number = 0;
    complex = 0;
}

Complex::~Complex() {

}
Complex::Complex(double a, double b) {
    this->number = a;
    this->complex = b;
}


double Complex::GetModule() const {
     return (double) sqrt(this->number * this->number + this->complex * this-> complex);
    return sqrt(pow(this->number, 2) + pow(this->complex, 2));
}

const Complex Complex::operator+(const Complex &other) const {
    return Complex(this->number + other.number, this->complex + other.complex);
}

const Complex Complex::operator-(const Complex &second) const {
    return Complex(this->number - second.number, this->complex - second.complex);
}

const Complex Complex::operator*(const Complex &other) const {
    return Complex(this->number * other.number - this->complex * other.complex,
                   this->number * other.complex + other.number * this->complex);
}

int Complex::operator==(const Complex &second) const {
    if (this->number == second.number && this->complex == second.complex) {
        return 1;
    }
    return 0;
}

int Complex::operator<(const Complex &second) const {
    if (this->GetModule() < second.GetModule()) {
        return 1;
    }
    return 0;
}

Complex &Complex::operator=(const Complex &other) {
    this->number = other.number;
    this->complex = other.complex;
    return *this;
}


std::string Complex::ToString() const {
    std::string str;
    str = std::to_string(number) + " ";
    complex >= 0 ? str += "+" : str += "-";
    str += " " + std::to_string(abs(complex)) + "i";
    return str;
}

std::ostream &operator<<(std::ostream &out, Complex current) {
    out << current.ToString();
    return out;
}
