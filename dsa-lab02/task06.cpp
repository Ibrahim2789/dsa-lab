#include <iostream>
using namespace std;

int main() {

    int n = 3;

    int* values = new int[n];

    cout<<"Enter three integers: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    cout << "The three integers are: ";

    for (int i = 0; i < n; i++) {
        cout << values[i] << " ";
    }
    cout << endl;

    delete[] values;
    values = nullptr;

    return 0;
}
