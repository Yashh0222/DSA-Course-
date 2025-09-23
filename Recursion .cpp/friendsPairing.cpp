#include<iostream>
using namespace std;

int friendsPairing(int n){
    if(n == 1 || n == 2){
        return n;
    }

    //For single friend pairing
    int ans1 = friendsPairing(n-1);// n-1 is used bcz one n is used & left part is n-1  
    
    //For two friends to pair(any one friend can form pair with every friend)
    int ans2 = (n-1) * friendsPairing(n-2);// same here 

    return ans1 + ans2;
}
int main(){ 
    
    cout<<friendsPairing(4)<<endl;
    return 0; 
}