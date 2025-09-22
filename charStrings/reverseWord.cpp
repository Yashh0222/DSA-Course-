#include<iostream>
#include<string.h>
using namespace std;

void reverseWord(char word[] ,int n){
    int st = 0, end = n-1;
    while (st < end)
    {
        swap(word[st] , word[end]);
        st++;
        end--;
    }
    
    
}
int main(){ 
    char word[30] = "YASH";

    reverseWord(word, strlen(word));
    cout<<word<<endl;
    return 0; 
}