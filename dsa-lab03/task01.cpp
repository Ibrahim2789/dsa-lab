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

int main() {
    
    Student s;

    cout<<"Enter your full name: ";
    getline(cin, s.fullName);

    cout<<"Enter your roll number: ";
    cin>>s.rollNumber;

    cout<<"Enter your marks: ";
    cin>>s.marks;

    cout<<"Full Name: "<<s.fullName<<endl;
    cout<<"Roll Number: "<<s.rollNumber<<endl;
    cout<<"Marks: "<<s.marks<<endl;

    return 0;
}