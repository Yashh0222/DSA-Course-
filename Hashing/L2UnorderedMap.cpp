#include<iostream>
#include<unordered_map>
using namespace std;
int main(){ 
    unordered_map<string, int> m;
    
    m["india"] = 150;
    m["china"] = 150;
    m["nepal"] = 15;
    m["US"] = 10;
    m["nepal"] = 200;
    
    for(pair<string, int> country : m){
        cout<<country.first<<"->"<<country.second<<endl;
    }

    m.erase("nepal");

    if(m.count("nepal")){
        cout<<"Nepal exists"<<endl;
    }else{
        cout<<"nepal doesnt exists"<<endl;
    }
    return 0; 
}