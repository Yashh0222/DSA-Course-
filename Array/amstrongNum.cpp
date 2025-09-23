#include<iostream>
using namespace std;
int main(){ 
    int n;
    cin>>n;

    int originalN;
    originalN = n;

    int sum = 0;
    while (n!=0)
    {
        int digit = n%10;
        sum = sum + digit*digit*digit;
        n = n/10;
    }

    if(sum == originalN){
        cout<<"its amstrong No "<<endl;
    }else{
        cout<<"Not a Amstrong Num "<<endl;
    }   

    return 0; 
}