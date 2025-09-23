#include<iostream>
#include<vector>
using namespace std;

/*void insertionSort(vector<int> &arr , int n){

    for (int i = 1; i < n; i++)
    {
      int temp = arr[i];
      int j = i-1;
       for (; j >=0 ; j--)
       {
        if (arr[j] > temp)
        {
            //shift
            arr[j+1] = arr[j];
        }else{
            break;
        }
        
       }
       arr[j+1] = temp;
       
    }
    
}*/

void insertionSort(vector<int> &arr , int n){

    int i = 1;
    while (i<n)
    {
        int temp = arr[i];
        int j = i-1;
        while (j>=0)
        {
            if (arr[j] > temp)
            {
                arr[j+1] = arr[j];
                
            }else{
                break;
            }
            j--;
        }
        arr[j+1] = temp;
        i++;
    }
    
}
int main(){ 
    vector<int> arr = {4,2,7,5,3};
    int size = 5;

    insertionSort(arr , 5);

    for (int j = 0; j < size; j++)
    {
        cout<<arr[j]<<" ";
    }
    cout<<endl;                   
    return 0; 
}