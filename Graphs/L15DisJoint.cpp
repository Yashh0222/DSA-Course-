#include<iostream>
#include<vector>
using namespace std;

class disJoint{
    public:
    int n;
    vector<int> par; // vec to add par of curr vertex
    vector<int> rank; // stores rank or height or level of vertex 

    disJoint(int n){
        this->n = n;

        for (int i = 0; i < n; i++)
        {
            par.push_back(i); // first make the no itself as its par 
            rank.push_back(0); // rank should be 0
        }
        
    }

    int find(int x){ // this returns par of given vertex eg: par 2->0  
        if(par[x] == x){ // if par is same as iteself retrun it 
            return x;
        }

        return find(par[x]); // recursive checking  for more optimisatin -> return par[x] = find(par[x]);
    }

    void unionByRank(int a, int b){
        int parA = find(a); // this finds par of given int to form inion 
        int parB = find(b);

        if(rank[parA] == rank[parB]){ //if rank is equal 
            par[parB] = parA; //then make parA the par of parB
            rank[parA]++; // increase rank of parA as parB is increased 
        }else if(rank[parA] > rank[parB]){
            par[parB] = parA; 
        }else{
            par[parA] = parB;
        }
    }

    void getInfo(){
        for (int i = 0; i < n; i++)
        {
            cout<<i<<" : "<<par[i]<<" , "<<rank[i]<<endl; 
        }
        
    }
};
int main(){ 
    disJoint dj(6);

    dj.unionByRank(0,2);
    cout<< dj.find(2)<< endl;
    dj.unionByRank(1,3);
    cout<< dj.find(3)<< endl;
    dj.unionByRank(2,5);
    cout<< dj.find(5)<< endl;
    dj.unionByRank(0,3);
    cout<< dj.find(2)<< endl;
    dj.unionByRank(0,4);

    dj.getInfo(); 
    return 0; 
}