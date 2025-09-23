#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdges(int u, int v)
    {                      // u---v
        l[u].push_back(v); // eg: if edge (0,1) at idx:0 1 will gewt added
        l[v].push_back(u); // similarly at idx:1 0 will get in list same process occurs till all edges get added
    }

    void print()
    {
        for (int i = 0; i < V; i++) // loop on vertises u: 0,1,2,3,4
        {
            list<int> neighbour = l[i];
            cout << i << " : ";
            for (int v : neighbour)
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    bool isBipartite()
    {
        queue<int> q;
        vector<bool> vis(V, false);
        vector<bool> colour(V, -1); // colour is used to detect bipartite graph

        q.push(0);
        vis[0] = true;
        colour[0] = 0; // for blue = 0, for white = 1

        while (q.size() > 0)
        {
            int curr = q.front();
            q.pop();

            list<int> neighbours = l[curr];
            for (int v : neighbours)
            {
                if (!vis[v])
                { // to not use vis vector make this as colour[v] == -1 -> this is used to find unvisited vertex
                    vis[v] = true;
                    colour[v] = !colour[curr]; // for neighbour of curr vertex give alternate colour
                    q.push(v);
                }
                else
                {
                    if (colour[v] == colour[curr])
                    {
                        return false; // colour of curr vertex and neighbour become same then they are not bipartite graph
                    }
                }
            }
        }
        return true;
    }
};
int main()
{
    int V = 4;
    Graph graph(V);

    graph.addEdges(0, 1);
    graph.addEdges(0, 2);
    graph.addEdges(1, 3);
    graph.addEdges(2, 3);
    // graph.addEdges(0,3); // this gives unBipartite graph

    cout << graph.isBipartite();
    return 0;
}