#include<iostream>
#include<string>
#include<stack>
using namespace std;

// checking if it has double parenthesis ((a + b)) bind this a+b and we get duplicate parenthesis
// ((a+b)+c) if we dont get return false

bool isDuplicate(string str){
    stack<char> s;

    for(int i=0; i<str.size(); i++){
        char ch = str[i];
        if(ch != ')'){ // pushing all elements till we find and closing bracket
            s.push(ch);
        }else{// finding opening bracket and pushing stack elements
            if(s.top() == '('){
                return true; // we found directly at top return duplicate parenthesis
            }

            // else pop elements till we find the duplicate parenthesis
            while(s.top() != '('){
                s.pop();
            }
            // finally when we find it pop the openeing bracket too
            s.pop();
        }
        
    }
    //finally retrurn false no duplicate parenthexsis
    return false;
}
int main(){ 
    string str1 = "((a + b))"; // True
    string str2 = "((a + b)+(c + d))"; // False

    cout<<isDuplicate(str1)<<endl; //1
    cout<<isDuplicate(str2)<<endl; //0
    
    return 0; 
}