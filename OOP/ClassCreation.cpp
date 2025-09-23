#include <iostream>
#include <cstring>
using namespace std;

class Hero
{
    // properties
private:
    int health;

public:
    char *name ;
    char level ;
    static int timeTOcomplete;

    Hero()
    {
        cout << "constructor called " << endl;
        name = new char[100];
    }

    // parametarised cnstructor
    Hero(int health,char level)
    {
        cout<<"this -> "<< this<<endl;
        this->health = health;
        this->level = level;
    }

    //copy constuctor 
    Hero(Hero& temp){

        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this-> name = ch; // deep copy by  making anaother array

        cout << " Copy constructor called " << endl;
        this->health = temp.health;
        this->level = temp.level;

    }
    void print()
    {
        cout<<endl;
        cout<< "[ Name : " << this -> name<<" , "; 
        cout<<" health: " << this -> health<<" , ";
        cout<<" level : " << this -> level<<" ]";
        cout<<endl;
    }

    int gethealth()
    {
        return health;
    }

    char getlevel()
    {
        return level;
    }

    void sethealth(int h)
    {
        health = h;
    }

    void setlevel(char ch)
    {
        level = ch;
    }

    
    void setName(char name[])
    {
        strcpy(this->name, name);
    }

    ~Hero(){
        cout<<"destructor bhai called "<<endl;
    }
   
};

int Hero::timeTOcomplete = 5;

int main()
{
    cout << Hero::timeTOcomplete << endl;

    Hero a;
    cout<<a.timeTOcomplete<<endl;
    /*
    //statically
    Hero a;

    //dynamically 
    Hero *b = new Hero();
    // maually we have to call othewise it will not delete 
    delete b;
    
    Hero hero1;

    hero1.sethealth(23);
    hero1.setlevel('U');
    char name[5] = "yash";
    hero1.setName(name);

    hero1.print();
   
    Hero hero2(hero1);
    hero2.print();

    hero1.name[0] = 'H';
    hero1.print();

    hero2.print();
    // shallow copy occurs to reduse this we use deep copy 

    

    Hero S(10 , 'H');
    S.print();

    Hero R(S);
    R.print();
    // constructor caalled sttically
    Hero yash(10);
    cout<<"the Address of yash  "<<&yash<<endl;
    yash.gethealth();

    // constructor called dynamically
    Hero *b = new Hero(11);  

    //static allocation
    Hero a;
    a.sethealth(80);
    a.setlevel('P');
    cout<<" The Health "<<a.gethealth()<<endl;
    cout<<" The level "<<a.level<<endl;

    // Dynamic Allocation
    Hero *b = new Hero;
    b->sethealth(50);
    b->setlevel('S');
    cout<<" The Health "<<(*b).gethealth()<<endl;
    cout<<" The level "<<(*b).level<<endl;

    cout<<" The Health "<<b->gethealth()<<endl;
    cout<<" The level "<<b->level<<endl;


    Hero yash ;

    cout<<" the Health is "<<yash.gethealth()<<endl;
    yash.sethealth(20);

    cout<<" the Health is "<<yash.gethealth()<<endl;

    yash.level = 'P';
    cout<<" the level is "<<yash.level <<endl;
    return 0;
    */
}
// only public function can be accesed directly
// By default class will have access specifer as private
// To access the private get & set with class will be used