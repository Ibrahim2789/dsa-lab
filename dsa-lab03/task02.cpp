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
    
    Student s;
    Student *p = &s;

    cout<<"Enter your full name: ";
    getline(cin, p->fullName);

    cout<<"Enter you roll number: ";
    cin>>p->rollNumber;

    cout<<"Enter your marks: ";
    cin>>p->marks;

    display(p);
    cout<<"Update your marks: ";
    cin>>p->marks;

    cout<<"Updated Student Record: "<<endl;
    display(p);
    
    return 0;
}