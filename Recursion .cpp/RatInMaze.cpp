#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool isSafe(int x,int y, int n,vector<vector<int>> visited,vector<vector<int>> &m){
    if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y] == 0 && m[x][y] == 1){
        return true;
    }else{
        return false;
    }
}

void solve(vector<vector<int>> &m, int n,vector<string> &ans,int x ,int y,vector<vector<int>> visited,string path){
// you reached x ,y
if(x == n-1 & y == n-1){
    ans.push_back(path);
    return;
}

visited[x][y]=1;

//four choises Down ,Left ,Up ,Right 

//Down 
int newx = x+1;
int newy = y;

if(isSafe(newx,newy,n,visited,m)){
    path.push_back('D');
    solve(m,n,ans,newx,newy,visited,path);
    path.pop_back();
}

//left 
 newx = x;
 newy = y-1;

if(isSafe(newx,newy,n,visited,m)){
    path.push_back('L');
    solve(m,n,ans,newx,newy,visited,path);
    path.pop_back();
}

//UP 
 newx = x-1;
 newy = y;

if(isSafe(newx,newy,n,visited,m)){
    path.push_back('U');
    solve(m,n,ans,newx,newy,visited,path);
    path.pop_back();
}

//Right 
 newx = x;
 newy = y+1;

if(isSafe(newx,newy,n,visited,m)){
    path.push_back('R');
    solve(m,n,ans,newx,newy,visited,path);
    path.pop_back();
}
visited[x][y] = 0;

}

int main(){ 
    vector<vector<int>> m = {
        {1,0,0,0},
        {1,1,0,1},
        {0,1,1,0},
        {1,1,1,1}
    };
    int n = m.size();
    vector<string> ans;

    if(m[0][0] == 0 || m[n-1][n-1] == 0){
        return 0;
    }

    vector<vector<int>> visited(n, vector<int>(n, 0)); // Initialize visited with 0
    string path = "";
    solve(m, n, ans, 0, 0, visited, path);

    // Sort and print paths
    sort(ans.begin(), ans.end());
    for (string p : ans) {
        cout << p << endl;
    }

    return 0;

}