#include <iostream>
using namespace std;

struct StackNode {
    int key;
    StackNode* next;
};

class Stack {
private:
    StackNode* top;
public:
    Stack() : top(nullptr) {}
    ~Stack() {
        while (!isEmpty()) pop();
    }
    void push(int val) {
        StackNode* newNode = new StackNode{ val, top };
        top = newNode;
    }
    int pop() {
        if (isEmpty()) return -1;
        int val = top->key;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
    int peek() {
        if (isEmpty()) return -1;
        return top->key;
    }
    bool isEmpty() {
        return top == nullptr;
    }
    void clear() {
        while (!isEmpty()) pop();
    }
};

void createStack(Stack& s) {
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    if (n <= 0) return;
    cout << "Введите " << n << " целых чисел:\n";
    int* arr = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = n - 1; i >= 0; --i)
        s.push(arr[i]);
    delete[] arr;
}

void printStack(Stack& s) {
    if (s.isEmpty()) {
        cout << "Стек (список) пуст.\n";
        return;
    }
    Stack temp;
    Stack temp2;
    while (!s.isEmpty())
        temp.push(s.pop());
    cout << "Стек (список): ";
    while (!temp.isEmpty()) {
        int val = temp.pop();
        cout << val << " ";
        s.push(val);
    }
    cout << endl;
}

void deleteByKey(Stack& s, int key) {
    if (s.isEmpty()) {
        cout << "Стек пуст, удаление невозможно.\n";
        return;
    }
    Stack aux;
    bool found = false;
    while (!s.isEmpty()) {
        int val = s.pop();
        if (!found && val == key) {
            found = true;
            continue;
        }
        aux.push(val);
    }
    while (!aux.isEmpty())
        s.push(aux.pop());
    if (found)
        cout << "Элемент с ключом " << key << " удалён.\n";
    else
        cout << "Элемент с ключом " << key << " не найден.\n";
}

void addBeforeKey(Stack& s, int newKey, int beforeKey) {
    if (s.isEmpty()) {
        s.push(newKey);
        cout << "Стек был пуст, элемент добавлен.\n";
        return;
    }
    Stack aux;
    bool found = false;
    while (!s.isEmpty()) {
        int val = s.pop();
        if (!found && val == beforeKey) {
            aux.push(newKey);
            found = true;
        }
        aux.push(val);
    }
    while (!aux.isEmpty())
        s.push(aux.pop());
    if (found)
        cout << "Элемент " << newKey << " добавлен перед " << beforeKey << ".\n";
    else
        cout << "Ключ " << beforeKey << " не найден. Элемент добавлен в конец.\n";
}

void destroyStack(Stack& s) {
    s.clear();
    cout << "Стек уничтожен.\n";
}

int main() {
    Stack myStack;
    createStack(myStack);
    printStack(myStack);
    int delKey;
    cout << "\nВведите ключ для удаления: ";
    cin >> delKey;
    deleteByKey(myStack, delKey);
    printStack(myStack);
    int newKey, beforeKey;
    cout << "\nВведите новый элемент: ";
    cin >> newKey;
    cout << "Перед каким ключом вставить? ";
    cin >> beforeKey;
    addBeforeKey(myStack, newKey, beforeKey);
    printStack(myStack);
    destroyStack(myStack);
    printStack(myStack);
    return 0;
}