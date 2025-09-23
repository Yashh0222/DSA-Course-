#include<iostream>
using namespace std;
void print(int *arr, int n){
    for (int j = 0; j < n; j++)
    {
        cout<<arr[j]<<" ";
    }
    cout<<endl;
}

void insertionSort(int *arr, int n){
    for(int i =1; i<n; i++){//For unsorted part 
       int curr = arr[i];//tempory varible
       int prev = i-1;//assignind previous to sorted part 
       while(prev >= 0 && arr[prev] > curr){//sorted part swapping 
        swap(arr[prev],arr[prev+1]);
        prev--;
       }
       arr[prev+1] = curr;//it goes beyond so 
    }
    print(arr,n);
}
int main(){ 
    int arr[] = {4,3,6,8,5};
    int n =5;

    insertionSort(arr ,5);
    return 0; 
}