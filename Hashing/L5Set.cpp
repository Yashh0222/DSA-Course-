#include<iostream>
#include<map>
#include<unordered_set>
#include<set>
using namespace std;
int main(){
    //this prints values in order 
    // In set when we add val it stored and if we add same value it will not be added again
    set<int> s;
    
    s.insert(1);
    s.insert(3);
    s.insert(5);
    s.insert(2);
    //s.insert(1);
    //s.insert(1);
    //s.insert(1); this 1 only onse

    cout<<"size is : "<<s.size()<<endl;

    s.erase(3);
    if(s.find(3) != s.end()){
        cout<<"3 Exists"<<endl;
    }else{                
        cout<<"3 dosent Exists"<<endl;
    }

    for(auto el : s){
        cout<<el<<" ";
    }
    cout<<endl;
    return 0; 
}