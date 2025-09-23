#include<iostream>
using namespace std;

void reverseString(string& name , int i, int j){
 
    cout<<"call recieved for str "<<name<<endl;
    //Base case 
    if(i>j){
        return;
    }

    swap(name[i],name[j]);
    i++;
    j--;

    //Recursive call 
    reverseString(name,i,j);
}
int main(){ 
     
    string name = "yash";
    
    reverseString(name , 0 ,name.length()-1);

    cout<<name<<endl;
    return 0; 
}