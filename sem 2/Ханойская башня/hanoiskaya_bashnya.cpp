#include <iostream>
using namespace std;

void Hanoi(int N, char from, char to, char aux) {
    if (N == 1) {
        cout << "Передвинуть диск 1 с " << from << " на " << to << endl;
    } else {
        Hanoi(N - 1, from, aux, to);
        cout << "Передвинуть диск " << n << " с " << from << " на " << to << endl;
        Hanoi(N - 1, aux, to, from);
    }
}

int main() {
    int N;
    cout << "Введите число дисков: ";
    cin >> N;

    if (N <= 0) {
        cout << "О-оу! Что-то пошло не так!" << endl;
        return 1;
    }
    Hanoi(N, 'A', 'B', 'C');

    return 0;
}