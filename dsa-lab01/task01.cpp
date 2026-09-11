#include <iostream>
#include <array>
using namespace std;

int main(){
    
    int numbers[5] = {2,4,6,8,10}; 
    numbers[2] = 7; // This changes the 3rd element = 6 to 7 

    for (int i = 0; i < 5; i++ ){

        cout<< numbers[i] << " ";
        // The output would be proceed as follows:
        // for i = 0: numbers[0] which would be 2, the first element of the array
        //This goes for all the iterations of the loop
        //So, the output would be:
        //2 4 7 8 10 
    }
    return 0;
}