#include <iostream>

using namespace std;

int main() {
    
    int sales[2][3];
    int (*rowptr)[3] = sales;

    
    for (int r = 0; r < 2 ; r++)
    {
        cout<<"Enter the three days for the branch "<<r+1<<": ";
        for (int c = 0; c < 3; c++)
        {
            cin>>*(*(rowptr+r)+c);
        }
        
    }
    
    double total = 0.0;
    double salesPerDay = 0.0;

    for (int r = 0; r < 2 ; r++){
        cout<<"Branch "<<r+1<<" | ";
        for (int c = 0; c < 3; c++){
            cout<<*(*(rowptr+r)+c)<<" ";
        }
        cout<<"|"<<endl;
    }

    cout<<"Branch totals: ";
    for (int r = 0; r < 2; r++)
    {
        total = 0.0;
        for (int c = 0; c < 3; c++){
            total += *(*(rowptr+r)+c);
        }
        cout<<total<<" ";
    }

    cout<<endl;
    cout<<"Days total: ";

    for (int c = 0; c < 3; c++)
    {
        salesPerDay = 0.0;
        for (int r = 0; r < 2; r++)
        {
            salesPerDay += *(*(rowptr+r)+c);
        }
        cout<<salesPerDay<<" ";
    }
    
    return 0;
}
