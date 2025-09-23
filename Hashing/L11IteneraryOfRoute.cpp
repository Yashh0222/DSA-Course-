#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_map>
using namespace std;

// To print route tickets available to go through all stations
void printItinerary(unordered_map<string, string> tickets){ //<from , to>
    // first start point which will be present only in from not to 
    // create unordered set and insert to values to set 

    unordered_set<string> to;
    for(pair<string, string> ticket : tickets){ //created pair to access (to) val
        to.insert(ticket.second); // added (to) values to set(to)
    }

    string start=""; // store start
    for(pair<string, string> ticket : tickets){
        if(to.find(ticket.first) == to.end()){ // this condn find start which is not present in set(to)
            start = ticket.first;
        }
    }

    // print start 
    cout<< start <<"->";
    while(tickets.count(start)){
        cout<<tickets[start]<<"->"; // print val of key start eg: mumbai is start and delhi is val
        start = tickets[start]; // update START to delhi and so on 
    }
    cout<<"destination"<<endl;

}
int main(){ 
    unordered_map<string, string> tickets ;
    tickets["chennai"] = "bengaluru"; 
    tickets["mumbai"] = "delhi"; 
    tickets["goa"] = "chennai"; 
    tickets["delhi"] = "goa";
    
    printItinerary(tickets);
    
    return 0; 
}