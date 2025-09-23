#include<iostream>
using namespace std;
//GLobal varible
int score = 51;

void a(int& i){
    cout<<"Score in a "<<score<<endl;
    cout<<i<< endl;
} 
void b(int& i){
    cout<<"Score in b "<<score<<endl;
    cout<<i<< endl;
} 

int main(){ 
    cout<<"Score in main "<<score<<endl;
    //score++; any funtion can changre the value of global varible and will be copied to other funtions 
    int i =5;
    a(i);
    b(i);
    return 0; 
}