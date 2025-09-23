#include<iostream>
#include<vector>
using namespace std;

int firstOcca(vector<int> arr, int i, int target){

    if(i == arr.size()){
        return -1;
    }

    if(arr[i] == target){
        return i;
    }

    return firstOcca(arr , i+1 , target);
  
}

int lastOcca(vector<int> arr ,int i, int target){
    if(i == arr.size()){
        return -1;
    }

    int idxFound = lastOcca(arr,i+1 ,target);

    if(idxFound == -1 & arr[i] == target){
        return i;
    }
    return idxFound;
}
int main(){ 
    vector<int> arr = {1,2,3,3,3,4,5};
    cout<<firstOcca(arr ,0 , 3)<<endl;
    cout<<lastOcca(arr ,0 , 3);
    return 0; 
}