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
    int choice, value;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value: ";
            cin >> value;
            s.Push(value);
            break;

        case 2:
            s.Pop();
            break;

        case 3:
            s.Peek();
            break;

        case 4:
            s.Display();
            break;

        case 5:
            cout << "Exiting the program!" << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
        }

    } while (choice != 5);

    if (!s.IsEmpty()) {
       cout << "Clearing remaining nodes before exit..." << endl;
       s.ClearStack();
    }
    return 0;
}

// LIFO (Last In, First Out) means the last element pushed onto the stack is the first one popped.

// Task 5 uses an array with a fixed capacity, so it cannot store more elements than its defined size.

// Task 6 uses dynamic memory allocation to create new nodes when pushing elements,
// allowing the stack to grow as needed depending on available memory.