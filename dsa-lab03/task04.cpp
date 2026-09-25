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
    float marks;
};

void displayStudent(const Student *s){
    cout<<"Full Name: "<<s->fullName<<endl;
    cout<<"Roll Number: "<<s->rollNumber<<endl;
    cout<<"Marks: "<<s->marks<<endl;
}

void updateMarks(Student* s, float newMarks){
    s->marks = newMarks;
}

int main() {
    
    Student *p = new Student();

    cout<<"Enter your full name: ";
    getline(cin, p->fullName);

    cout<<"Enter your roll number: ";
    cin>>p->rollNumber;

    cout<<"Enter your marks: ";
    cin>>p->marks;

    displayStudent(p);

    float newMarks;
    cout<<"Update your marks: ";
    cin>>newMarks;

    updateMarks(p, newMarks);
    cout<<"Updated Student Record: "<<endl;
    displayStudent(p);

    delete p;
    p = nullptr;
    return 0;
}