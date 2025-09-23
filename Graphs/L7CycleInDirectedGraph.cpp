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
        l[u].push_back(v); // In directed graph only directed edges are added 
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
    
    bool helper(int src, vector<bool> &vis, vector<bool> &recPath){
        vis[src] = true;
        recPath[src] = true;

        list<int> neighbours = l[src];

        for(int v : neighbours){
            if(!vis[v]){
                if(helper(v, vis, recPath)){
                    return true;
                }
            }else{
                if(recPath[v]){ // if this is already true menans already in recpath so cycle is detected 
                    return true;
                }
            }
        }
        recPath[src] = false; // we have to backtrasck to maintain recursionpath
        return false;
    }
    
    bool cycledetectionInDirectedGraph(){
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false); // this is used to get cycle 
        
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (helper(i, vis, recPath))
                {
                    return true;
                }
                
            }
            
        }
        return false;        
    }

};
int main(){ 
    int V = 5;
    Graph graph(V);

    graph.addEdges(1,0);
    graph.addEdges(0,2);
    graph.addEdges(2,3);
    graph.addEdges(3,0);
 
    cout<<graph.cycledetectionInDirectedGraph();
    
    return 0; 
}