#include<iostream>
#include<climits>//for INT-MAX
using namespace std;
void maxProfit(int *prises ,int n ){
    int bestBuy[10000]; 
    // this array is created to find best buy(this finds the minimum value from prises)
    bestBuy[0] = INT_MAX;
    for(int i = 1; i<n; i++){
        bestBuy[i] = min(bestBuy[i-1] , prises[i-1]);
        cout<<bestBuy[i];
    }cout<<endl;

    int maxProfit = 0;
    for(int i = 1; i<n; i++){
       int currProfit = prises[i] - bestBuy[i];
       maxProfit = max(maxProfit ,currProfit);
    }
    cout<<"Max Profit ="<<maxProfit<<endl;
}
int main(){ 
    int prises[] = {1,2,3,4,5};
    int n = sizeof(prises)/sizeof(int);

    maxProfit(prises ,5);
    return 0; 
}