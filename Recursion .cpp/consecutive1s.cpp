#include<iostream>
#include<string>
using namespace std;

void binString(int n, int lastIdx, string ans){
    
    if(n == 0){
        cout<<ans<<endl;
        return;
    }

    if(lastIdx != 1){// we have two add only pair without (1,1)
        binString(n-1, 0, ans + '0');
        binString(n-1, 1, ans + '1');
    }else{
        binString(n-1, 0, ans + '0');
    }
}
int main(){ 
    string ans = " ";
    binString(2, 0, ans);
    return 0; 
}