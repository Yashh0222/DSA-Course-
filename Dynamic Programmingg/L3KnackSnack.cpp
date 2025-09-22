#include<iostream>
#include<vector>
using namespace std;

int knackSnackRec(vector<int> val, vector<int> wt, int W, int n){
    // base casse
    if (n == 0 || W == 0)
    {
        return 0;
    }

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(itemWt <= W){
        // include-> if we want to include that item in sack 
        int ans1 = knackSnackRec(val, wt, W-itemWt, n-1) +  itemVal;

        //exclude-> if we dont want to add means we get two choiss
        int ans2 = knackSnackRec(val, wt , W, n-1);

        return max(ans1, ans2); // recursion returns the max val to include the item in sack or not  
    }else{
        //this works when itemWt >= W 
        return knackSnackRec(val, wt , W, n-1);
    }
    

}
int main(){ 
    
    vector<int> val = {15,14,10,45,30}; 
    vector<int> wt = {2,5,1,3,4};
    int W = 7; // weight of sack(bori)
    int n = 5;

    cout<< knackSnackRec(val , wt, W, n)<<endl;
    return 0; 
}