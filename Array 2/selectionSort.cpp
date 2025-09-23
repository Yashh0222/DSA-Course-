#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>& arr, int n){
     for (int i = 0; i < n-1; i++)
     {
        int minIndex = i;

        for (int j = i+1; j < n; j++)
        {
           if(arr[j] < arr[minIndex])
            minIndex = j;
           
        }
        swap(arr[minIndex],arr[i]);
     }
    
     
}
int main(){ 
    vector<int> arr = {4,3,6,7};
    int size = 4;
   
    selectionSort(arr , 4);

   for(int i = 0; i < size; i++)
    {
      cout<< arr[i]<<" ";
    }
    cout<< endl;
     
    
    return 0; 
}