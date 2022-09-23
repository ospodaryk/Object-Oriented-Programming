#include "drib.h"
#include <QStringList>
#include <QMessageBox>


Fraction::Fraction()
{
   numberOfFraction++;
}

Fraction::Fraction(int numerator, int denumerator)
{
    this->numerator = numerator;
    this->denumerator = denumerator;
}


Fraction::Fraction(const Fraction &fraction){
    this->numerator=fraction.numerator;
    this->denumerator=fraction.denumerator;
}
int Fraction::getNumerator()const
{
    return numerator;
}

int Fraction::getDenuminator()const
{
    return denumerator;
}

void Fraction::setNumerator(int numerator)
{
    this->numerator = numerator;
}

void Fraction::setDenumerator(int denumerator)
{
    this->denumerator = denumerator;
}


Fraction Fraction::add(const Fraction &fraction) const
{

    Fraction c;
    c.numerator = (fraction.denumerator  *numerator+denumerator  *fraction.numerator);
    c.denumerator = (fraction.denumerator *denumerator );

    c.reduce();
    return c;}

Fraction Fraction::minus(const Fraction &fraction) const
{
    Fraction c;
    c.numerator = (fraction.denumerator * numerator) -(denumerator * fraction.numerator);
    c.denumerator =  denumerator*fraction.denumerator;
    c.reduce();
    return c;
}

Fraction Fraction::multiply(const Fraction &fraction) const
{
    Fraction c;
    c.numerator =  fraction.numerator * numerator;
    c.denumerator =  fraction.denumerator * denumerator;
    c.reduce();
    return c;
}

Fraction Fraction::divide(const Fraction &fraction) const
{
    Fraction c;
    c.numerator =  numerator * fraction.denumerator ;
    c.denumerator = denumerator * fraction.numerator;
    c.reduce();
    return c;
}

Fraction Fraction::inverse()
{
    Fraction c;
    c.numerator = denumerator;
    c.denumerator = numerator;
    return c;
}

QString Fraction::toString()const
{
    QString FractionString =  QString::number(numerator) + "/" + QString::number(denumerator);
    return FractionString;
}

void Fraction::fromString(QString str)
{
        QStringList number = str.split('/');
        numerator = number[0].toInt();
        denumerator = number[1].toInt();
}

void Fraction::reduce() {
    int n = fabs(numerator);
    int d = fabs(denumerator);
   while(n!=0 && d!=0){
    if (n > d) {
        n %= d;
    } else if (n < d) {
        d %= n;
    }}
    int NSD = n + d;
    numerator /= NSD;
    denumerator /= NSD;

}

//    int a=fabs(numerator);
//    int b= fabs(denumerator);

//    for (long i = a; i > 0; i--) {
//                if (a % i == 0 && b % i == 0) {
//                    b = b / i;
//                    a = a / i;
//                    break;
//                }
//            }

//    numerator = a;
//    denumerator = b;}


Fraction Fraction::operator+(const Fraction &fraction)
{
    return this->add(fraction);
}

Fraction Fraction::operator-(const Fraction &fraction)
{
    return this->minus(fraction);
}


Fraction Fraction::operator*(const Fraction &fraction)
{
    return this->multiply(fraction);
}

Fraction Fraction::operator/(const Fraction &fraction)
{
    return this->divide(fraction);
}

Fraction Fraction::operator!()
{
    return this->inverse();
}


void Fraction::operator =(const Fraction &fraction){
   numerator=fraction.numerator;
   denumerator=fraction.denumerator;
}
































