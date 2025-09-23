#include<iostream>
using namespace std;
int main(){ 
    
    int n;
    cin >> n;

    int i = 2;
   // int sum = 0;

   /* while(i<=n){
        sum = sum + i;
        i = i+2;
    }
    cout<<"the sum of even integer is "<<sum<<endl;*/

     while(i<=n){
       if(n%i == 0){
         cout<<"not a prime  for "<<i<<endl;
       }else{
         cout<<" a prime for "<<i<<endl;
    }
    i = i+1;
    }
    
    
    return 0;
}