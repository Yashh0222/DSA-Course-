#include<iostream>
#include<map>
using namespace std;
int main(){ 
    
    map<int,string> m;

    m[1] = "yash";
    m[2] = "sanket";
    m[13] = "radhe";

    m.insert({5, "ayan"});
    cout<<"before erase"<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }cout<<endl;

    cout<<"finding 13 -> "<<m.count(13)<<endl;

    m.erase(13);
    cout<<"after erase"<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }cout<<endl;
    return 0; 
}