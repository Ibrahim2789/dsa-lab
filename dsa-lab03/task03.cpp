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

void display(Student *p){
    cout<<"Full Name: "<<p->fullName<<endl;
    cout<<"Roll Number: "<<p->rollNumber<<endl;
    cout<<"Marks: "<<p->marks<<endl;
}

int main() {
    
    Student *p = new Student();

    cout<<"Enter your full name: ";
    getline(cin, p->fullName);

    cout<<"Enter your roll number: ";
    cin>>p->rollNumber;

    cout<<"Enter your marks: ";
    cin>>p->marks;

    display(p);
    
    delete p;
    p = nullptr;
    return 0;
}