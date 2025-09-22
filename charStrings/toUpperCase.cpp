#include<iostream>
#include<string.h>
using namespace std;
// making char upper case
/*void toUpper(char word[], int n){
    for (int i = 0; i < n; i++)
    {
        char ch = word[i];
        if(ch>= 'A' && ch<='Z'){
            continue;
        }else{
            word[i] = ch -'a' + 'A';// ch -'a' gets position of ch and + 'A' prints it in upper case
        }
    }
    
}
*/
void toLower(char word[], int n){
    for (int i = 0; i < n; i++)
    {
        char ch = word[i];
        if(ch>= 'a' && ch<='z'){
            continue;
        }else{
            word[i] = ch -'A' + 'a';
        }
    }
    
}
int main(){ 
    char word[30] = "YASH";
    
    //toUpper(word,strlen(word));
    toLower(word,strlen(word));

    cout<<word<<endl;
    return 0; 
}