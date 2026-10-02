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
    void PrintList();
    void ClearList();
    void AddNode(int addData);
    void SearchNode(int searchData);
    int CountNodes();
    void PrintSecondNode();
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
int List::CountNodes(){
    curr = head;

    int count = 0;

    while (curr!=nullptr){
        count++;
        curr = curr->next;
    }
    return count;
}

void List::SearchNode(int searchData){
    curr = head;
    int position = 1;
    while( curr!=nullptr ){

        if (curr->data == searchData) {
            cout << "Value found at position " << position << endl;
            return;
        }

        curr = curr->next;
        position++;
    }
    cout<<"Value not found!"<< endl;
}

void List::PrintSecondNode(){

    curr = head;

    if (curr == nullptr || curr->next == nullptr) {
        cout << "No second node exists!" << endl;
        return;
    }

    cout << curr->next->data << endl;
}

int main(){

    List myList;
    List oneNodeList;

    oneNodeList.AddNode(10);
    oneNodeList.PrintSecondNode();

    oneNodeList.ClearList();
    myList.PrintList();

    myList.AddNode(10);
    myList.AddNode(20);
    myList.AddNode(30);
    myList.AddNode(20);

    myList.PrintList();

    myList.SearchNode(20);
    myList.SearchNode(99);

    myList.PrintSecondNode();

    myList.ClearList();
    return 0;
}