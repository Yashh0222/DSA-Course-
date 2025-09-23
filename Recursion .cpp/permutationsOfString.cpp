#include<iostream>
using namespace std;

void permutations(string str, string ans){
    int n = str.size();

    if(n == 0){
        cout<<ans<<"\n";
        return;
    }

    //to take out one element in every iteration
    for (int i = 0; i < n; i++)
    {
        char ch = str[i];
        //ex of next step str = abc to delete b so add a and c using given formula
        string nextidx = str.substr(0,i) + str.substr(i+1, n-1);
        permutations(nextidx, ans + ch);
    }
    
}
int main(){ 
    string str = "abcd";
    string ans= "";
    
    permutations(str, ans);
    return 0; 
}