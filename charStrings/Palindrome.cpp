#include<iostream>
#include<string.h>
using namespace std;

bool palindrome(char word[] , int n){
    int st =0 , end = n-1;
    while (st < end)
    {
        if(word[st++] != word[end--]){
            cout<<"Not Palindrome"<<endl;
            return false;
        }
    }
    cout<<" Palindrome"<<endl;
    return true;
}
int main(){ 
    char word[30] = "nayan";

    palindrome(word, strlen(word));
    return 0; 
}