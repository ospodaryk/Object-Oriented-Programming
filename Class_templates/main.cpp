#include "complex.h"
#include "number.h"
#include <iostream>

#include <iostream>
using namespace std;
int main()
{
    Number <Complex> first(Complex(21,-5));
    Number <Complex> second(Complex(3,2));
    cout << "First number: " << first << endl;
    cout << "Second number: " << second << endl;
    Number <Complex> result;
    result = first + second;
    cout << "First + second = " << result << endl;
    result = first * second;
    cout << "First * second = " << result << endl;
    int check = second < first;
    if( check==0) { cout << "Second is bigger"<<endl << endl << endl; }
    else {cout << "First is bigger"<<endl << endl;}

    Number < Number <Complex>> fourth(Complex(0,1));
    Number < Number <Complex>>fifth(Complex(2,-1));
    cout << "Fourth number: " << fourth << endl;
    cout << "Fifth number: " << fifth << endl;
    Number < Number <Complex>> sixth;
    sixth = fourth + fifth;
    cout << "Sixth number: " << sixth << endl;

    return 0;
}
