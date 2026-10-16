/*
    Name: Muhammad Ibrahim
    CMS ID: 540051
    Section: BsCS-2k25-D
*/
#include <iostream>
using namespace std;

class ArrayQueue {
private:
    int items[5];
    int front = -1;
    int rear = -1;

public:
    void Enqueue(int value);
    void Dequeue();
    void peekFront();
    void Display();
    bool isEmpty();
    bool isFull();
};

void ArrayQueue::Enqueue(int value){
    if (isFull()) {
        cout << "Queue is full!" << endl;
        return;
    }

    if (isEmpty()) {
        front = 0;
    }

    rear++;
    items[rear] = value;
}

void ArrayQueue::Dequeue() {
    if (isEmpty()) {
        cout << "The queue is already empty!" << endl;
        return;
    }

    cout << "Removed: " << items[front] << endl;

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
}

bool ArrayQueue::isFull(){
    return rear == 4;
}

bool ArrayQueue::isEmpty(){
    return front == -1 || front > rear;
}

void ArrayQueue::peekFront(){
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << items[front] << endl;
}

void ArrayQueue::Display(){
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }

    for (int i = front; i <= rear; i++) {
        cout << items[i] << " ";
    }

    cout << endl;
}

int main() {
    ArrayQueue q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    q.Dequeue();
    q.peekFront();
    q.Display();

    q.Dequeue();
    q.Dequeue();
    q.Dequeue();

    q.Enqueue(40);
    q.Display();

    return 0;
}