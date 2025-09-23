#include<iostream>
using namespace std;

void reachHome(int src , int des){

    cout<<"sourse "<<src<<" destination "<<des<<endl;
    if(src == des){
    cout<<"pahoch gaya "<<endl;
      return ;
    }

    //oncrement the steps 
    src++;

    // Use Recursive conditon 
    reachHome(src ,des);
}
int main(){ 
    
    int des = 10;
    int src = 1;

    reachHome(src , des);
    return 0; 
}