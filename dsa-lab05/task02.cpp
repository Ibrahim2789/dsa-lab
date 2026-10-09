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
    void InsertBefore(int position, int value);
    void DeleteNode(int value);
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

void List::InsertBefore(int position, int value){
    if (position < 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    nodeptr temp = head;
    int count = 1;

    while(temp!=nullptr && count!=position){
        temp = temp->next;
        count++;
    }

    if ( temp == nullptr ){
        cout<<"The postion could not be found!";
        return;
    }
    nodeptr n = new node(value);

    n->next = temp;
    n->prev = temp->prev;

    if (temp->prev != nullptr) {
        temp->prev->next = n;
    }
    else {
        head = n;
    }

    temp->prev = n;
}


void List::DeleteNode(int value) {
    nodeptr temp = head;

    while (temp != nullptr && temp->data != value) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "The value could not be found!" << endl;
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    else {
        head = temp->next;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    else {
        tail = temp->prev;
    }

    delete temp;
    cout << "Node deleted successfully!" << endl;
}


int main() {
    List l;

    l.AddNode(10);
    l.AddNode(20);
    l.AddNode(30);

    l.PrintForward();
    l.PrintReverse();

    l.InsertBefore(2, 15);
    l.PrintForward();
    l.PrintReverse();

    cout << "\nDelete 20:" << endl;
    l.DeleteNode(20);
    l.PrintForward();
    l.PrintReverse();

    l.InsertBefore(1, 5);
    l.PrintForward();
    l.PrintReverse();

    l.DeleteNode(5);
    l.PrintForward();
    l.PrintReverse();

    l.DeleteNode(30);
    l.PrintForward();
    l.PrintReverse();

    l.DeleteNode(100);

    l.ClearList();

    l.AddNode(50);
    l.DeleteNode(50);
    l.PrintForward();
    l.PrintReverse();

    l.DeleteNode(10);

    return 0;
}