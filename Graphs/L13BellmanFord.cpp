#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Edge
{
public:
    int v;  // vertex
    int wt; // verttex weight

    Edge(int v, int wt)
    {
        this->v = v;
        this->wt = wt;
    }
};
// this is used to find shortest b/w vertex with which has -ve value 
void bellmanFord(vector<vector<Edge>> graph, int V, int src)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < V-1; i++)// to stop negetive loop
    {
        for(int u = 0; u<V; u++){
            for(Edge e : graph[u]){ // to get to every edge of curr vertex 
                if(dist[u] != INT_MAX && dist[e.v] > dist[u] + e.wt){
                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        cout<< dist[i] <<" ";        
    }
    
    
}
int main()
{
    int V = 5;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1, 2)); // this adds edge b/w 0--->1 with weight 2
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, -4));
    graph[2].push_back(Edge(3, 2));

    graph[3].push_back(Edge(4, 4));

    graph[4].push_back(Edge(1, -1));

    bellmanFord(graph, V, 0);

    return 0;
}