#include<iostream>
#include<vector>
using namespace std;
//Based on divide & conquer(TC is 0(nlogn) & SP is 0(n) due vector use)

int merge(int arr[],int st, int mid, int end){
    vector<int> temp;
    int i = st;
    int j = mid+1;
    int invCount = 0;

    //if left arr[i] < arr[j] then this will copy arr[i] to temp arr
    while(i <= mid && j <= end){
        if(arr[i] < arr[j]){
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);  
            //this is used bcz after divide arry get sorted and we can use it compare
            invCount += (mid - i + 1);//this formula compare other counts directly if it get one of comparison
        }
    }

    //if after comparisions any elements left in left then copy it to temp arr
    while(i <= mid){
        temp.push_back(arr[i++]);
    }

    //same for right arr 
    while(j <= end){
        temp.push_back(arr[j++]);
    }

    // now copy temp arr to main arr using for loop
    for (int idx = st, x = 0; idx <= end; idx++)
    {
       arr[idx] = temp[x++];
    }

    return invCount;
}

int mergeSort(int arr[], int st, int end){
    //base case
    if(st >= end){
      return 0;
    }
    //(Divide)
    int mid = st  + (end - st)/2;

    //to divide left part again & againn
    int leftinverCount =  mergeSort(arr, st, mid);

    //to divide right part again & againn
    int rightinverCount = mergeSort(arr, mid + 1, end);

    //To add the sorted array (conquer)
    int invCount = merge(arr, st, mid, end);

    return leftinverCount + rightinverCount + invCount; 
    
    }


void print(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    
}
int main(){ 
    
    int arr[] = {6,3,5,2,7};
    int n = 5;
    cout<<"Inversion count "<< mergeSort(arr, 0, n-1)<<endl;
    print(arr,n);
    return 0; 
}