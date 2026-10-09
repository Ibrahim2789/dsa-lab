/*
    Name: Muhammad Ibrahim
    CMS ID: 540051
    Section: BsCS-2k25-D
*/
#include <iostream>

using namespace std;
class List{
    private:
    typedef struct node{
        int data;
        node* next;
        node* prev;

        node(int value) : data(value), next(nullptr), prev(nullptr) {}
    }* nodeptr;
    nodeptr head = nullptr;
    nodeptr tail = nullptr;

    public:
    void AddNode(int value);
    void PrintForward();
    void PrintReverse();
    void ClearList();
};

void List::AddNode(int value){

    nodeptr n = new node(value);

    if ( head == nullptr ){
        head = tail = n;
    }
    else{
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
}

void List::PrintForward(){
    if (head == nullptr) {
        cout << "The List is empty." << endl;
        return;
    }
    nodeptr curr = head;

    while(curr != nullptr){
        cout<<" "<<curr->data<<" | <==> ";
        curr = curr->next;
    }
    cout<<"nullptr"<<endl;
}

void List::PrintReverse(){
    if (tail == nullptr) {
        cout << "The List is empty." << endl;
        return;
    }
    nodeptr curr = tail;

    while(curr != nullptr){
        cout<<" "<<curr->data<<" | <==> ";
        curr = curr->prev;
    }
    cout<<"nullptr"<<endl;
}

void List::ClearList(){
    if (head == nullptr){
        cout<<"The List is already empty."<<endl;
        return;
    }

    nodeptr curr = head;
    nodeptr prev = curr;
    while(curr!=nullptr){
        prev = curr;
        curr = curr->next;
        delete prev;
    }

    head = nullptr;
    tail = nullptr;
    cout<<"The list is cleared successfully!"<<endl;
}
int main() {
    List l;
    int count, value;

    cout << "Enter the number of elements: ";
    cin >> count;

    while (count < 0) {
        cout << "Enter a non-negative count: ";
        cin >> count;
    }

    for (int i = 0; i < count; i++) {
        cout << "Enter value: ";
        cin >> value;
        l.AddNode(value);
    }

    l.PrintForward();
    l.PrintReverse();

    l.ClearList();

    return 0;
}