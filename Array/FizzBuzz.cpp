#include<iostream>
using namespace std;
int main(){ 
    int n;
    cin>>n;
    int fizz = 0,buzz =0;
    for (int i = 1; i <= n; i++)
    {
       fizz++;buzz++;
       if(fizz == 3 && buzz == 5){
        cout<<"fizzbuzz"<<endl;
        fizz = 0; buzz = 0;
       }else if(fizz == 3){
        cout<<"fizz"<<endl;
        fizz = 0;
       }else if(buzz == 5){
        cout<<"buzz"<<endl;
        buzz = 0;
       }else{
        cout<<i<<endl;
       }
    }
    
        
    return 0; 
}