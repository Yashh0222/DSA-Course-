#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){ 
    map<int, string> m;
    m[101] = "yash";
    m[102] = "sanket";
    m[103] = "yash";
    cout<<m[101]<<endl; //yash

    // count checks if map consists val or not
    cout<<m.count(101)<<endl; //1 
    cout<<m.count(104)<<endl; //0 

    // to print map values
    for(auto it : m){
        cout<<"Key = "<<it.first<<" Value = "<<it.second<<endl;
    }
    return 0; 
}