#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//using stack for value comaprisons 
// creating vec ans for storing the ans 
//if there no greater value retrn -1
//using backward for loop for comparisons

void nextGreater(vector<int> arr, vector<int>& ans){
    stack<int> s;
    int idx = arr.size()-1;
    ans[idx] = -1;
    s.push(arr[idx]);

    for( idx = idx-1;idx >= 0; idx--){ // to travewse the arr
        int curr = arr[idx];
        while (!s.empty() && curr >= s.top() )//using while loop for comparisions
        {
            s.pop();
        }

        if(s.empty()){
            ans[idx] = -1;
        }else{
            ans[idx] = s.top();
        }
        
        s.push(curr);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){ 
    vector<int> arr = {6,8,0,1,3};
    vector<int> ans = {0,0,0,0,0};

    nextGreater(arr, ans);
    return 0; 
}