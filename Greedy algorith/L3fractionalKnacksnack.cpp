#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<double,int> p1, pair<double,int> p2){
    return p1.first > p2.first ; // decending order because we have to add high value pproduct first in sack 
}

int fractionalKnacksack(vector<int> val, vector<int> wt, int w){
    int n = val.size();
    // we have to crete vec to store ratio of val and weights with index for sorting
    vector<pair<double, int>> ratio(n, make_pair(0.0,0)); 
    for (int i = 0; i < n; i++)
    {
        double r = val[i]/(double)wt[i]; 
        ratio[i] = make_pair(r , i);
    }
    
    sort(ratio.begin(),ratio.end(), compare);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int idx = ratio[i].second;
        if(wt[idx] <= w){
            //adding amount of whose wt is less than sack weight
            ans += val[idx];
            w -= wt[idx];
        }else{// if sack weigth is less than curr weight
            ans += ratio[i].first * w;
            w = 0;
            break;                        
        }
    }
    cout<<"maximum amount can be carried in total sack is = "<<ans<<endl;
    return ans;
}
int main(){ 
    vector<int> val = {60,100,120};
    vector<int> wt = {10,20,30};

    // w is sack caapcity
    int w = 50;

    fractionalKnacksack(val,wt , w);
    return 0; 
}