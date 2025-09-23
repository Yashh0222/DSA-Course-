#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class Graph { 
    int V; 
    bool isUndir;
    list<pair<int, int>> * l;  

    public:
    Graph(int V, bool isUndir = true){
        this->V = V;
        this->isUndir = isUndir;
        l = new list<pair<int, int>> [V];
        
    }

    void addEdge(int u, int v, int wt){
        l[u].push_back(make_pair(v,wt));
        if(isUndir) 
            l[v].push_back(make_pair(u, wt));
           
    }

    void primsAlgo(int src){
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // mean heap used to fihnd minmum cost of every edge 
        // minheap = (wt, u)
        vector<bool> mst(V, false); // used to keep track of all vertices 

        pq.push(make_pair(0,src));
        int ans = 0; 

        while(pq.size() > 0 ){
            int u = pq.top().second;
            int wt = pq.top().first; // pair first gives weight b/w edges
            pq.pop();

            if(!mst[u]){ // this check if vertex is true or false if false it will make true if already true this will skip that verterx
                mst[u] = true;
                ans += wt;

                list<pair<int, int>> neighbours = l[u];
                for(pair<int, int> n: neighbours){
                    pq.push(make_pair(n.second, n.first));
                } 
            }

        }
        cout<<"final Mst is = "<<ans<<endl;
        
    }
};
int main(){ 
    // prim's algo graph 
    Graph graph(4);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(1, 3, 40);
    graph.addEdge(2, 3, 50);
    
    graph.primsAlgo(0);

    return 0; 
}