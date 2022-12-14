#include "mainwindow.h"
#include "road.h"

#include <QApplication>
//Автомобільна дорога |  Тип (державна/регіональна/обласна/місцева) |  Протяжність | Кількість смуг |  Наявність пішохідної доріжки |  Наявність розділювача посередині дороги



//++++++++++++++++++++++++++++++++++++++++++++++++++++1)      Впорядкувати дороги за протяжністю.

//+++++++++++++++++++++++++++++++++++++++++++++++++++2)    Знайти найкоротшу дорогу, де найбільша кількість смуг.

//+++++++++++++++++++++++++++++++++++++++++++++++++++3)      Знайти всі дороги, в яких наявні розділювачі посередині, кількість смуг >2 та згрупувати за типом.

//++++++++++++++++++++++++++++++++++++++++++++++++4)      Визначити типи автомобільних доріг, з найбільшою протяжністю та наявністю пішохідних доріжок.

//++++++++++++++++++++++++++++++++++++++++++++++++5)      Визначити автомобільні дороги з найбільшою кількістю смуг та наявними пішохідними доріжками які належать до регіональних.

//Для класу створити: ++1) Конструктор за замовчуванням; +++2) Конструктор з параметрами; +++3) конструктор копій; 4) перевизначити операції >>, << для зчитування та запису у файл.


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
