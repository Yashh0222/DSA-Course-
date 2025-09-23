#include<iostream>
using namespace std;
int waterTrap(int *heights, int n ){
    int leftMax[20000], rightMax[20000];
    leftMax[0] = heights[0];    //initilising first element to infinity for checking which cancels to 
    rightMax[n-1] = heights[n-1];

    //traverse to find the maximum elemnts towrds its left to trap water
    for(int i=1; i<n; i++){
        leftMax[i] = max(leftMax[i-1],heights[i-1]);
    }

    // same for right side(finding the top most elements beside every element so we can trap water)
    for(int i=n-2; i>=0; i--){
        rightMax[i] = max(rightMax[i+1],heights[i+1]);
    }

    int waterTrapped = 0;
    for(int i=0;i<n;i++){
        int currWater = min(leftMax[i],rightMax[i])-heights[i];
        if(currWater > 0){
            waterTrapped += currWater;
        }
    }
    cout<<"water Trapped = "<<waterTrapped<<endl;
    return waterTrapped;
}
int main(){ 
    int heights[7] = {4,2,0,6,3,2,5};
    int n = sizeof(heights)/sizeof(int);

    waterTrap(heights ,n);
    return 0; 
}