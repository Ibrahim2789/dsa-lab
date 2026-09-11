#include <iostream>
#include <algorithm>
using namespace std;

void reverseArray(int array[],int size, int n){

    if (n==size/2){
        return;
    }

    reverseArray(array,size, n+1);
    swap(array[n], array[size-1-n]);

}


int main() {
    int* numbers = new int[6];

    cout<< "Enter 6 numbers: ";
    for (int i = 0; i < 6 ; i++){
        cin>> numbers[i];
    }

    reverseArray(numbers,6,0);

    cout<<"Reversed Array: ";
    for ( int i = 0 ; i < 6 ;i++){
        cout<< numbers[i]<<" ";
    }

    return 0;
}