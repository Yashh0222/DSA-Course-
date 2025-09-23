#include<iostream>
using namespace std;

int sumofDigits(int num){
   int digsum = 0;
   
   while (num > 0)
   {
    int lastdig = num % 10;
    num /=10;
    
    digsum += lastdig;

   }
   return digsum;
}

int main(){ 
    cout<<"sum = "<<sumofDigits(2356)<<endl;

    return 0; 
}