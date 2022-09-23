#include "MyMatrix.h"
int main() {
    srand(time(NULL));
    cout << "Початковий масив  " << endl;
    int countofrow, countofcolumn;
    cout << "Кількість рядків : ";
    cin >> countofrow;
    cout << "Кількість стовпців : ";
    cin >> countofcolumn;
    MyMatrix matr(countofrow, countofcolumn);
    matr.initialisation();
    matr.showmatrix();
    cout << "+,-,*,Обернути матрицю?(і)" << endl;
    char tmp;
    do {
        cin >> tmp;
        check(tmp);
    } while (tmp != '+' && tmp != '-' && tmp != '*' && tmp != 'i');
    MyMatrix Temp;
    MyMatrix Res1;

    switch (tmp) {
        case 'i':
            Res1 = matr.inverse();
            cout << "Обернена матриця : " << endl;
            Res1.showmatrix();
            break;
        default:
            MyMatrix other;
            MyMatrix Res;
            other.create(countofrow, countofcolumn);
            cout << "Додатковий масив " << endl;
            other.initialisation();
            other.showmatrix();
            switch (tmp) {
                case '+':
                    Res = matr + other;
                    break;
                case '-':
                    Res = matr - other;
                    break;
                case '*':
                    Res = matr * other;
                    break;
            }
            cout << "Результат дії " << tmp << endl;
            Res.showmatrix();
            break;
    }
}
