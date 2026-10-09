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

        node(int value) : data(value), next(nullptr) {}
    }* nodeptr;
    nodeptr head = nullptr;
    nodeptr tail = nullptr;

    public:
    void AddNode(int value);
    void PrintList();
    void CountNodes();
    void ClearList();
};
void List::AddNode(int value){

    nodeptr n = new node(value);
    if ( head == nullptr ){
        head = n;
        tail = n;
        tail->next=head;
        return;
    }

    tail->next = n;
    tail = n;
    tail->next = head;
}

void List::PrintList(){
    if (head == nullptr){
        cout<<"The List is already empty."<<endl;
        return;
    }

    nodeptr curr = head;

    do{
        cout<<" "<<curr->data<<" | <==> ";
        curr = curr->next;
    }while(curr != head);
    cout<<"head"<<endl;
}

void List::ClearList(){
    if (head == nullptr){
        cout<<"The List is already empty."<<endl;
        return;
    }

    nodeptr curr = head;
    nodeptr prev = curr;
    do{
        prev = curr;
        curr = curr->next;
        delete prev;
    }while(curr!=head);

    head = nullptr;
    tail = nullptr;
    cout<<"The list is cleared successfully!"<<endl;
}

void List::CountNodes(){
    int count = 0;

    if (head == nullptr) {
        cout << "Number of nodes: " << count << endl;
        return;
    }

    nodeptr curr = head;
    do{
        count++;
        curr = curr->next;
    }while(curr != head);
    cout<<"Number of nodes: "<<count<<endl;
}
int main() {
    List l;

    l.PrintList();
    l.CountNodes();

    l.AddNode(10);
    l.PrintList();
    l.CountNodes();

    l.ClearList();

    l.AddNode(10);
    l.AddNode(20);
    l.AddNode(30);

    l.PrintList();
    l.CountNodes();

    l.ClearList();

    return 0;
}