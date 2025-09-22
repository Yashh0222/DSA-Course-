#include<iostream>
using namespace std;
int getIthBit(int num,int i){
    int bitMask = 1 << i;

    if((num * bitMask) == 0){
        return 0;
    }else{
        return 1;
    }
}

//setting ith bit
int setIthBit(int num ,int i){
    int bitMask = 1 << i;
    return (num | bitMask); 
}

//clearing ith bit
int clearIthBit(int num ,int i){
    int bitMask = ~(1 << i);
    return (num & bitMask); 
}

//Check num is power of two 
bool isPowerOf2(int num){
    if(!(num &  (num -1))){
        return true;
    }else{
        return false;
    }
}
int main(){ 
    cout<<getIthBit(6 , 2)<<endl;
    cout<<setIthBit(6 , 3)<<endl;
    cout<<clearIthBit(6 , 1)<<endl;
    cout<<isPowerOf2(8)<<endl;
    cout<<isPowerOf2(3)<<endl;
    return 0; 
}