#include<iostream>
#include<list>
#include<vector>
#include<queue>
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

    void BFS(){
        queue<int> q;
        vector<bool> vis(V, false);

        q.push(0);
        vis[0] = true;

        while (q.size() > 0 )
        {
            int u = q.front(); // storing it for future use (u is curr vertex)
            q.pop();
            cout<<u<<" ";
            
            list<int> neighbours = l[u]; // accesing curr vertex all neighbours 
            for(int v : neighbours){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
            
        }
        cout<<endl;
    }
};
int main(){ 
    Graph graph(7);

    graph.addEdges(0,1);
    graph.addEdges(0,2);
    graph.addEdges(1,3);
    graph.addEdges(2,4);
    graph.addEdges(3,4);
    graph.addEdges(3,5);
    graph.addEdges(4,5);
    graph.addEdges(5,6);

    graph.BFS();
    return 0; 
}