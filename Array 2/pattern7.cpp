#include<iostream>
using namespace std;
int main(){ 
    int n;
    cin>>n;

    /*int row =1;
    while (row<=n)
    {
        int space = row-1;
        while (space)
        {
            cout<<" ";
            space = space-1;
        }
        int col =1 ;
        while (col<=n-row+1)
        {
            cout<<row;
            col = col+1;
        }
        cout<<endl;
        row = row + 1;
    }
     */

    /*int row =1;
    while (row<=n)
    {
        int space =n-row;
        while (space)
        {
            cout<<" ";
            space = space-1;
        }
        int col =1 ;
        while (col<=row)
        {
            cout<<row;
            col = col+1;
        }
        cout<<endl;
        row = row + 1;
    }*/
     
    /*int row =1;
    while (row<=n)
    {
        int space = row-1;
        while (space)
        {
            cout<<" ";
            space = space-1;
        }
        int col =1 ;
        int value = row;
        while (col<=n-row+1)
        {
            cout<<value;
            value = value+1;
            col = col+1;
        }
        cout<<endl;
        row = row + 1;
    }*/
    
    int row =1;
    int count =1;
    while (row<=n)
    {
        int space = n-row;
        while (space)
        {
            cout<<" ";
            space = space-1;
        }
        int col =1 ;
        while (col<=row)
        {
            cout<<count;
            count = count+1;
            col = col+1;
        }
        cout<<endl;
        row = row + 1;
    }
    return 0; 
}