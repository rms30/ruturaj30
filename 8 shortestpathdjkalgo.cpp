#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> iPair;

class Graph
{
int V;
vector<vector<iPair>> adj;
public:
Graph(int V)
{
this->V = V;
adj.resize(V);
}
void addEdge(int u, int v, int w)
{
adj[u].push_back(make_pair(v, w));
adj[v].push_back(make_pair(u, w));
}

void dijkstra(int src)
{
priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
vector<int> dist(V, INT_MAX);
pq.push(make_pair(0, src));
dist[src] = 0;
while (!pq.empty())
{
int u = pq.top().second;
pq.pop();
for (auto &neighbor : adj[u])
{
int v = neighbor.first;
int weight = neighbor.second;
if (dist[v]>dist[u]+weight)
{
dist[v]=dist[u]+weight;
pq.push(make_pair(dist[v], v));
}
}
}
cout<<"Vertex\t\tDistance from Source\n";
for (int i = 0; i < V; i++)
{
cout<<i<<"\t\t"<<dist[i]<<"\n";
}
}
};

int main()
{
int V = 5;
Graph g(V);
g.addEdge(0, 1, 10);
g.addEdge(0, 2, 5);
g.addEdge(1, 2, 2);
g.addEdge(1, 3, 1);
g.addEdge(2, 3, 9);
g.addEdge(2, 4, 2);
g.addEdge(3, 4, 4);
int source = 0;
g.dijkstra(source);
return 0;
}