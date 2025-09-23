#include<iostream>
#include<vector>
using namespace std;
int main(){ 
    
    vector<int> v;
    vector<int> a(5,1);
    cout<<"print a"<<endl;
    for(int i:a){
        cout<<i<<" ";
    }cout<<endl;


    cout<<"capacity = "<<v.capacity()<<endl;

    v.push_back(1);
    cout<<"capacity = "<<v.capacity()<<endl;

    v.push_back(2);
    cout<<"capacity = "<<v.capacity()<<endl;

    v.push_back(3);
    cout<<"capacity = "<<v.capacity()<<endl;
    cout<<"size = "<<v.size()<<endl;

    cout<<"Element at second index = "<<v.at(2)<<endl;
    cout<<"Element at first index = "<<v.front()<<endl;
    cout<<"Element at last index = "<<v.back()<<endl;

    cout<<"before pop back"<<endl;
    for(int i:v){
        cout<<i<<" ";
    }cout<<endl;

     v.pop_back();
    cout<<"after pop back"<<endl;
    for(int i:v){
        cout<<i<<" ";
    }cout<<endl;

    cout<<"before clear size = "<<v.size()<<endl;
    v.clear();
    cout<<"after clear size = "<<v.size()<<endl;
    //cout<<v.capacity()<<endl;
    return 0; 
}