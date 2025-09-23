#include<iostream>
using namespace std;
int sum_array(int num[], int size){
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + num[i];
    }
    return sum;
    
}

int main(){ 
    int size;
    cin>>size;

    int num[5];

    for (int i = 0; i < size; i++)
    {
     cin>>num[i];
    }
     cout<<sum_array(num ,size);
    

    return 0; 
}