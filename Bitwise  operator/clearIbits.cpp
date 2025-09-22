#include<iostream>
using namespace std;
void clearIbits(int num, int i){
    // To clear i Bits of num 
    int bitMask = (~0) << i;

    num = num & bitMask;// & is used to get same num back after deletion
    
    cout<<num<<endl;
}
int main(){ 
    clearIbits(15, 2);//12
    
    return 0; 
}