#include <iostream>
#include <array>
using namespace std;

int main(){
    cout<<"Muhammad Ibrahim"<<endl;

    int numbers[5];
    int total = 0;

    cout<< "Enter five numbers: ";
    for (int i = 0; i < 5 ; i++){
        cin>> numbers[i];
    }
    for (int i = 0 ; i < 5 ; i++){
        total += numbers[i];
    }
    cout<<"The total sum is: " << total;
    return 0;
}