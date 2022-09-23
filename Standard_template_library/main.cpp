#include <iostream>
#include <vector>
#include <set>
#include <list>

using namespace std;

void printm(multiset<double> &mst);
void printv(vector<double> &array);
bool IsOdd (int i) {return ((i%2)==1);}
int main() {
    multiset<double> mst1 = {1.3, 2.4, 3.9, 4.6, 5.356, 6.39, 7.2, 8.11, 9.22, 10.5};
    printm(mst1);
    double choice;
    cout << "Введіть елемент для видалення ";
    cin >> choice;
    mst1.erase(choice);
    printm(mst1);
    cout << "Введіть елемент для введення ";
    cin >> choice;
    mst1.insert(choice);
    printm(mst1);
    multiset<double>::iterator iter;
    multiset<double> mst2 = {0.3, 2.4, 31.9, 14.6, 15.356, 16.39, 71.2, 18.11, 19.22, 20.5};
    int n;
    cout << "Введіть кількість елементів для видалення ";
    cin >> n;
    int afterPosition;
    cout << "Введіть позицію після якої видалити елементи ";
    cin >> afterPosition;
    multiset<double>::iterator ip = mst1.begin();
    for (int i = 0; i < afterPosition; i++) {ip++;}
    multiset<double>::iterator in = ip;
    for (int i = 0; i < n; i++) {in++;}
    mst1.erase(ip, in);
    printm(mst1);
    mst1.insert(mst2.begin(), mst2.end());
    cout << "=======Перший multiset=======" << endl;
    printm(mst1);
    cout << "=======Другий multiset=======" << endl;
    printm(mst2);
    cout << "\nВідсортований перший ĸонтейнер по спаданню елементів " << endl;
    multiset<double, greater<double> > mst3;
    mst3.insert(mst1.begin(), mst1.end());
    multiset<double>::iterator itt;
    for (itt = mst3.begin(); itt != mst3.end(); itt++) { cout << *itt << " "; }
    cout << endl;
    vector<double> array;
    cout << "\n=======Перший вектор=======" << endl;
    multiset<double>::iterator find;
    find=find_if(mst3.begin(), mst3.end(),IsOdd);
    while(find!=mst3.end()){
        array.push_back(*find);
        find=find_if(++find, mst3.end(),IsOdd);
    }
swap(*array.begin(),*(array.end()-1));
    list<double> lis;

    copy(array.begin(),array.end(), back_inserter(lis));
    swap(*lis.begin(),*(--lis.end()));

    printv(array);

    sort(array.begin(), array.end());
    cout << "=======Перший контейнер=======" << endl;
    printm(mst1);
    cout << "\n=======Другий контейнер=======" << endl;
    printv(array);

    multiset<double> third(array.begin(), array.end());
    for (iter = mst1.begin(); iter != mst1.end(); iter++) {
        third.insert(*iter);
    }

    cout << "\n=======Третій контейнер=======" << endl;
    printm(third);
    int count=count_if(third.begin(), third.end(), IsOdd);
    cout << "Кількість елементів, що задовільянють заданій умові = " << count << endl;
}

void printv(vector<double> &array) {
    if (array.empty()) {
        cout << "multiset порожній";
        return;
    }
    vector<double>::iterator iter;
    for (iter = array.begin(); iter != array.end(); iter++) { cout << *iter << " "; }
    cout << endl;

}

void printm(multiset<double> &mst) {
    if (mst.empty()) {
        cout << "multiset порожній";
        return;
    }
    multiset<double>::iterator iter;
    for (iter = mst.begin(); iter != mst.end(); iter++) { cout << *iter << " "; }
    cout << endl;

}