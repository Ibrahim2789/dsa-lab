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
    void DeleteNode(int delData);
    void SearchNode(int searchData);
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

void List::DeleteNode(int delData){

    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    if (head->data == delData) {
        curr = head;
        head = head->next;
        delete curr;
        return;
    }

    nodeptr prev = head;
    curr = head->next;

    while(curr!=nullptr && curr->data != delData){
        prev = curr;
        curr = curr->next;
    }

    if ( curr == nullptr ){
        cout<<"The value does not exist!"<<endl;
        return;
    }

    prev->next = curr->next;
    delete curr;
}
int main() {

    List myList;

    myList.AddNode(10);
    myList.AddNode(20);
    myList.AddNode(20);
    myList.AddNode(30);

    myList.PrintList();

    myList.DeleteNode(20);
    myList.PrintList();

    myList.DeleteNode(10);
    myList.PrintList();

    myList.DeleteNode(30);
    myList.PrintList();

    myList.DeleteNode(99);
    myList.PrintList();

    myList.DeleteNode(20);
    myList.PrintList();

    myList.DeleteNode(20);
    myList.PrintList();

    myList.ClearList();
    return 0;
}