#include<iostream>
using namespace std;
int main(){ 
    int arr[3][3] = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9}};

     // in 2D matrix pointer works for whole row
     cout<<arr<<"="<<&arr[0][0]<<endl; // both gives same        
     cout<<arr + 1<<"1="<<&arr[0][1]<<endl; // so here this != beause pointer in 2D points to row and this points to next row              
     cout<<arr+1<<"="<<&arr[1][0]<<endl;// here row is chanded so it got equal            
    return 0; 
}