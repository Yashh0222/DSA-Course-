#include<iostream>
using namespace std;
int main(){ 
  /*
    int arr[10] = {2, 5, 6 , 7};

    cout<<"address at first memeory block "<<arr<<endl;
    cout<<arr[0]<<endl;
    cout<<"address at first memeory block "<<&arr<<endl;

    cout<<"4th "<<*arr<<endl;
    cout<<"5th "<<*arr+1<<endl;
    cout<<"6th "<<*(arr+1)<<endl;
    cout<<"7th "<<arr[2]<<endl;
    cout<<"8th "<<*(arr+2) <<endl;

    int i =3;
    cout<<i[arr]<<endl;
    cout<<arr[i]<<endl;

    
   int temp[10];
   cout<<sizeof(temp)<<endl;
   cout<<sizeof(*temp)<<endl;
   cout<<sizeof(&temp)<<endl;

   int *ptr = &temp[0];
   cout<< sizeof(ptr) <<endl;
   cout<< sizeof(*ptr) <<endl;
   cout<< sizeof(&ptr) <<endl;


int a[20] = {1,2,3,5};

cout<<"->"<<&a[0]<<endl;
cout<<&a<<endl;
cout<<a<<endl;

int *p = &a[0];
cout<<p<<endl;
cout<<*p<<endl;
cout<<"->"<<&p<<endl;
*/

int arr[10];

//error
// arr = arr+1;

int *ptr = &arr[0];
cout<<ptr<<endl;
ptr = ptr +1 ;
cout<<ptr<<endl;
  return 0;
}