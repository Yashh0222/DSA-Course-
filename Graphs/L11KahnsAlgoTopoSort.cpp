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
    
    // To find topological sorting using khan algo using BFS
    void calcInDegree(vector<int> &inDeg){
        for (int u = 0; u < V; u++)
        {
            list<int> neighbours = l[u];
            for(int v: neighbours){ //u-->v this finds the indegre of vertex neighbours ansd increse it 
                inDeg[v]++;                
            }
        }
        
    }

    // topological sort using bfs kahn's algo using indegree if it has indegree = 0 theen print it 
    void topoSort2(){
        vector<int> inDeg(V, 0);
        calcInDegree(inDeg); // we find indegre for every node and push it to vec 
        queue<int> q; // we use queue to print it in order 

        for (int i = 0; i < V; i++)
        {
            if(inDeg[i] == 0){
                q.push(i); // push it if it has 0 indegree                           
            }
        }

        while(q.size() > 0){
            int curr = q.front();
            q.pop();
            cout<<curr<<" ";

            list<int> neighbours = l[curr];
            for(int v : neighbours){
                inDeg[v]--; // make curr vertex indegree 1 less bcz of we have removed that vertex so  
                if(inDeg[v] == 0){
                    q.push(v);
                }
            }
        }
        cout<<endl;

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
 
    graph.topoSort2();
    return 0; 
}