#include<iostream>
using namespace std;
int main(){ 
    int arr[3][3] = {{1,2,3},
                     {4,5,6},
                      {7,8,9}};
    int n =3;

    //To rotate array 90 degrees
    // first transpose the matrix without extra spase
    //j= i+1 is used to ignore reversing again
    for(int i=0; i<n; i++){
        for (int j = i+1; j < n; j++)
        {
           swap(arr[i][j],arr[j][i]);
        }
        
    }

    //reverse the rows 
    for(int i=0; i<n; i++){
        int left = 0,right= n-1;
        while (left <= right)
        {
           swap(arr[i][left], arr[i][right]);
           left++;
           right--;
        }
        
    }

    // print the rotated array
    for(int i=0; i<n; i++){
        for (int j = 0; j < n; j++)
        {
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0; 
}