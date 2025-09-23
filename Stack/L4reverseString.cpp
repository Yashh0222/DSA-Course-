#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Reverse a string using stack
string reverseString(string str)
{

    string ans;
    stack<int> s;

    for (int i = 0; i < str.size(); i++)
    {
        s.push(str[i]);
    }

    while (!s.empty())
    {
        char top = s.top();
        ans += top;
        s.pop();
    }
    return ans;
}

int main()
{
    string str = "Yash";
    cout << reverseString(str) << endl;
    return 0;
}