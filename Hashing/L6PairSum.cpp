#include<iostream>
#include<unordered_map>
using namespace std;
int main(){ 
    int arr[7] = {1,2,7,11,15,5,9};
    int n = 7;
    int target = 9;


    unordered_map<int, int> m; // key = arr[i], val = idx

    for(int i=0; i<n; i++){
        int comp = target - arr[i];// we need comp for to complete our target 
        if(m.count(comp)){ //checks if required comp is present in map or not (EG:whwn we gwt 7 from arr this checks map to find 2 to complete 9 comp at idx 7 is 9-7=2 and will be in map )
            cout<<"ans is :" <<m[comp]<<","<<i<<endl;
            cout<<"ans is :" <<comp<<","<<arr[i]<<endl;
            break;            
        }
        m[arr[i]] = i;
    }
    return 0; 
}