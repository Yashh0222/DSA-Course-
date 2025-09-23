#include<iostream>
#include<string>
#include<vector>
using namespace std;

void subSets(string str, string subSet){
    if(str.size() == 0){
        cout<<subSet<<"\n";
        return ;
    }

    char ch =  str[0]; // start from 0
    //Yes choise to take char and move forward in recursion 
    subSets(str.substr(1,str.size() - 1), subSet + ch);

    // No for not selecting same char and continue the recursion
    subSets(str.substr(1, str.size()-1), subSet); 

}
int main(){ 
string str = "abc";
string subSet= "";

subSets(str, subSet);
    return 0; 
}