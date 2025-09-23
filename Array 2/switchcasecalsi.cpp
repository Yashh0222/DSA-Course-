#include<iostream>
using namespace std;
int main(){ 
    
    /*int a,b;

    cout<<"Enter value of a"<<endl;
    cin>>a;
    cout<<"Enter value of b"<<endl;
    cin>>b;

    char op;
    cout<<"Enter the opertion u want to perform"<<endl;
    cin>>op;

    switch( op ){

        case '+':cout<<(a+b)<<endl;
                 break;
        case '-':cout<<(a-b)<<endl;
                 break; 
        case '*':cout<<(a*b)<<endl;
                 break;   
        case '/':cout<<(a/b)<<endl;
                 break;   
        case '%':cout<<(a%b)<<endl;
                 break;    
        default : cout<<"Enter valid operation"<<endl;      
    }*/

    int amount;
    cout<<"Enter amount  to be seperate"<<endl;
    cin>>amount;
    
    int note =0;
    int op;
    cout<<"Enter the note which is to be checked"<<endl;
    cin>>op;
    
    switch( op ){

        case 100 : note = amount/100;
                   amount = amount - (100*note);
                   cout<<"The 100 notes in "<<note<<endl;
                   break;
        case 50 :  amount = amount - (50*note);
                   note = amount/50;
                   cout<<"The 50 notes in "<<note<<endl;
                   break;       
        case 20 :  note = amount/20;
                   amount = amount - (20*note);
                   cout<<"The 20 notes in "<<note<<endl;
                   break;
        case 10 :  note = amount/10;
                   amount = amount - (10*note);
                   cout<<"The 10 notes in "<<note<<endl;
                   break;
        default :  cout<<"Entered note is not present  "<<endl;
                   break;

    }
    return 0; 
}