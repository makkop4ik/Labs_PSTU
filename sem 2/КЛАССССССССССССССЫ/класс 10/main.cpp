#include "Time.h"
#include "file_work.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    char filename[80];
    int choice, res;

    do {
        cout << "\n--- Меню ---\n";
        cout << "1. Создать файл\n";
        cout << "2. Просмотреть файл\n";
        cout << "3. Удалить записи, не равные заданному значению\n";
        cout << "4. Уменьшить записи, равные заданному значению, на 1:30\n";
        cout << "5. Добавить K записей в начало файла\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Имя файла: "; cin >> filename;
            res = make_file(filename);
            if (res < 0) cout << "Ошибка создания файла!\n";
            else cout << "Файл создан, записано " << res << " записей.\n";
            break;

        case 2:
            cout << "Имя файла: "; cin >> filename;
            res = print_file(filename);
            if (res < 0) cout << "Ошибка открытия файла!\n";
            else if (res == 0) cout << "Файл пуст.\n";
            else cout << "Всего записей: " << res << endl;
            break;

        case 3: {
            cout << "Имя файла: "; cin >> filename;
            Time value;
            cout << "Введите интервал (значение, которому должны равняться записи для сохранения):\n";
            cin >> value;
            res = del_unequal(filename, value);
            if (res < 0) cout << "Ошибка открытия файла!\n";
            else cout << "Удалено записей, не равных " << value << ". Осталось: " << res << endl;
            break;
        }

        case 4: {
            cout << "Имя файла: "; cin >> filename;
            Time value;
            cout << "Введите интервал (значение, для которого будем уменьшать):\n";
            cin >> value;
            Time delta(1, 30);
            res = decrement_equal(filename, value, delta);
            if (res < 0) cout << "Ошибка открытия файла!\n";
            else cout << "Уменьшено записей, равных " << value << ": " << res << endl;
            break;
        }

        case 5: {
            cout << "Имя файла: "; cin >> filename;
            int k;
            cout << "Сколько записей добавить в начало? "; cin >> k;
            res = add_to_begin(filename, k);
            if (res < 0) cout << "Ошибка!\n";
            else cout << "Добавлено " << res << " записей в начало файла.\n";
            break;
        }

        case 0:
            cout << "До свидания!\n";
            break;

        default:
            cout << "Неверный выбор. Повторите.\n";
        }
    } while (choice != 0);

    return 0;
}