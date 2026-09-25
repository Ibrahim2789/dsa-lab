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

Student* createRecord(){
    Student* s = new Student();
    cout<<"Enter your full name: ";
    cin.ignore();
    getline(cin, s->fullName);

    cout<<"Enter your roll number: ";
    cin>>s->rollNumber;

    cout<<"Enter your marks: ";
    cin>>s->marks;
    return s;
}

void displayIfExists(const Student* s) {
    if (s != nullptr) {
        cout<<"Full Name: " << s->fullName << endl;
        cout<<"Roll Number: " << s->rollNumber << endl;
        cout<<"Marks: " << s->marks << endl;
    } 
    else {
        cout<<"No record available" << endl;
    }
}

void updateMarks(Student* s){
    if (s != nullptr) {
        cout<<"Enter the new marks: ";
        cin>>s->marks;
    } else {
        cout<<"No record available. Cannot update marks."<<endl;
    }   
}

void deleteRecord(Student* &s){
    if (s != nullptr) {
        delete s;
        s = nullptr;
        cout<<"Student record deleted successfully."<<endl;
    } else {
        cout<<"No record available. Cannot delete."<<endl;
    }
}

int main() {

    Student* p = nullptr;

    while(true){
        
        cout<<"\n============Menu===========\n";
        cout<<"1: Create a record"<<endl;
        cout<<"2: Display the record"<<endl;
        cout<<"3: Update the Marks"<<endl;
        cout<<"4: Delete the Record"<<endl;
        cout<<"5: Exit the program"<<endl;

        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;

        if (choice == 1){
            if (p != nullptr) {
                cout<<"A record already exists. Please delete it before creating a new one."<<endl;
            } else {
                p = createRecord();
            }
        }
        else if(choice == 2){
            displayIfExists(p);
        }
        else if( choice == 3){
            updateMarks(p);
        }
        else if( choice == 4){
            deleteRecord(p);
        }
        else if(choice == 5){
            cout<<"The program is exited successfully."<<endl;
            break;
        }
        else{
            cout<<"Invalid choice. Please try again."<<endl;
        }
    }

    if (p != nullptr) {
        delete p;
        p = nullptr;
    }
    return 0;
}