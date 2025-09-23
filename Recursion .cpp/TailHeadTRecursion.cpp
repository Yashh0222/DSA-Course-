#include<iostream>
using namespace std;
/*
//tail recurssion 
int print(int n){

    if(n == 0){
        return 1;
    }
    cout <<n <<endl;
    //Recursive statement 
    print(n-1);
}
    */

//head  recurssion 
int print(int n){

    if(n == 0){
        return 1;
    }
    //Recursive statement 
    print(n-1);

    cout <<n <<endl;
}
int main(){ 
    
    int n;
    cin>>n;

    print(n);

    return 0; 
}