#include "MyMatrix.h"

MyMatrix::MyMatrix() {
    this->column = 0;
    this->row = 0;
    matrix = nullptr;
}

MyMatrix::MyMatrix(int r, int c) {
    this->row = r;
    this->column = c;
    matrix = new double *[r];
    for (int i = 0; i < r; i++) {
        matrix[i] = new double[c];
        for (int j = 0; j < c; j++) {
            matrix[i][j] = 0;
        }
    }
}

void MyMatrix::create(int r, int c) {
    this->clear();
    this->row = r;
    this->column = c;
    matrix = new double *[r];
    for (int i = 0; i < r; i++) {
        matrix[i] = new double[c];
        for (int j = 0; j < c; j++) {
            matrix[i][j] = 0;
        }
    }
}

void MyMatrix::initialisation(const MyMatrix &other) {

    this->clear();
    this->column = other.column;
    this->row = other.row;
    matrix = new double *[row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new double[column];
        for (int j = 0; j < column; j++) {
            matrix[i][j] = other(i, j);
        }
    }
}

void MyMatrix::initialisation() {
    if (matrix) {
        char symb;
        cout << "Ініціалізувати рандомними числами? (1-Так,0-Ні) ";
        cin >> symb;
        switch (symb) {
            case '1':
                for (int i = 0; i < row; i++) {
                    for (int j = 0; j < column; j++) {
                        matrix[i][j] = (rand() % 100) * 1.0;
                    }
                }
                break;
            case '0':
                for (int i = 0; i < row; i++) {
                    for (int j = 0; j < column; j++) {
                        cout << "matr[" << i + 1 << "][" << j + 1 << "] = ";
                        cin >> matrix[i][j];
                        check(matrix[i][j]);
                    }
                }
        }
    }
}

void MyMatrix::showmatrix() const {
    if (matrix) {
        cout << "_______________________________________________________________" << endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                printf(" %14lf ", matrix[i][j]);
            }
            cout << endl;
        }
        cout << "_______________________________________________________________" << endl;
    } else throw ("Матриця порожня");

}

int MyMatrix::GetColumn() const {
    return this->column;
}

int MyMatrix::GetRow() const {
    return this->row;
}


double &MyMatrix::operator()(int row, int column) {
    if ((row >= this->row) || (row < 0) || (column >= this->column) || (column < 0)) {
        throw out_of_range("Вихід за межі масиву");
    }
    return matrix[row][column];
}

double &MyMatrix::operator()(int row, int column) const {
    if (row >= this->row || row < 0 || column >= this->column || column < 0) {
        throw out_of_range("Вихід за межі масиву");
    }
    return matrix[row][column];
}

MyMatrix &MyMatrix::operator=(const MyMatrix &other) {
    if (&other == this) {
        return *this;
    }
    if (this->row == other.GetRow() && this->column == other.GetColumn()) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                matrix[i][j] = other(i, j);
            }
        }
    } else {
        this->initialisation(other);
    }
    return *this;
}

MyMatrix MyMatrix::operator+(const MyMatrix &other) {
    MyMatrix result(row, column);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            result(i, j) = matrix[i][j] + other(i, j);
        }
    }
    return result;
}

MyMatrix MyMatrix::operator-(const MyMatrix &other) {
    MyMatrix result(row, column);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            result(i, j) = matrix[i][j] - other(i, j);
        }
    }
    return result;
}

MyMatrix MyMatrix::operator*(const MyMatrix &other) {
    MyMatrix result(row, other.column);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < other.column; j++) {
            for (int k = 0; k < column; k++) {
                result(i, j) += matrix[i][k] * other(k, j);
            }
        }
    }
    return result;
}

MyMatrix &MyMatrix::inverse() {
    if (row != column) {
        throw std::length_error("Кількість рядків повинна бути рівна кількості стовпці");
    }
    double D;
    double **tmp = new double *[row];
    for (int i = 0; i < column; i++)
        tmp[i] = new double[row];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++) {
            tmp[i][j] = 0.0;
            if (i == j)
                tmp[i][j] = 1.0;
        }
    for (int k = 0; k < row; k++) {
        D = matrix[k][k];
        if (D == 0) {
            throw MyException("Визначник = 0 ");
        }
        for (int j = 0; j < column; j++) {
            matrix[k][j] /= D;
            tmp[k][j] /= D;
        }

        for (int i = k + 1; i < row; i++) {
            D = matrix[i][k];
            for (int j = 0; j < column; j++) {
                matrix[i][j] -= matrix[k][j] * D;
                tmp[i][j] -= tmp[k][j] * D;
            }
        }
    }
    for (int k = row - 1; k > 0; k--) {
        for (int i = k - 1; i >= 0; i--) {
            D = matrix[i][k];
            for (int j = 0; j < column; j++) {
                matrix[i][j] -= matrix[k][j] * D;
                tmp[i][j] -= tmp[k][j] * D;
            }
        }
    }
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            matrix[i][j] = tmp[i][j];
    for (int i = 0; i < column; i++)
        delete[] tmp[i];
    delete[] tmp;
    return *this;
}

void MyMatrix::clear() {
    if (matrix) {
        for (int i = 0; i < row; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    this->row = 0;
    this->column = 0;
}


MyMatrix::~MyMatrix() {
    clear();
}
