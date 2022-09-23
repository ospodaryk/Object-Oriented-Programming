#pragma once
#include <iostream>
#include <exception>
#include <limits>
#include <iomanip>
#include "MyException.h"

using namespace std;

template <typename T>
inline void check(T& a) {
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Невірно введені дані. Спробуйте ще : "<< endl;
        cin >> a;
    }
}
class MyMatrix
{
private:
    double** matrix;
    int column, row;
public:
    MyMatrix();

    MyMatrix(int r,int c);

    MyMatrix(const MyMatrix& other);

    void create(int r, int c);

    void initialisation();

    void initialisation(const MyMatrix& other);

    void clear();

    void showmatrix() const;

    int GetColumn() const;

    int GetRow() const;

    double& operator()(int row, int column);

    double& operator()(int row, int column) const;

    MyMatrix& operator=(const MyMatrix& other);

    MyMatrix operator+(const MyMatrix& other);

    MyMatrix operator-(const MyMatrix& other);

    MyMatrix operator*(const MyMatrix& other);

    MyMatrix& inverse();

    ~MyMatrix();
};

