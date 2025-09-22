#include<iostream>
#include<string>
using namespace std;
int countVowel(string str){
    int count =0;

    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] == 'a'|| str[i] == 'e'|| str[i] == 'i'|| str[i] == 'o'|| str[i] == 'u'){
            count++;
        }        
    }
    cout<<"count  is "<<count<<endl;
    return count;
}
int main(){ 
    string str = "yaaaash";

    countVowel(str);
    return 0; 
}