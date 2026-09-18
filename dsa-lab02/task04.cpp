#include <iostream>
using namespace std;

int main() {
    
    int students;
    cout<<"Enter the number of students: ";
    cin>>students;

    if ( students <= 0 ){
        cout<<"Error: No allocation or student input.";
        return -1;
    }
    int subjects;
    cout<<"Enter the number of subjects: ";
    cin>>subjects;

    if ( subjects <= 0 ){
        cout<<"Error: No allocation or subject input.";
        return -1;
    }

    int** marks = new int*[students];
    for (int i = 0; i < students; i++){
        marks[i] = new int[subjects];
    }

    for (int r = 0; r < students ; r++){
        cout<<"Enter the marks for each subject for the student "<<r+1<<": ";

        for (int c = 0; c < subjects; c++){

            cin>>*(*(marks+r)+c);

            if ( *(*(marks+r)+c) < 0 || *(*(marks+r)+c) > 100 ){

            cout<<"Invalid entered marks for the student.";

            for (int r = 0; r < students; r++){
                delete[] marks[r];
            }
            delete[] marks;

            return -1;
            }
        }
    }

    for (int r = 0; r < students ; r++){
        cout<<"Student "<<r+1<<": ";
        for (int c = 0; c < subjects; c++){
            cout<<*(*(marks+r)+c)<<" ";
        }
        cout<<endl;
    }

    double total = 0.0;
    int highAcheiver = 0;
    double highMarks = 0.0;

    cout<<"Totals: ";
    for (int r = 0; r < students; r++){
        total = 0.0;
        for (int c = 0; c < subjects; c++){
            total += *(*(marks+r)+c);
        }
        cout<<total<<" ";
        if(total > highMarks){
            highMarks = total;
            highAcheiver = r+1;
        }
    }

    cout<<endl;

    cout<<"Top Student: "<<highAcheiver<<endl;
    cout<<"Highest Marks: "<<highMarks;

    for (int r = 0; r < students; r++){
        delete[] marks[r];
    }
    delete[] marks;
    
    return 0;
}