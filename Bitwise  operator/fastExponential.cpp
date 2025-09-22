#include<iostream>
using namespace std;

void fastExpo(int x, int n ){
    int ans =1;
     while (n > 0)
     {
        int lastDit = n & 1;
        if (lastDit)
        {
            ans = ans * x;
        }

        x = x * x;
        n = n >> 1;
        
     }
     cout<<ans<<endl;
}

int main(){ 

    fastExpo(2 ,2);
    
    return 0; 
}