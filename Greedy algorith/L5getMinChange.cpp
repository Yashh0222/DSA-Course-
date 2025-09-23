#include<iostream>  
#include<vector>
using namespace std;

int getMinChange(vector<int> coins, int v){
    int ans = 0;

    int n = coins.size();    
    // backward for loop to get get minimum no of coins 
    for (int i = n - 1; i >= 0 && v > 0; i--) // v > 0 is bcz coins for value is done loop closing
    {
        if (v >= coins[i]) // ex : 590 > 2000 is false so this chosse 500 after condn becomes true  
        {
            int coinCount = v/coins[i];
            ans += v/coins[i]; // ex: 590/500 = 1 adding 1 coin to our ans 
            cout<<"val of coin is "<<coins[i]<<" no of coins is "<<coinCount<<endl;
            v = v % coins[i]; // to get left val do % ex : 590 % 500 = 90
            
            // this process repets until v is 0 (condn : v > 0)
        }
       
    }
    cout<<"Min no of coins for "<<v<<" is = "<<ans<<endl;
    return ans;
}
int main(){ 
    vector<int> coins = {1,2,5,10,20,50,100,500,2000};
    int v = 590;

    getMinChange(coins, v);  
    return 0; 
}
