#include<iostream>
using namespace std;
int main(){ 
    
    int n;
    cin>>n;

    int row =1;
    while (row<=n)
    {
        int col =1;
        while (col<=n-row+1)
        {
            cout<<col;
            col = col+1;
        }
        int star =1;
        while (star<=n-col+1)
        {
           cout<<"*";
           star = star +1;

        }
         int sstar =1;
        while (sstar<=n-col+1)
        {
           cout<<"*";
           sstar = sstar +1;

        }
        int count  = n-row+1;
        while (count)
        {
            cout<<count;
            count = count-1;
        }
        
        cout<<endl;
        row = row +1;
    }
    
    return 0; 
}