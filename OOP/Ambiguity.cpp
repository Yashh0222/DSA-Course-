#include<iostream>
using namespace std;
class A {
    public:
    void func(){
        cout<<" I am Yash "<<endl;
    }
};

class B {
    public:
    void func(){
        cout<<" I am Yash "<<endl;
    }
};

class C:public B, public A{
     
};
int main(){ 
    C c;
    //c.func(); this gives error instead use scope resolutio operator 
    c.A::func();
    c.B::func();
    return 0; 
}