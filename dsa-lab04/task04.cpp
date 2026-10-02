/*
    Name: Muhammad Ibrahim
    CMS ID: 540051
    Section: BsCS-2k25-D
*/

#include <iostream>

using namespace std;

class List{
    private:
    typedef struct Node{
        int data;
        Node* next;

        Node(int value, Node* nextNode = nullptr) {
            data = value;
            next = nextNode;
        }

    }* nodeptr;
    nodeptr head = nullptr;
    nodeptr curr = nullptr;

    public:
    void InsertAtBeginning(int addData);
    void PrintList();
    void ClearList();
    void AddNode(int addData);
};

void List::PrintList(){
    curr = head;

    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    while(curr!=nullptr){
        cout<<"| "<<curr->data<<" | -> ";
        curr = curr->next;
    }

    cout<<"nullptr"<<endl;
}

void List::ClearList(){
    nodeptr prev = head;

    while(head!=nullptr){
        prev = head;
        head=head->next;
        delete prev;
    }

    cout<<"List is being cleared!"<<endl;
}
void List::AddNode(int addData){
    nodeptr n = new Node(addData);

    if (head == nullptr) {
        head = n;
        return;
    }

    curr = head;

    while(curr->next!=nullptr){
        curr = curr->next;
    }

    curr->next = n;
}

void List::InsertAtBeginning(int addData){

    nodeptr n = new Node(addData);

    n->next = head;
    head = n;
}
int main(){

    List myList;

    myList.InsertAtBeginning(20);
    myList.PrintList();

    myList.InsertAtBeginning(10);
    myList.PrintList();

    myList.AddNode(30);
    myList.PrintList();

    myList.ClearList();

    return 0;
}