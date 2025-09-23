#include<iostream>
#include<list>
#include<iterator>
using namespace std;

void printList(list<int> ll){
    list<int>::iterator itr;
    for (itr = ll.begin(); itr != ll.end(); itr++)
    {
        cout<<(*itr)<<"->";
    }
    cout<<"NULL"<<endl;
}
int main(){ 

    list<int> ll;

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    printList(ll);
    //In built funtions 
    cout<<"Size of LL = "<<ll.size()<<endl;

    cout<<"Head Of LL = "<<ll.front()<<endl;
    cout<<"Tail Of LL = "<<ll.back()<<endl;

    ll.pop_back();
    ll.pop_front();
    printList(ll);
    return 0; 
}