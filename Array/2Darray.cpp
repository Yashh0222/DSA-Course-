#include<iostream>
using namespace std;

bool ispresent(int arr[][3],int target , int row , int col){
    
    for(int row=0; row<3; row++){
        for (int col = 0; col < 3; col++)
        {
           if(arr[row][col] == target){
            return 1;
           }
        }
        
    }return 0;
}

//printing row sum
void printrowsum(int arr[][3], int row , int col){
    cout<<"printing sum-> "<<endl;
      for(int row=0; row<3; row++){
        int sum =0;
        for (int col = 0; col < 3; col++)
        {
           sum+= arr[row][col];
        }
        cout<<sum<<" ";
    }
}

//printing col sum
void printcolsum(int arr[][3], int row , int col){
    cout<<"printing sum-> "<<endl;
      for(int col=0; col<3; col++){
        int sum =0;
        for (int row = 0; row < 3; row++)
        {
           sum+= arr[row][col];
        }
        cout<<sum<<" ";
    }
}

int largestrowsum(int arr[][4], int row , int col){

    int maxi = INT16_MIN;
    int rowIndex = -1;

      for(int row=0; row<3; row++){
        int sum =0;
        for (int col = 0; col < 3; col++)
        {
           sum+= arr[row][col];
        }
        if (sum > maxi)
        {
            maxi = sum;
            rowIndex = row;
        }
        
    }
    cout<<"the maximum sum "<<maxi<<endl;
    return rowIndex; 
}
int main(){ 
    
    //int arr[3][3] ;
    int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    //int arr[3][4]={{1,11,111,1111},{2,22,222,2222},{3,33,333,3333}};
   
   //row wise input 
   /* for(int row=0; row<3; row++){
        for (int col = 0; col < 3; col++)
        {
            cin>>arr[row][col];
        }
        
    }
    
    //coloume wise input 
    for(int col=0; col<4; col++){
        for (int row = 0; row < 3; row++)
        {
            cin>>arr[row][col];
        }
        
    }
    */
    for(int row=0; row<3; row++){
        for (int col = 0; col < 3; col++)
        {
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
        
    }
/*
    cout<<"Enter the element to search "<<endl;
    int target;
    cin>>target;

    if(ispresent(arr , target , 3, 3))
    {
        cout<<"Element is present"<<endl;
    }else{
     cout<<"Element is not present"<<endl;     
    }
    
    printrowsum(arr, 3,3);
    printcolsum(arr, 3,3);
*/
 
 int ansindex = largestrowsum(arr,3,4);
 cout<<"maximum row index = "<<ansindex<<endl;
    return 0; 
}