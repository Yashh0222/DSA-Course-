#include<iostream>
using namespace std;

void update(int **p2){
   // p2 = p2 +1 ;
   // kuch change hua ? -> No 

    //*p2= *p2 +1 ;
    // kuch change hua ? -> Yes 

    **p2 = **p2 +1 ;
    // kuch change hua ? -> yes 
    
}
int main(){ 
    /*
    int i =5;
    int *p = &i;
    int **p2 = &p;

    cout<<"printing p "<<p<<endl;
    cout<<"address of p "<<&p<<endl;
    cout<< *p2 <<endl;

    cout<<i<<endl;
    cout<< *p <<endl;
    cout<< **p2 <<endl;

    cout<< &i <<endl;
    cout<< p <<endl;
    cout<< *p2 <<endl;

    cout<< &p <<endl;
    cout<< p2 <<endl;
  


    cout<<"Before "<<i<<endl;
    cout<<"Before "<<p<<endl;
    cout<<"Before "<<p2<<endl;
    update(p2);
    cout<<"after "<<i<<endl;
    cout<<"after "<<p<<endl;
    cout<<"after "<<p2<<endl;


    /*int first = 8;
    int second = 18;
    int *ptr = &second;
    *ptr = 9;
    //cout<<"First "<<first<<"second "<<second<<endl;

    int firsts = 8;
    int *p = &firsts;
    cout<<(*p)++<<" ";
    cout<<firsts<<endl;

    int *p = 0;
    int num = 110;
   // *p = num; gives segmentation error 
    p = &num;//insted use this
    cout<<*p<<endl;
 */

    int arr[] = {11,12,13,14};
    //int *ptr = arr++; // here it givees error because arr cant be plus in pointer 
    //cout<< *ptr <<endl;

    return 0; 
}