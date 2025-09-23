#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){ 

    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout<<"finding 6 -> "<<binary_search(v.begin(),v.end(),6)<<endl;
    cout<<"lower bound  -> "<<lower_bound(v.begin(),v.end(),6)-v.begin()<<endl;
    cout<<"upper bound  -> "<<upper_bound(v.begin(),v.end(),6)-v.begin()<<endl;

    int a= 3;
    int b= 4;

    cout<<"max is ->"<<max(a,b)<<endl;
    cout<<"min is ->"<<min(a,b)<<endl;

    swap(a,b);
    cout<<"a ->"<<a<<endl;

    string s = "abcd";
    reverse(s.begin(),s.end());
    cout<<s<<endl;

    rotate(v.begin(),v.begin()+1,v.end());
    cout<<"after rotation"<<endl;
    for(int i :v){
        cout<<i<<" ";
    }

    sort(v.begin(),v.end());
    cout<<"after sorting"<<endl;
    for(int i :v){
        cout<<i<<" ";
    }
    
    return 0; 
}