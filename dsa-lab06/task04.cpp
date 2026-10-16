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

bool ArrayQueue::isFull(){
    return rear == 4;
}

bool ArrayQueue::isEmpty(){
    return front == -1;
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

    q.Display();

    q.Enqueue(40);
    q.Enqueue(50);
    q.Enqueue(60);

    q.Display();

    return 0;
}
