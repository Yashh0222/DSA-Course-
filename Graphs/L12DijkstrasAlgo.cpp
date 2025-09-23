#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Edge{
    public: 
    int v; //vertex 
    int wt ; // verttex weight
    
    Edge(int v, int wt){
        this->v =  v;         
        this->wt =  wt;         
    }
};

 void dijkstra(int src, vector<vector<Edge>> graph, int V){
        // create priority queue with min Heap
        // pair<dist[v] , v> first->weight , second->vertex 
        priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap

        vector<int> dist(V, INT8_MAX); //  vec with V no of vertes with weight infinity 

        pq.push(make_pair(0, src));
        dist[src] = 0;
        
        while (pq.size() > 0)
        {
            int u = pq.top().second; // to get curr vertex eg: u = 0
            pq.pop();
            
            vector<Edge> edges = graph[u]; // this gives neighbour edges of u eg : 0 edges are 1, 2  
            for(Edge e : edges){ // here e.v gives neighbouring vertex and e.wt gives weight of neighbouring vertex
                if(dist[e.v] > dist[u] + e.wt){
                    dist[e.v] = dist[u] + e.wt;
                    pq.push(make_pair(dist[e.v], e.v));
                }
            }
        }

        for(int d : dist){
            cout<<d<<" ";
        }
        cout<<endl;
    }
int main(){ 
    int V = 6;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1,2)); //this adds edge b/w 0--->1 with weight 2 
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(2,1));
    graph[1].push_back(Edge(3,7));

    graph[2].push_back(Edge(4,3));

    graph[3].push_back(Edge(5,1));

    graph[4].push_back(Edge(3,2));
    graph[4].push_back(Edge(2,5));

    dijkstra(0, graph, V);
    
    return 0; 
}