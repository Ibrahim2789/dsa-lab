#include <iostream>

using namespace std;

void display(const int* p, int size){
    
    int total = 0;
    for(int i = 0 ; i < size ; i++){
        cout<<"Day " << i+1 << ": " << *(p+i) <<" "<<endl;
        total += *(p+i);
    }

    cout<<endl;
    cout<<"The total number of items sold for five days: "<<total<<endl;
}
int main() {
    
    int sales[5];
    int* p = sales;

    cout<<"Enter the total number of items sold for five days: ";
    for(int i = 0 ; i < 5 ; i++){
        cin>>*(p+i);
    }
    
    cout<<"The number of items sold per day: "<<endl;
    display(p, 5);

    cout<<"Updated sales of the number of items per day: "<<endl; 
    *(p+2) += 2;
    display(p, 5);


    return 0;
}
