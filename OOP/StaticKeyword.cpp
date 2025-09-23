#include<iostream>
using namespace std;

void counter(){
    static int count = 0;
    count++;
    cout<<" count :" <<count<<endl;
    }
int main(){ 
    counter();///without static funtion it count starts again from 0
    counter(); // after static keyword it becomes static and doent change 
    counter();
    return 0; 
}