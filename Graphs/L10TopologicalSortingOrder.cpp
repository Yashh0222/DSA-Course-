#include<iostream>
#include<list>
#include<vector>
#include<stack>
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

    void topoHelper(int src, vector<bool> &vis, stack<int> &s){
        vis[src] = true;

        list<int> neighbour = l[src];
        
        for(int v : neighbour){
            if(!vis[v]){
                topoHelper(v, vis, s);
            }
        }
        s.push(src); // to get topological order we add every src this gives order 
    } 

    void topoSort(){
        vector<bool> vis(V, false);
        stack<int> s;

        for (int i = 0; i < V; i++)
        {
            if(!vis[i]){
                topoHelper(i, vis, s);
            }
        }

        // to print topological sort 
        while (!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }       
        
        
    }

};
int main(){ 
    int V = 6;
    Graph graph(V);

    graph.addEdges(2,3);
    graph.addEdges(3,1);
    graph.addEdges(4,0);
    graph.addEdges(4,1);
    graph.addEdges(5,0);
    graph.addEdges(5,2);
 
    graph.topoSort();
    
    return 0; 
}