#include<iostream>
using namespace std;
int main(){ 
    
    int row;
    cin>> row;

    int col;
    cin>> col; 

    //creating a 2D array 
    int** arr = new int*[row];
    for (int i = 0; i < row; i++)
    {
       arr[i] = new int[col]; 
    }

    //taking i/p 
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin>>arr[i][j];
        }
        
    }

        //taking o/p 
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout<<arr[i][j]<<" ";
            }cout<<endl;
            
        }

        //releaasing memory of heap 
        for (int i = 0; i < row; i++)
        { 
            delete [] arr[i];
        }
        delete [] arr ;
    
     
    return 0; 
}