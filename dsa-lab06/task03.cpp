/*
    Name: Muhammad Ibrahim
    CMS ID: 540051
    Section: BsCS-2k25-D
*/
#include <iostream>
#include <string>
using namespace std;

class ArrayStack {
private:
    char alphabets[20];
    int top = -1;

public:
    void Push(char alphabet);
    char Pop();
    void Peek();
    void Display();
    bool isEmpty();
    bool isFull();
    void reverseDisplay();
};

void ArrayStack::Push(char alphabet){
    if (isFull()) {
        cout << "Stack is full!" << endl;
        return;
    }

    top++;
    alphabets[top] = alphabet;
}

char ArrayStack::Pop() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return '\0';
    }

    return alphabets[top--];
}

void ArrayStack::Peek() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }

    cout << alphabets[top] << endl;
}

void ArrayStack::Display() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }

    for (int i = top; i >= 0; i--) {
        cout << alphabets[i] << " ";
    }

    cout << endl;
}

bool ArrayStack::isEmpty() {
    return top == -1;
}

bool ArrayStack::isFull() {
    return top == 19;
}


int main() {
    string word;

    cout << "Enter one word (up to 20 characters): ";
    cin >> word;

    if (word.length() > 20) {
        cout << "The word is too long." << endl;
        return 1;
    }

    ArrayStack stack;

    for (int i = 0; i < word.length(); i++) {
        stack.Push(word[i]);
    }

    cout << "Reversed word: ";

    while (!stack.isEmpty()) {
        cout << stack.Pop();
    }

    cout << endl;

    return 0;
}
