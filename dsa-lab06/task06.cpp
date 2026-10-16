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

    cout << "Serving customer: " << items[front] << endl;

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
    int choice;
    int value;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add customer" << endl;
        cout << "2. Serve Next" << endl;
        cout << "3. View Next" << endl;
        cout << "4. Display queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter customer token number: ";
            cin >> value;
            q.Enqueue(value);
            break;

        case 2:
            q.Dequeue();
            break;

        case 3:
            q.peekFront();
            break;

        case 4:
            q.Display();
            break;

        case 5:
            cout << "Exiting the program!" << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
        }

    } while (choice != 5);

    return 0;
}