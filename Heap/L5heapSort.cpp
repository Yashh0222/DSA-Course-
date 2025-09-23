#include<iostream>
#include<vector>
using namespace std;

void heapify(int i, vector<int> &arr, int n){
    int left = 2*i+1;
    int right = 2*i+2;
    int maxIdx = i;

    if(left < n && arr[left] > arr[maxIdx]){
        maxIdx = left;
    }

    
    if(right < n && arr[right] > arr[maxIdx]){
        maxIdx = right;
    }

    if(maxIdx != i){ // if left or right is greater 
        swap(arr[i], arr[maxIdx]);
        heapify(maxIdx, arr, n);
    }
}
void heapSort(vector<int> &arr){
    int n = arr.size();

    // converting array to proper max heap 
    for (int i = (n/2)-1; i >= 0; i--) //TC : 0(n*logn)
    {
        heapify(i,arr,n);
    }

    //sorting array by swaping top||root element to last position element
    for (int i = n-1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(0, arr, i);
    }    
    
}
int main(){ 
    vector<int> arr = {1,4,2,5,3};
    heapSort(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0; 
}