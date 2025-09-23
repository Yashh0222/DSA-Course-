#include<iostream>
using namespace std;
int main(){ 

    int num = 5;
    
    cout<<num<<endl;
    cout<<"Address of num "<<&num<<endl;

    int *ptr = &num;
    cout<<"addres of num "<<ptr<<endl;
    cout<<"value of num "<< *ptr <<endl;

    double d = 4.3;
    double *p2 = &d ;

    cout<<"addres of num "<<p2<<endl;
    cout<<"value of num "<<*p2<<endl;

    cout<<"size of integer "<<sizeof(num)<<endl;
    cout<<"size of pointer "<<sizeof(ptr)<<endl;
    cout<<"size of pointer "<<sizeof(p2)<<endl;
     
    return 0; 
}