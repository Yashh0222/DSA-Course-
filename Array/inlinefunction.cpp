#include<iostream>
using namespace std;

// Heere inline funtion helps reduse funtion call overhead and reduse extra memeory uses 
//only used for 1 line code or 2 
inline int getMax(int a, int b){
    return (a>b) ? a:b;
}
int main(){ 
    
    int a = 1,b = 2;
    int ans = 0;

    ans = getMax(a,b);
    cout<<ans<<endl;

    a = a + 3;
    b = b + 1;
    ans = getMax(a,b);
    cout<<ans<<endl;
    return 0; 
}