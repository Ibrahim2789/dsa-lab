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
    void AddNode(int addData);
    int CountNodes();
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
int main(){

    List myList;
    int a;

    do {
        cout<< "Enter a non-negative integer (the number of nodes): ";
        cin>>a;
    } while (a < 0);

    if (a > 0) {
        cout << "Enter the values for each node: ";
        for (int i = 0; i < a; i++) {
            int value;
            cin >> value;
            myList.AddNode(value);
        }
    }

    cout << "Number of nodes: " << myList.CountNodes() << endl;
    myList.PrintList();
    myList.ClearList();
    return 0;
}