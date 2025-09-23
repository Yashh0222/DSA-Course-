#include<iostream>
#include<string>
using namespace std;

int gridWays(int row,int col, int n, int m, string ans){

    //Base CAse after reching the matrix destination (MXN)
    if(row == n-1 && col == m-1){
        cout<<ans<<" "<<endl ;
         return 1;
    }
    // 2nd Base case at 1st row end col element it should go down if not then this is the condition
    if(row >= n || col >= m ){
        return 0;
    }
    
    // to go towards right
    int val1 = gridWays(row, col + 1, n, m, ans + 'R');

     // to go towards down
    int val2 = gridWays(row + 1, col , n, m, ans + 'D');

    return val1 + val2;
}


int main(){ 
    
    int n = 3;
    int m = 3;
    string ans = "";
    cout<<"No of Ways to reach destinaation in matrix is = " <<gridWays(0, 0, n, m,ans);
    return 0; 
}