#include<iostream>
using namespace std;
//it has time complexity O(n^3) 
void maxSubArraySum1(int *arr , int n){
    int maxSum = INT8_MIN;
    for(int start = 0; start < n; start++){
        for(int end = start; end < n; end++){
              int currSum = 0; 
            for(int i = start ; i<=end; i++){
               currSum += arr[i];
           }
            cout<<currSum<<",";
            maxSum = max(maxSum ,currSum);

        }
        
        cout<<endl;
    }
  cout<<"Max sum sub array is : "<<maxSum<<endl;
}

//it has time complexity O(n^2) slightly optimised 

void maxSubArraySum2(int *arr , int n){
    int maxSum = INT8_MIN;
    for(int start = 0; start < n; start++){// start  = 2
        int currSum = 0; 
        for(int end = start; end < n; end++){// end = 2,3,4,5 it adds there itself
            currSum += arr[end];
            cout<<currSum<<",";
            maxSum = max(maxSum ,currSum);

        }
        
        cout<<endl;
    }
  cout<<"Max sum sub array is : "<<maxSum<<endl;
}

// kadane's alghorithm 
void maxSubArraySum3(int *arr , int n){
    int maxSum = INT8_MIN;
    int currSum = 0;

    for(int i=0 ;i < n; i++){
        currSum += arr[i];
        maxSum = max(maxSum , currSum);
        if(currSum < 0){
            currSum = 0;
        }
    }
    cout<<"Max sum of sub array is : "<<maxSum<<endl;
}
int main(){ 
    int arr[] = {1,2,3,4,5,6};
    int n =6;

    maxSubArraySum3(arr ,6);
    return 0; 
}