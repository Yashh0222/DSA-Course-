#include<iostream>
using namespace std;

int countOfNum(int arr[2][3],int n,int m ,int num){
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j] == num){
                cnt++;
            }
        }
        
    }
   if(cnt == 0){
    cout<<"Element is not present"<<endl;
   }else{
    cout<<"Count is = "<<cnt<<endl;
   }
   
}
int main(){ 
    int arr[2][3] = {{4,7,8},
                     {8,8,7}};

    countOfNum(arr, 2, 3, 7);
    return 0; 
}