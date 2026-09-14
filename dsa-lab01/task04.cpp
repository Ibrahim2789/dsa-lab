#include <iostream>
#include <array>
using namespace std;

int main(){
    cout<<"Muhammad Ibrahim"<<endl;
    
    int numbers[8];

    cout<< "Enter eight numbers: ";
    for (int i = 0; i < 8 ; i++){
        cin>> numbers[i];
    }

    int maximum = numbers[0];
    int minimum = numbers[0];
    int maxIndex = 0;
    int minIndex = 0;
    for ( int i = 0 ; i < 8 ; i++){
        if (numbers[i] > maximum){
            maximum = numbers[i];
            maxIndex = i;
        }

        if ( numbers[i] < minimum ){
            minimum = numbers[i];
            minIndex = i;
        }
    }

    cout<<"Largest Value: "<<maximum<<endl;
    cout<<"Index of the Largest Value: "<<maxIndex<<endl;
    cout<<"Smallest Value: "<<minimum<<endl;
    cout<<"Index of the Smallest Value: "<<minIndex<<endl;

    return 0;
}