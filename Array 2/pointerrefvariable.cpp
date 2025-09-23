#include<iostream>
using namespace std;

int& func(int a){
    int num =a;
    int& ans = num;
    return ans;
}// this will give warning 

int*  fun(int n){
    int* ptr =&n ;
    return ptr;
}// this will give warning 

void update2(int& n){
    n++;
 }

void update1(int n){
   n++;
}
int main(){ 
    /*
    int i =5;
    // create refrense varible  
    int &j = i;

    cout<< i <<endl;
    i++;
    cout<< i <<endl;
    j++;
    cout<< i <<endl;
    cout<< j <<endl;
    */

    int n =5;

    cout<<"Before "<<n<<endl;
    update1(n);
    cout<<"After 1: "<<n<<endl;
    update2(n);
    cout<<"After  "<<n<<endl;

    return 0; 
}