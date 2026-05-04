#include <iostream>
using namespace std;


struct Node {
    int key;
    Node* prev;
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
        Node* p = new Node{ val, nullptr, nullptr };
        if (!head) {
            head = p;
            tail = p;
        }
        else {
            tail->next = p;
            p->prev = tail;
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
    Node* curr = head;

    while (curr && curr->key != key)
        curr = curr->next;

    if (!curr) {
        cout << "Элемент с ключом " << key << " не найден.\n";
        return;
    }


    if (curr == head) {
        head = head->next;
        if (head) head->prev = nullptr;
        delete curr;
        cout << "Элемент с ключом " << key << " удалён.\n";
        return;
    }


    if (curr->prev) curr->prev->next = curr->next;
    if (curr->next) curr->next->prev = curr->prev;
    delete curr;
    cout << "Элемент с ключом " << key << " удалён.\n";
}


void addBeforeKey(Node*& head, int newKey, int beforeKey) {
    Node* newNode = new Node{ newKey, nullptr, nullptr };


    if (!head) {
        head = newNode;
        cout << "Список был пуст, элемент добавлен.\n";
        return;
    }


    Node* curr = head;
    while (curr && curr->key != beforeKey)
        curr = curr->next;


    if (!curr) {

        Node* last = head;
        while (last->next) last = last->next;
        last->next = newNode;
        newNode->prev = last;
        cout << "Ключ " << beforeKey << " не найден. Элемент добавлен в конец списка.\n";
        return;
    }


    newNode->next = curr;
    newNode->prev = curr->prev;
    if (curr->prev)
        curr->prev->next = newNode;
    else
        head = newNode;
    curr->prev = newNode;

    cout << "Элемент " << newKey << " добавлен перед " << beforeKey << ".\n";
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

    // Создание
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