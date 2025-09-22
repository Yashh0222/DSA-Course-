#include<iostream>
using namespace std;
void OddorEven(int num){
    if((num & 1) == 0){// can also written as if(!(num &1))
        cout<<"Even"<<endl;
    }else{
        cout<<"Odd"<<endl;
    }
}
int main(){ 
    OddorEven(4);
    OddorEven(3);
    
    return 0; 
}