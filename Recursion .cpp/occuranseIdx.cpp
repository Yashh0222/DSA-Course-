#include<iostream>
#include<vector>
using namespace std;

void occuranseIdx(vector<int> arr, int i, int target){
    if(i == arr.size()){
        return ;
    }

    
        if(arr[i] == target){
           cout<<i<<" ";
        }
        return occuranseIdx(arr, i+1, target);
}
int main(){ 
    vector<int> arr = {1,2,3,5,3,2,5,2};
    
    occuranseIdx(arr, 0, 2);
    return 0; 
}