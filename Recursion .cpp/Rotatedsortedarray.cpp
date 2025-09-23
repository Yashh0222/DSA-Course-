#include<iostream>
using namespace std;
// Using recursion searching with TC(0(logn)) 
int search(int arr[], int st, int end, int target){
    //base case
    if(st > end){
        return -1;
    }

    int mid = st + (end - st)/2;
    if(arr[mid] == target){
        return mid;
    }

    //To check in which line 
    if(arr[st] <= arr[mid]){//Line 1
        if(arr[st] <= target && target <= arr[mid]){
            //seearch in left part
            return search(arr, st, mid - 1, target);
        }else{
            //search in right part
            return search(arr, mid + 1, end, target);
        }
    }else{
        if(arr[mid] <= target && target <= arr[end]){
            //seaarch in right part
            return search(arr, mid + 1, end, target);
        }else{
            // search in left part
            return search(arr, st, mid -1, target);
        }
    }
}
int main(){ 
    int arr[] = {4,5,6,7,0,1,2};

    int n = 7;
    cout<<"Target is at index "<<search(arr, 0, n - 1, 2);
    
    return 0; 
}