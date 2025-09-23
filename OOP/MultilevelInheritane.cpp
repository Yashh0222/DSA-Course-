#include<iostream>
using namespace std;

class Animal {
    public:
    int age;
    int weight;

    public:
    void speak(){
        cout<<"Speaking"<<endl;
    }
};

class Dog : public Animal {
    
};

class Labra : public Dog {
    
};
int main(){ 
    Labra l;
    l.speak();
    cout<<l.age<<endl;
    
    return 0; 
}