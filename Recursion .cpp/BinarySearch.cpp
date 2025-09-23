#include<iostream>
using namespace std;

void print(int arr[] , int s ,int e)
{
    cout<<"searcching array  "<<endl;
    for(int i = s; i<=e;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
bool binarySearch(int arr[], int s , int e, int key ){
    cout<<endl;
    print(arr,s,e);
    if(s > e){
        return false;
    }
    int mid = s + (e - s)/2;
    cout<<"mid element "<<arr[mid]<<endl;

    if(arr[mid] == key){
        return true;
    }

    if(arr[mid] < key ){
        return binarySearch(arr , mid +1 , e , key);
    }else{
        return binarySearch(arr ,s ,mid -1, key );
    }
}
   
int main(){ 

    int arr[] = {2,4,5,6,7};
    int size = 5;
    int key = 4;

    cout<<"Present or not "<<binarySearch(arr , 0 , size-1,key);
    return 0; 
}