#include<iostream>
#include<map>
using namespace std;
int main(){ 
    // Prints everthing in order based on converting string to numerical 
    map<string, int> m;
    
    m["india"] = 150;
    m["china"] = 150;
    m["us"] = 10;
    m["nepal"] = 200;
    m["uk"] = 20;
    
    for(pair<string, int> country : m){
        cout<<country.first<<"->"<<country.second<<endl;
    }

    m.erase("nepal");

    // count checks if map consists val or not
    if(m.count("nepal")){
        cout<<"Nepal exists"<<endl;
    }else{
        cout<<"nepal doesnt exists"<<endl;
    }
    return 0; 
}