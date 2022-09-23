
#include <iostream>

class Complex {
private:
    double number;
    double complex;
public:
    Complex();
    ~Complex();

    Complex(double a, double b);

    double GetModule() const;

    const Complex operator+(const Complex &other) const;

    const Complex operator-(const Complex &other) const;

    const Complex operator*(const Complex &other) const;

    Complex &operator=(const Complex &other);

    int operator==(const Complex &other) const;

    int operator<(const Complex &other) const;

    friend std::ostream &operator<<(std::ostream &out, Complex current);

    std::string ToString() const;

};
