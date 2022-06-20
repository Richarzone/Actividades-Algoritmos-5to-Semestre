//Ricardo Arriaga
//A01570553

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX
#define Edge pair<int, int>         
#define Graph vector<vector<Edge>> 
#define Vertex pair<int, int> 

//Complejidad: O(n log(n))
vector<int> dijkstra(Graph& G, int source)
{
    vector<int> dist(G.size(), INF);
    dist[source] = 0;
    priority_queue<Vertex, vector<Vertex>, greater<Vertex>> queue;

    Vertex vs(0, source);
    queue.push(vs);
    while(!queue.empty())
    {
        int u = queue.top().second;
        queue.pop();
        for(int i = 0; i < G[u].size(); i++)
        {
            Edge e = G[u][i];
            int v = e.first;
            int w = e.second;

            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                Vertex vtx(dist[v], v);
                queue.push(vtx);
            }
        }
    }
    return dist;
}

int main()
{
    int n;
    int nodes;
    int edges;
    char u;
    char v;
    int w;

    int numU;
    int numV;
    char ans = 'A';
    int greater = 0;
    vector<char> results;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> nodes >> edges;
        Graph G(nodes);

        for(int j = 0; j < edges; j++)
        {
            cin >> u >> v >> w;
            numU = u - 'A';
            numV = v - 'A';

            Edge edge1(numV, w);
            G[numU].push_back(edge1);
            Edge edge2(numU, w);
            G[numV].push_back(edge2);
        }

        vector<int> distances = dijkstra(G, 0);

        for(int j = 0; j < distances.size(); j++)
        {
            if(greater < distances[j])
            {
                greater = distances[i];
                ans = j + 'A';
            }
        }
        results.push_back(ans);
    }

    for(int i = 0; i < results.size(); i++)
    {
        cout << "Case " << i + 1 << ": " << results[i] << endl;
    }

    return 0;
}

/*
2
5 7
A B 5
A C 4
A D 7
B E 3
C D 2
C E 4
D E 1
4 6
A B 1
A C 1
A D 1
B C 1
B D 1
C D 1
*/