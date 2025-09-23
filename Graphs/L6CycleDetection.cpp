#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
    int V;
    list<int> * l;

    public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V]; 
    }

    void addEdges(int u, int v){ //u---v 
        l[u].push_back(v); // eg: if edge (0,1) at idx:0 1 will gewt added   
        l[v].push_back(u); // similarly at idx:1 0 will get in list same process occurs till all edges get added
    }

    void print(){
        for (int i = 0; i < V; i++) // loop on vertises u: 0,1,2,3,4
        {
            list<int> neighbour = l[i];
            cout<<i<<" : ";
            for(int v: neighbour){
                cout<<v<< " ";
            }
            cout<<endl;
        }
        
    }

    
    
    bool cycleDetectionHelper(int src, int par, vector<bool> &vis){
        vis[src] = true;

        list<int> neighbours = l[src];
        
        for(int v : neighbours){
            if(!vis[v]){
                if(cycleDetectionHelper(v, src, vis)){ // here vertex become parent to neighbour  eg: src is given as parents
                    return true;
                }
            }else{
                if(v != par){
                    return true ; // cycle detected 
                }
            } 
        }

        return false;
    } 

    bool cycleDetection(){
        vector<bool> vis(V, false);
        return cycleDetectionHelper(0, -1, vis); //start par with -1 when it goes to vertex then after adding 1 we get par 0
    }
};
int main(){ 
    int V = 5;
    Graph graph(V);

    graph.addEdges(0,1);
    graph.addEdges(0,2);
    graph.addEdges(0,3);

    graph.addEdges(1,2);

    graph.addEdges(3,4);

    cout<<graph.cycleDetection();
    return 0; 
}