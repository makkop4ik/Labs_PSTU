#include <iostream>
using namespace std;


struct Node {
    int key;
    Node* next;
};


Node* createList() {
    Node* head = nullptr;
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    if (n <= 0) return nullptr;

    cout << "Введите " << n << " целых чисел:\n";
    Node* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        Node* p = new Node{ val, nullptr };
        if (!head) {
            head = p;
            tail = p;
        }
        else {
            tail->next = p;
            tail = p;
        }
    }
    return head;
}


void printList(Node* head) {
    if (!head) {
        cout << "Список пуст.\n";
        return;
    }
    cout << "Список: ";
    for (Node* p = head; p; p = p->next)
        cout << p->key << " ";
    cout << endl;
}


void deleteByKey(Node*& head, int key) {
    if (!head) {
        cout << "Список пуст, удаление невозможно.\n";
        return;
    }

    if (head->key == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Элемент с ключом " << key << " удалён.\n";
        return;
    }

    Node* prev = head;
    Node* curr = head->next;
    while (curr && curr->key != key) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) {
        cout << "Элемент с ключом " << key << " не найден.\n";
        return;
    }
    prev->next = curr->next;
    delete curr;
    cout << "Элемент с ключом " << key << " удалён.\n";
}


void addBeforeKey(Node*& head, int newKey, int beforeKey) {
    Node* newNode = new Node{ newKey, nullptr };

    if (!head) {
        head = newNode;
        cout << "Список был пуст, элемент добавлен.\n";
        return;
    }

    if (head->key == beforeKey) {
        newNode->next = head;
        head = newNode;
        cout << "Элемент " << newKey << " добавлен перед " << beforeKey << ".\n";
        return;
    }

    Node* prev = head;
    Node* curr = head->next;
    while (curr && curr->key != beforeKey) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) {

        prev->next = newNode;
        cout << "Ключ " << beforeKey << " не найден. Элемент добавлен в конец списка.\n";
    }
    else {
        prev->next = newNode;
        newNode->next = curr;
        cout << "Элемент " << newKey << " добавлен перед " << beforeKey << ".\n";
    }
}


void destroyList(Node*& head) {
    Node* p = head;
    while (p) {
        Node* next = p->next;
        delete p;
        p = next;
    }
    head = nullptr;
    cout << "Список уничтожен.\n";
}


int main() {
    setlocale(LC_ALL, "Russian");

    // Создание списка
    Node* myList = createList();
    printList(myList);


    int delKey;
    cout << "\nВведите ключ для удаления: ";
    cin >> delKey;
    deleteByKey(myList, delKey);
    printList(myList);


    int newKey, beforeKey;
    cout << "\nВведите новый элемент: ";
    cin >> newKey;
    cout << "Перед каким ключом вставить? ";
    cin >> beforeKey;
    addBeforeKey(myList, newKey, beforeKey);
    printList(myList);


    destroyList(myList);

    return 0;
}