#include<iostream>
using namespace std;

int partition(int arr[], int st, int end){
    int i = st - 1;
    int pivot = arr[end];

    for(int j = st; j < end; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i] , arr[j]);
        }
    }
    i++;
    swap(arr[i] , arr[end]);

    //return pivot idx
    return i;
}

void quickSort(int arr[], int st, int end){
    //base case
    if(st >= end ){
        return ;
    }

    int pivotIdx = partition(arr, st, end);

    //recursion
    quickSort(arr, st, pivotIdx-1);//for left side of pivot

    quickSort(arr, pivotIdx+1 , end);//for right side of pivot
}

void print(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    
}
int main(){ 
    int arr[] = {6,3,5,2,7,4};
    int n = 6;
    quickSort(arr, 0, n-1);
    print(arr,n);
    return 0; 
}