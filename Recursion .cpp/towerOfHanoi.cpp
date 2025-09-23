#include<iostream>
using namespace std;
//A-> sourse, B -> Helper, C -> destination 
void TOH(int n, char A,char B, char C){

    //BAse case
    if(n == 0){
        return;
    }
    //calling func to shift plates 
    TOH(n-1, A, C, B);
    //n-1 is no disc to transsfer, first upper disc goes to helper c and 2nd disc goes to b 
    cout<<A<<" to "<<C<<endl;//printing the flow

    TOH(n-1, B, A, C);
    //disc present at B goes to C using helper A 
}
int main(){ 
    TOH(3,'A', 'B', 'C');
    return 0; 
}