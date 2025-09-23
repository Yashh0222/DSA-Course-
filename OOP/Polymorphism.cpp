#include<iostream>
using namespace std;

class A{
    public:
    void sayHello(){
        cout<<"Hello"<<endl;
    }
    // changing data type will not work we have to add parameter 
    int sayHello(char name){
        cout<<"Hello"<<endl;
        return 1;
    }
    // We can use same func name but using parater in functn called func overlaoding
    void sayHello(string name){
        cout<<"Hello"<<name<<endl;
    }
};
int main(){ 
    A a;
    a.sayHello();  
    return 0; 
}