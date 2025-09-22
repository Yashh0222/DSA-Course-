#include<iostream>
#include<string>
#include<vector>
using namespace std;

// using tabulation finding the lowest common substring 
// it means continues substring that is present in both strings eg: ab is commom in both strings 
// it return 2 which ab size 
int lcsTabulation(string str1, string str2){
    int  n = str1.size();
    int m = str2.size(); 
    int ans = 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if (str1[i-1] == str2[j-1]) // str last char = condn
            {
                dp[i][j] = dp[i-1][j-1] + 1; // this finds if strings are = 
                ans = max(ans, dp[i][j]); // if any other ans is greater this gives max in all other ans 
            }else{
                dp[i][j] = 0;
                //this sets that ans step to zero if there is no = string 
                // ans stores the final max str value which is =  
            }
            
        }
        
    }
    return ans;
}
int main(){ 
    string str1 = "abcdge";
    string str2 = "abedg";

    int  n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    
    cout<<lcsTabulation(str1, str2)<<endl;
    return 0; 
}