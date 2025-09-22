#include<iostream>
#include<string.h>
using namespace std;
int main(){ 
    /*
    char word[30];
    cin>>word;// after whitespace it doent print anything 

    cout<<"The word is "<<word<<endl;
    cout<<"the length of word is "<<strlen(word)<<endl;*/

    char sentence[30];
    cin.ignore();
    cin.getline(sentence,30,'*');// so we use getline keyword to print sentense 
    //if we have to terminte the sentense just the * as argument  

    cout<<"The word is "<<sentence<<endl;
    cout<<"the length of word is "<<strlen(sentence)<<endl;
    return 0; 
}