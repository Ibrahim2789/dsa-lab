#include <iostream>
using namespace std;

int main() {

    int n;
    cout<<"Enter the number of subjects(1-10): ";
    cin>>n;

    if ( n <= 0 || n > 10 ){
        cout<<"Error: No allocation or student input.";
        return -1;
    }

    int* marks = new int[n];

    cout<<"Enter the marks for each subject: ";
    for (int i = 0; i < n; i++)
    {
        cin>>*(marks+i);
    }
    
    int* extendedMarks = new int[n+1]{0};
    for (int i = 0; i < n; i++){
        *(extendedMarks+i) = *(marks+i);
    }

    cout<<"Enter another subject's marks: ";
    cin>>*(extendedMarks+n);

    delete[] marks;
    marks = extendedMarks;
    extendedMarks= nullptr;

    for (int i = 0; i < n+1; i++){
        cout<<*(marks+i)<<" ";
    }
    
    delete[] marks;
    marks = nullptr;

    return 0;
}