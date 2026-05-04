#include <iostream> 
#include "cl_1.h"
using namespace std;

int main() {
    int first, second;

        cout << "Введите номинал купюры: " << endl;
    cin >> first;
    cout << endl;

    cout << "Введите кол-во купюр данного достоинства: ";
    cin >> second;
    cout << endl;


    ATM at;

    cout << at.summa(first, second) << endl;

    return 0;
}