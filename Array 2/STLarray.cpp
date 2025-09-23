#include<iostream>
#include<array>
using namespace std;
int main(){ 
    
    array<int , 4> a = {1,2,3,4};
    int size = a.size();

    for (int i = 0; i < size; i++)
    {
       cout<<a[i]<<endl;
    }
    cout<<"element at index 2nd is "<<a.at(2)<<endl;
    cout<<"Array is empty or not "<<a.empty()<<endl;
    cout<<"first element  "<<a.front()<<endl;
    cout<<"second element  "<<a.back()<<endl;
    cout<<"size of array "<<a.size()<<endl;
    return 0; 
}