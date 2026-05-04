#include <iostream>
using namespace std;

struct QueueNode {
    int key;
    QueueNode* next;
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}
    ~Queue() {
        while (!isEmpty()) dequeue();
    }
    void enqueue(int val) {
        QueueNode* newNode = new QueueNode{ val, nullptr };
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    int dequeue() {
        if (isEmpty()) return -1;
        int val = front->key;
        QueueNode* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
        return val;
    }
    int peek() {
        if (isEmpty()) return -1;
        return front->key;
    }
    bool isEmpty() {
        return front == nullptr;
    }
    void clear() {
        while (!isEmpty()) dequeue();
    }
};

void createQueue(Queue& q) {
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    if (n <= 0) return;
    cout << "Введите " << n << " целых чисел:\n";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        q.enqueue(val);
    }
}

void printQueue(Queue& q) {
    if (q.isEmpty()) {
        cout << "Очередь (список) пуста.\n";
        return;
    }
    Queue temp;
    cout << "Очередь (список): ";
    while (!q.isEmpty()) {
        int val = q.dequeue();
        cout << val << " ";
        temp.enqueue(val);
    }
    cout << endl;
    while (!temp.isEmpty())
        q.enqueue(temp.dequeue());
}

void deleteByKey(Queue& q, int key) {
    if (q.isEmpty()) {
        cout << "Очередь пуста, удаление невозможно.\n";
        return;
    }
    Queue aux;
    bool found = false;
    while (!q.isEmpty()) {
        int val = q.dequeue();
        if (!found && val == key) {
            found = true;
            continue;
        }
        aux.enqueue(val);
    }
    while (!aux.isEmpty())
        q.enqueue(aux.dequeue());
    if (found)
        cout << "Элемент с ключом " << key << " удалён.\n";
    else
        cout << "Элемент с ключом " << key << " не найден.\n";
}

void addBeforeKey(Queue& q, int newKey, int beforeKey) {
    if (q.isEmpty()) {
        q.enqueue(newKey);
        cout << "Очередь была пуста, элемент добавлен.\n";
        return;
    }
    Queue aux;
    bool found = false;
    while (!q.isEmpty()) {
        int val = q.dequeue();
        if (!found && val == beforeKey) {
            aux.enqueue(newKey);
            found = true;
        }
        aux.enqueue(val);
    }
    while (!aux.isEmpty())
        q.enqueue(aux.dequeue());
    if (found)
        cout << "Элемент " << newKey << " добавлен перед " << beforeKey << ".\n";
    else
        cout << "Ключ " << beforeKey << " не найден. Элемент добавлен в конец.\n";
}

void destroyQueue(Queue& q) {
    q.clear();
    cout << "Очередь уничтожена.\n";
}

int main() {
    Queue myQueue;
    createQueue(myQueue);
    printQueue(myQueue);
    int delKey;
    cout << "\nВведите ключ для удаления: ";
    cin >> delKey;
    deleteByKey(myQueue, delKey);
    printQueue(myQueue);
    int newKey, beforeKey;
    cout << "\nВведите новый элемент: ";
    cin >> newKey;
    cout << "Перед каким ключом вставить? ";
    cin >> beforeKey;
    addBeforeKey(myQueue, newKey, beforeKey);
    printQueue(myQueue);
    destroyQueue(myQueue);
    printQueue(myQueue);
    return 0;
}