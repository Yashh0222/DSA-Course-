#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// to find lagest rectangle area b/w slides gives heights to find breadths

void maxAreaHistogram(vector<int> heights){
     int n = heights.size();
    vector<int> nsl(n);// nsl = next smaller left b/w slides
    vector<int> nsr(n);// nsr = next smaller right b/w slides
    stack<int> s;

    // finding nsl values 
    nsl[0] = -1; // first elemnt didnt have any smaller height so -1
    s.push(0); //and push index to stack 

    for (int i = 0; i < heights.size(); i++)
    {
        int curr = heights[i];
        while (!s.empty() && curr <= heights[s.top()])
        {
            s.pop();
        }

        if (s.empty())
        {
            nsl[i] = -1;
        }else{
            nsl[i] = s.top();
        }
        s.push(i);
        
    }
    
    //befor adding nsr empy stack
    while (!s.empty())
    {
        s.pop();
    }
    
    // finding nsr values we have use backward loop for nsr 
    // we have to last height if there is s,maler height 
    //int n = heights.size();
    nsr[n-1] = n;
    s.push(n-1); 
    
    for (int i = n-2; i >= 0; i--)
    {
        int curr = heights[i];
        while (!s.empty() && curr <= heights[s.top()])
        {
            s.pop();
        }

        if(s.empty()){
            nsr[i] = n;
        }else{
            nsr[i] = s.top();
        }
        s.push(i);
    }
    
    // calculating max area 
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
         int ht = heights[i];
         int wdt = nsr[i] - nsl[i] -1; // this formula gives us width extra -1 is used to get desired result

         int area = ht * wdt;
        
         maxArea = max(area , maxArea);
    }
    
    cout<<"Max Area of histogram is : "<<maxArea<<endl;
    

} 

int main(){ 
    vector<int> heights = {2 ,1 ,5,6,2,3};
    maxAreaHistogram(heights);
    return 0; 
}