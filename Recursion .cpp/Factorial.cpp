#include<iostream>
using namespace std;

int Factorial(int n){
    
    if(n==0){
        return 1;

    }

    int smallProblem = Factorial(n-1);
    int BigProblem = n * smallProblem;

    return BigProblem ;

}
int main(){ 
    
    int n;
    cin>>n;

    int ans = Factorial(n);
    cout<<ans<<endl;
    return 0;

}