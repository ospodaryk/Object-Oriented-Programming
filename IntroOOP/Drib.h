#ifndef fraction_H
#define fraction_H
#include <QString>
#include <QLineEdit>

class Fraction
{
    friend void operator<<(QLineEdit *edit,const Fraction &fraction);
    friend void operator>>(QLineEdit *edit, const Fraction &fraction);
    friend bool operator>(const Fraction &a, const Fraction &b);
    friend bool operator<(const Fraction &a, const Fraction &b);
    friend bool operator==(const Fraction &a, const Fraction &b);
private:
    int denumerator;
      int numerator;
public:
    static unsigned int    numberOfFraction;
    Fraction();
    Fraction(int numerator, int denumeratot);
    Fraction(const Fraction &fraction);

    void setNumerator(int numerator);

    void setDenumerator(int denuminator);

    int getNumerator()const;
    int getDenuminator()const;
    Fraction add(const Fraction &fraction)const;
    Fraction minus(const Fraction &fraction) const;
    Fraction multiply(const Fraction &fraction) const;
    Fraction divide(const Fraction &fraction) const;
    Fraction inverse();
    Fraction operator+(const Fraction &fraction);
    Fraction operator-(const Fraction &fraction);
    Fraction operator*(const Fraction &fraction);
    Fraction operator/(const Fraction &fraction);
    Fraction operator!();
    void operator=(const Fraction &fraction);
    QString toString()const;
    void fromString(QString str);
    void reduce();
};

#endif // fraction_H
