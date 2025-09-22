#include<iostream>
#include<string>
using namespace std;
int main(){ 
    string str = "Yash Koparkar";
    
    //Normal for loop
    //for (int i = 0; i < str.length(); i++)
    //{
    //    cout<<str[i]<<" ";
    //}
    //cout<<endl;

    //For Each loop
    for(char ch : str){
        cout<<ch<<" ";
    }
    cout<<endl;
    return 0; 
}