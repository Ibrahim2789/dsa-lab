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
    void InsertAtBeginning(int addData);
    void AddNode(int addData);
    void DeleteNode(int delData);
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

void List::InsertAtBeginning(int addData){

    nodeptr n = new Node(addData);

    n->next = head;
    head = n;
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

void List::PrintSecondNode(){

    curr = head;

    if (curr == nullptr || curr->next == nullptr) {
        cout << "No second node exists!" << endl;
        return;
    }

    cout << curr->next->data << endl;
}

int main() {

    List list;

    while (true) {

        int choice, value;

        cout<< "\n===== LINKED LIST MENU =====" << endl;
        cout<< "1. Insert at Beginning" << endl;
        cout<< "2. Insert at End" << endl;
        cout<< "3. Search by Value" << endl;
        cout<< "4. Delete by Value" << endl;
        cout<< "5. Display All Nodes" << endl;
        cout<< "6. Count Nodes" << endl;
        cout<< "7. Display Second Node" << endl;
        cout<< "8. Exit" << endl;

        cout<< "Enter your choice: ";
        cin>>choice;

        switch (choice) {

            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.InsertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.AddNode(value);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                list.SearchNode(value);
                break;

            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                list.DeleteNode(value);
                break;

            case 5:
                list.PrintList();
                break;

            case 6:
                cout << "Number of nodes: "
                     << list.CountNodes() << endl;
                break;

            case 7:
                list.PrintSecondNode();
                break;

            case 8:
                list.ClearList();
                cout << "Program exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}

// Accessing a general position requires traversal because a linked list
// does not support direct indexing like an array. We must start from the
// head and follow the next pointers until we reach the required position.

// Searching by value can take O(n) time because the value may be in the
// last node or may not exist at all. In the worst case, we must check
// every node in the list.