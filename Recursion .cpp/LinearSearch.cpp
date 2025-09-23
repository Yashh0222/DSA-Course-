#include<iostream>
using namespace std;

void print(int arr[] , int size)
{
    cout<<"search Arrray in every recurison is "<<size<<endl;
    for(int i = 0; i<size;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
bool linearSearch(int arr[]  , int size , int key){

    print(arr,size);
    if (size == 0)
    { 
        return false;
    }
    if(arr[0] == key ){
        return true;
    }else{
        bool remainingPart = linearSearch( arr + 1 , size - 1, key);
        return remainingPart;
    }
    
    
}
int main(){ 
    
    int arr[] = {2,4,1,6,3};
    int size = 5;
    int key = 3;

    int ans = linearSearch(arr , size , key );

    if(ans){
        cout<<"preesent "<<endl;
    }else{
        cout<<"Absent"<<endl;
    }
    return 0; 
}