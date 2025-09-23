#include<iostream>
using namespace std;

/*totalOcc(int arr[], int n){
     
    int total = 0;

    total = (lastOcc - firstOcc) + 1;

}*/
int firstOcc(int arr[], int n , int key ){
   
    int s =0,e=n-1;
    int ans= -1;
    int mid = s + (e-s)/2;

    while (s<=e)
    {
        if (arr[mid] == key )
        {
            ans = mid;
            e = mid -1;
        }else if (key > arr[mid])
        {
            s = mid+1;
        }else if (key < arr[mid])
        {
             e =mid -1;
        }
        mid = s + (e-s)/2;
    }
    return ans ;
}

int lastOcc(int arr[], int n , int key ){
   
    int s =0,e=n-1;
    int ans= -1;
    int mid = s + (e-s)/2;

    while (s<=e)
    {
        if (arr[mid] == key )
        {
            ans = mid;
            s = mid + 1;
        }else if (key > arr[mid])
        {
            s = mid+1;
        }else if (key < arr[mid])
        {
             e =mid -1;
        }
        mid = s + (e-s)/2;
    }
    return ans ;
}
int main(){ 
    int arr[8] = {1,2,3,3,3,3,3,4};
    
    int firstindex = firstOcc(arr , 8 , 3);
    cout<<" First Index of 3 is  "<<firstindex<<endl;

    int lastindex = lastOcc(arr , 8 , 3);
    cout<<" Last Index of 3 is  "<<lastindex<<endl;

    cout<<"the total  occuranse of 3 is -> "<<(lastindex - firstindex) + 1<<endl; 
    return 0; 
}