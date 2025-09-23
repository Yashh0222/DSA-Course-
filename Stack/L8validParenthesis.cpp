#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool valid(string str){
    stack<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if(ch == '(' || ch == '[' || ch == '{' ){//opening of brackets and pushing to stacck for comparisons 
            s.push(ch);
        }else{ // findind clossing brackets and comparing
            if(s.empty()){
                return false;
            }

            int top = s.top();//using top element to compare next closing brackets
            if ((top == '(' && ch == ')') || (top == '{' && ch == '}') || (top == '[' && ch == ']') )
            {
                s.pop();
            }else{
                return false;
            }
            
        }
    }
    return s.empty();    
}
int main(){ 
    string str1 = "([}])";// invalid condtion 
    string str2 = "([{}])";// valid condtion 

    cout<<valid(str1)<<endl; // ans = 0
    cout<<valid(str2)<<endl; // ans = 1
    return 0; 
}