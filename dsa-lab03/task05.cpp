/*
    Name: Muhammad Ibrahim
    CMS ID: 540051
    Section: BsCS-2k25-D
*/

#include <iostream>
using namespace std;

struct Student{
    int rollNumber;
    string fullName;
    double marks;
};

void displayIfExists(const Student* s) {
    if (s != nullptr) {
        cout<<"Full Name: " << s->fullName << endl;
        cout<<"Roll Number: " << s->rollNumber << endl;
        cout<<"Marks: " << s->marks << endl;
    } 
    else {
        cout << "No record available" << endl;
    }
}

int main() {
    
    Student *p = nullptr;
    displayIfExists(p);

    p = new Student();

    cout<<"Enter your full name: ";
    getline(cin, p->fullName);

    cout<<"Enter your roll number: ";
    cin>>p->rollNumber;

    cout<<"Enter your marks: ";
    cin>>p->marks;

    displayIfExists(p);

    delete p;
    p = nullptr;
    displayIfExists(p);
    return 0;
}