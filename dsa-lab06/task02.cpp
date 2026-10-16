/*
    Name: Muhammad Ibrahim
    CMS ID: 540051
    Section: BsCS-2k25-D
*/
#include <iostream>
using namespace std;

class LinkedStack {
private:
    typedef struct node {
        int data;
        node* next;

        node(int value) : data(value), next(nullptr) {}
    } *nodeptr;

    nodeptr top = nullptr;

public:
    void Push(int value);
    void Pop();
    void Peek();
    void Display();
    bool IsEmpty();
    void ClearStack();
};

void LinkedStack::Push(int value) {
    nodeptr n = new node(value);
    n->next = top;
    top = n;

    cout<<"The element "<<value<<" is pushed into the stack."<<endl;
}

void LinkedStack::Pop() {
    if (IsEmpty()) {
        cout << "The Stack is empty!" << endl;
        return;
    }

    nodeptr temp = top;
    top = top->next;

    cout << "Popped element: " << temp->data << endl;
    delete temp;
}

void LinkedStack::Peek() {
    if (IsEmpty()) {
        cout << "The Stack is empty!" << endl;
        return;
    }

    cout << "Top element: " << top->data << endl;
}

void LinkedStack::Display() {
    if (IsEmpty()) {
        cout << "The Stack is empty!" << endl;
        return;
    }

    nodeptr temp = top;

    cout << "Stack elements: ";

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

bool LinkedStack::IsEmpty() {
    return top == nullptr;
}

void LinkedStack::ClearStack() {
    if (IsEmpty()) {
        cout << "The Stack is already empty!" << endl;
        return;
    }
    nodeptr temp;

    while (top != nullptr) {
        temp = top;
        top = top->next;
        delete temp;
    }

    cout<< "The Stack is cleared successfully!" << endl;
}



int main() {
    LinkedStack s;

    s.Push(5);
    s.Push(15);
    s.Push(25);

    s.Display();

    s.Pop();
    s.Peek();

    s.Pop();
    s.Pop();
    s.Pop();

    s.ClearStack();

    return 0;
}
