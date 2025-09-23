#include<iostream>
#include<queue>
using namespace std;

//To create student and marks pair for which gives max value (max heap)
class student {
    public: 
    int marks;
    string name;

    student(string name, int marks){
        this->marks = marks;
        this->name = name;
    }

    bool operator < (const student &obj) const{ // we have to overload operator '<' for comparison blw marks and names to be given as max heap 
        return this->marks < obj.marks; // used for giiving marks as max heap 
        //return this->name < obj.name; // used for giving name as max heap
        //return this->marks > obj.marks; //by changing symbool it gives minheap 
    }
};
int main(){ 
    priority_queue<student> pq;

    pq.push(student("yash", 85));
    pq.push(student("bak", 95));
    pq.push(student("sanket", 65));

    while (!pq.empty())
    {
        cout<<"top : "<<pq.top().name<<","<<pq.top().marks<<endl;
        pq.pop();
    }
    
    return 0; 
}