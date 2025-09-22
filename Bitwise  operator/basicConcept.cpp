#include<iostream>
using namespace std;
int main(){ 
    //Bitwise Operator
    cout<<(7 << 2)<<endl;
    //shifts two binary digits towrds left side(Formula = a * 2^b)Ex: a = 7,b = 2;
    cout<<(7 >> 2)<<endl;
    //shifts two binary digits towrds right side(Formula = a / 2^b) Ex: a = 7,b = 2;

    //imp -> only '0' will be added after shifting

    return 0; 
}