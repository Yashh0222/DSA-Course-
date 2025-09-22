#include<iostream>
using namespace std;
int diagonalSum(int arr[][3],int n){
    int sum = 0;
   //this has time complexity of 0(N^2) 
   // for(int i=0; i<n; i++){///row
   //     for(int j=0; j<n; j++){//col
   //         if(i == j){
   //             sum += arr[i][j];//sum of primary diagonal
   //         }else if(j == n-i-1){
   //             sum += arr[i][j];//sum of secondary diagonal
   //         }
   //     }
   // }
   // cout<<"sum is "<<sum<<endl;
   // return sum;

   //Same with the TC of 0(N)
   for (int i = 0; i < n; i++)
   {
    sum += arr[i][i];
    if(i != n-i-1){
        sum += arr[i][n-i-1];
    }
   }
   
}
int main(){ 
    int arr[3][3] = {{1, 2, 3}, 
                      {4, 5, 6}, 
                       {7, 8, 9}};

    diagonalSum(arr,3);
    return 0; 
}