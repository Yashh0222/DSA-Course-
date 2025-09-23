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
    
    void helper(int src, int dest, vector<bool> &vis, string &path){
        if(src == dest){
            cout<< path << dest <<endl;
            return ;
        }
        
        vis[src] = true;
        path += to_string(src); // this adds path in string form for int NUmbers 

        list<int> neighbours = l[src];

        for(int v : neighbours){
            if(!vis[v]){
                helper(v, dest, vis, path);
            }
        }
        path = path.substr(0, path.size()-1); // we have to backtrack to find out reamainng paths
        vis[src] = false; // for backtracking we have to make it false again to traverse

    }
    void printAllPaths(int src, int dest){ 
        vector<bool> vis(V, false);
        string path ="";
        helper(src, dest, vis, path);
    }
    
};
int main(){ 
    int V = 6;
    Graph graph(V);

    graph.addEdges(0,3);
    graph.addEdges(2,3);
    graph.addEdges(3,1);
    graph.addEdges(4,0);
    graph.addEdges(4,1);
    graph.addEdges(5,0);
    graph.addEdges(5,2);

    graph.printAllPaths(5, 1);
    return 0; 
}