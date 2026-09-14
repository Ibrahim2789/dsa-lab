#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cout<<"Muhammad Ibrahim"<<endl;

    int* numbers = new int[10];

    cout<< "Enter 10 numbers: ";
    for (int i = 0; i < 10 ; i++){
        cin>> numbers[i];
    }

    int k = 0;
    for ( int i = 0 ; i < 10 ; i++ ){
        int count=0;
        for ( int j = 0 ; j < i ; j++ ){
            if ( numbers[i] == numbers[j] ){
                count++;
            }
        }
        
        if (count==0){
            swap(numbers[i], numbers[k]);
            k++;
        }
    }

    for (int i = 0 ; i < k ; i++ ){
        cout<<numbers[i]<<" ";
    }

    cout<<endl;
    cout <<"Unique numbers are : "<< k;

    delete[] numbers;
    numbers=nullptr;
    return 0;
}