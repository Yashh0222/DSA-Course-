#include<iostream>
using namespace std;
int main(){ 
     
    char ch ;
    cin>>ch;
   
   if (ch >= 'a' && ch <= 'z' )
   {
    cout<<"it is lower case"<<endl;
   }else if(ch >= 'A' && ch <= 'Z' )
   {
    cout<<"it is uppper case"<<endl;
   }else {
      cout<<"it is numric case"<<endl;
   }
    
    
   
    return 0; 
}