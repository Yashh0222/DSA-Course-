#include<iostream>
#include<vector>
using namespace std;
//simple code using recursion TC: 0(2^n)
int fib(int n){
    if (n == 0 || n ==1)
    {
        return n;
    }

    return fib(n-1) + fib(n-2); // recursive call for fibonacci series 
    
}

//Using Dynamic Programming TC: 0(N) (first type : Memoisation)
int fibDP(int n, vector<int> &f){
    if (n ==0 || n == 1)
    {
        return n;
    }

    if (f[n] != -1) // this adds every tree absoulte value to vec for futre use reduces recursion  
    {
        return f[n];
    }

    f[n] = fibDP(n-1, f) + fibDP(n-2, f); // this adds every repetative value to vec 
    return f[n];    
    
}

// DP (second type : Tabulation) using loop 
int fibTab(int n){
    vector<int> fib(n+1, 0);

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n+1 ; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];

    }

    return fib[n];
    
}
int main(){ 
    int n = 6;
    vector<int> f(n+1, -1);  //f(given n , vector with value -1)
    cout<<"fib using normal recursion " <<fib(n)<<endl;
    cout<<"fib using DP memoisatrion  " <<fibDP(n, f)<<endl;
    cout<<"fib using table or loops "<<fibTab(n)<<endl;
    return 0; 
}