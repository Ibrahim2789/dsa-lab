/*
    Name: Muhammad Ibrahim
    CMS ID: 540051
    Section: BsCS-2k25-D
*/
#include <iostream>
using namespace std;

class ArrayStack {
private:
    int items[5];
    int top = -1;

public:
    void Push(int value);
    void Pop();
    void Peek();
    void Display();
    bool isEmpty();
    bool isFull();
};

void ArrayStack::Push(int value) {
    if (isFull()) {
        cout << "Stack is full!" << endl;
        return;
    }

    top++;
    items[top] = value;
}

void ArrayStack::Pop() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }

    cout << "Removed element: " << items[top] << endl;
    top--;
}
void ArrayStack::Peek() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }

    cout << "Top element: " << items[top] << endl;
}

void ArrayStack::Display() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }

    for (int i = top; i >= 0; i--) {
        cout << items[i] << " ";
    }

    cout << endl;
}

bool ArrayStack::isEmpty() {
    return top == -1;
}

bool ArrayStack::isFull() {
    return top == 4;
}

int main() {
    ArrayStack s;

    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.Display();
    s.Pop();
    s.Peek();

    s.Push(40);
    s.Push(50);
    s.Push(60);
    s.Push(70);
    s.Push(80);
    s.Push(90);

    while (!s.isEmpty()) {
        s.Pop();
    }

    s.Pop();

    return 0;
}