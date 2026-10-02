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
    void CreateThreeNodes();
    void PrintList();
    void ClearList();
};

void List::CreateThreeNodes(){
    int a, b, c;
    cout<<"Enter the first integer: ";
    cin>>a;
    cout<<"Enter the second integer: ";
    cin>>b;
    cout<<"Enter the third integer: ";
    cin>>c;

    nodeptr n1 = new Node(a);
    nodeptr n2 = new Node(b);
    nodeptr n3 = new Node(c);

    head = n1;
    n1->next = n2;
    n2->next = n3;
}

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

    cout<<"List is being cleared"<<endl;
}

int main() {

    List myList;

    myList.PrintList();

    myList.CreateThreeNodes();

    myList.PrintList();

    myList.ClearList();

    myList.PrintList();

    return 0;
}