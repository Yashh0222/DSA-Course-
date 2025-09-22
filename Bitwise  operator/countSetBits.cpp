#include<iostream>
using namespace std;
//find how many 1's are there in num(binary form)
int countSetBits(int num){
    int count = 0;

    while (num > 0)
    {
        //find last digit 
        int lastDig = num & 1;
        //add last digit to count 
        count += lastDig;

        // right shift num to get all poosile 1's and 0's
        num = num >> 1;
    }
    
    cout<<count<<endl;
    return count;
}
int main(){ 
    countSetBits(10);
    return 0; 
}