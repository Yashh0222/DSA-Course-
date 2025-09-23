#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

//To print distint elements count we use set which store val only onse 
int CountDistinct(vector<int> arr){
    unordered_set<int> s;
    
    for (int i = 0; i < arr.size(); i++)
    {
        s.insert(arr[i]);
    }

    for(int el : s){
        cout<<el<<" ";
    }
    cout<<endl;
    return s.size();
    
} 
int main(){ 
    vector<int> arr = {4,3,2,5,6,7,3,4,2,1};

    cout<<"Count = "<<CountDistinct(arr)<<endl;
    return 0; 
}