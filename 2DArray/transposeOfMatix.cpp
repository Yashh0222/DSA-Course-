#include<iostream>
using namespace std;

void matrix(int arr[2][3],int n, int m){
    int row=n,col=m;

    int transpose[m][n] = {{0}};

    for (int i = 0; i < row; i++)
    {
        for(int j=0; j<col; j++){
            transpose[j][i] = arr[i][j];
        }
    }

    //print transpose
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
}
int main(){ 
    int arr[2][3] = {{4,7,8},
                     {8,8,7}};

    matrix(arr, 2, 3);
    return 0; 
}