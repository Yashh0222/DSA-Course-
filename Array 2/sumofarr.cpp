#include<iostream>
#include<vector>
using namespace std;

vector<int> reverse(vector<int> v){

    int s = 0;
    int e = v.size()-1;

    while(s<e){
        swap(v[s++] , v[e--]);
    }
    return v;
}

vector<int> findArray(vector<int>&a ,int n ,vector<int>&b ,int m){
    int i = n-1; 
    int j = m-1; 
    int carry = 0; 
    vector<int> ans;

    while (i>=0 && j>=0)
    {
       int val1 = a[i];
       int val2 = a[j];

       int sum = val1 + val2 + carry;

       carry = sum/10;
       sum = sum%10;
       ans.push_back(sum);
       i--;
       j--;
    }
    //first case
     while (i>=0)
     {
       int sum = a[i] + carry;
       carry = sum/10;
       sum = sum%10;
       ans.push_back(sum);
       i--;
     }

     //second case
     while (j>=0)
     {
       int sum = b[i] + carry;
       carry = sum/10;
       sum = sum%10;
       ans.push_back(sum);
       j--;
     }

          //third case
     while (carry != 0)
     {
       int sum = carry;
       carry = sum/10;
       sum = sum%10;
       ans.push_back(sum);
       
     }
     return reverse (ans);
    
}

int main(){ 

    vector<int> a = {4,3,6,7};
    vector<int> b= {4,3,6,7};
    
    vector<int> ans = findArray(a, a.size(), b, b.size());
     for(int i = 0; i < ans.size(); i++) { 
        cout << ans[i] << " ";
         } cout << endl;
    
    return 0; 
}