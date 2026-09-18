#include <iostream>
using namespace std;

int main() {
    
    int n;
    cout<<"Enter the number of students: ";
    cin>>n;

    if ( n <= 0 ){
        cout<<"Error: No allocation or mark input.";
        return -1;
    }

    int* marks= new int[n];
    cout<<"Enter the marks(0-100) for each student: ";
    for (int i = 0 ; i < n ; i++){

        cin>>*(marks+i);

        if ( *(marks+i) < 0 || *(marks+i) > 100 ){
            cout<<"Invalid entered marks for the student.";
            delete[] marks;
            marks = nullptr;
            return -1;
        }

    }

    double total = 0;
    int count = 0;
    
    for(int i = 0 ; i < n ; i++){
        cout<<"Student "<<i+1<<" marks: "<<*(marks+i)<<endl;
        total += *(marks+i);
        if( *(marks+i)>=50 ){
            count++;
        }
    }

    cout<<"Total: "<<total<<endl;
    cout<<"Average: "<<(total/n)<<endl;
    cout<<"Pass Count: "<< count;

    delete[] marks;
    marks = nullptr;

    return 0;
}
