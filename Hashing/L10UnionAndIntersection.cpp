#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

// to print intersection of both arrays 
void PrintIntersection(vector<int> arr1, vector<int> arr2){
    unordered_set<int> s;

    //copy arr1 to set
    for(int el : arr1){
        s.insert(el);
    }

    for(int el : arr2){
        if(s.find(el) != s.end()){ // conditon if we found arr2 val in set 
            cout<<el<<" ";
            s.erase(el); // if we find same eleement in set then remove it if same element ocuurs again it will print again so remove it 
        }
    }
    cout<<endl;
}
//to print Unionn of arr
void PrintUnion(vector<int> arr1, vector<int> arr2){
    unordered_set<int> s;

    //copy arr1 to set
    for(int el : arr1){
        s.insert(el);
    }

    // copy arr2 to set
    for(int el : arr2){
        s.insert(el);
    }

    
    for(int el : s){
        cout<<el<<" ";
    }
    cout<<endl;
}
int main(){ 
    vector<int> arr1 = {7,3,9};
    vector<int> arr2= {6,3,9,2,9,4};

    cout<<"Union = ";
    PrintUnion(arr1, arr2);

    cout<<"Interserction = ";
    PrintIntersection(arr1, arr2);
    return 0; 
}