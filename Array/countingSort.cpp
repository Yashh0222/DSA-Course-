#include<iostream>
#include<limits.h>
using namespace std;

void print(int *arr, int n){
    for (int j = 0; j < n; j++)
    {
        cout<<arr[j]<<" ";
    }
    cout<<endl;
}

void countingSort(int *arr, int n){
    int freq[100000] = {0};
    int minVal = INT_MAX,maxVal = INT_MIN;
    for(int i=0; i<n; i++){
        minVal = min(minVal , arr[i]);
        maxVal = max(maxVal , arr[i]);
    }
    
    //counting frequency oof elements
    for(int i = 0; i<n ;i++){
        freq[arr[i]]++;
    }

    //printing elements according to seriel using freq
    for(int i=minVal, j=0 ; i<=maxVal; i++){
        while(freq[i] > 0){
            arr[j++] = i;
            freq[i]--;
        }
    }
    print(arr,n);
}
int main(){ 
    int arr[] = {1,4,5,1,2,2,3,1,4};
    int n =9;

    countingSort(arr ,9);
    return 0; 
}