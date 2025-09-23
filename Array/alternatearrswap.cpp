#include<iostream>
using namespace std;

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}


void swapAlternate(int arr[] , int size){
    for (int i = 0; i < size; i+=2)
    {
        if(i+1 < size){
            swap(arr[i] , arr[i+1]);
        }
    }
    
}
int main(){ 
  int even[6] = {2,5,4,3,1,7};
  int odd[5] = {2,5,4,3,7};
   
   swapAlternate(even,6);
   printArray(even ,6);
   cout<<endl;

   swapAlternate(odd,6);
   printArray(odd ,6);


    return 0; 
}