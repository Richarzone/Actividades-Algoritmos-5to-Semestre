#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <iomanip>

using namespace std; 
  
typedef  pair<int, int> iPair; 
  
#define MAX INT_MAX

struct Graph { 
    int V, E, costMSTKruskal, costMST; 
    float costMSTPrim;
    vector<pair<int, pair<int, int>>> edges; 
    vector<vector<pair<int, float>>> adjList;
  
    Graph(int V, int E){ 
        this->V = V; 
        this->E = E;
        adjList.resize(V); 
        costMSTKruskal = 0;
        costMSTPrim = 0.0;
    } 
  
    void addEdge(int u, int v, float w) { 
        edges.push_back({w, {u, v}});
        adjList[u].push_back({v,w});
    } 
    void load();
    void print();
    void kruskalMST(); 
    void primMST();
    void coordsToGraph();
}; 
  
// To represent Disjoint Sets 
struct DisjointSets 
{ 
    int *parent, *rnk; 
    int n; 
  
    DisjointSets(int n){ 
        this->n = n; 
        parent = new int[n+1]; 
        rnk = new int[n+1]; 
        for (int i = 0; i <= n; i++){ 
            rnk[i] = 0; 
            parent[i] = i; 
        } 
    } 
  
    // Find the parent of a node 'u' 
    // Path Compression 
    int find(int u) 
    { 
        /* Make the parent of the nodes in the path 
           from u--> parent[u] point to parent[u] */
        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    } 
  
    // Union by rank 
    void merge(int x, int y) 
    { 
        x = find(x), y = find(y); 
  
        /* Make tree with smaller height 
           a subtree of the other tree  */
        if (rnk[x] > rnk[y]) 
            parent[y] = x; 
        else // If rnk[x] <= rnk[y] 
            parent[x] = y; 
  
        if (rnk[x] == rnk[y]) 
            rnk[y]++; 
    } 
}; 

//Complejidad: O(n*m)
void Graph::coordsToGraph()
{
    float a, b;
    float c;
    int anterior = MAX;
    vector<pair<float, float>> coords;

    for (int i=0; i<V; i++)
    {
        cin >> a >> b;
        coords.push_back(make_pair(a, b)); 
    }

    //Calcular Edges
    for(int i = 0; i < V-1; i++)
    {
        float dist = MAX;
        float curDist = 0.0;
        int t = 1;

        for(int j = 0; j < coords.size(); j++)
        {
            if(j != i && j != anterior)
            {
                pair<float, float> coord1 = coords[i];
                pair<float, float> coord2 = coords[j];
                
                float x = abs(coord1.first - coord2.first);
                float y = abs(coord1.second - coord2.second);

                //Si (X != 0 && Y != 0) = hay inclinacion
                if(x != 0 && y != 0)
                {
                    curDist = sqrt((pow(x,2) + pow(y,2)));
                }
                else //No hay inclinacion
                {
                    curDist = max(x, y);
                }
                
                if(curDist < dist) //Se actualiza el nodo mas cercano y se reinicia la variable de empates
                {
                    dist = curDist;
                    t = 1;
                }
                else if(curDist == dist) //Se revisa por empates entre 2 o mas nodos y se marcan cuantos nodos empatan
                {
                    t++;
                }
            }
        }

        //Se agregan los vertices que tengan la ruta menor
        for(int x = 1; x <= t; x++)
        {
            addEdge(i,i+x,dist);
        }

        anterior = i;
    }
}

//Complejidad: O(v^2)
void Graph::primMST()
{
    int selectedSource = 0;
    costMSTPrim = 0;
    unordered_set<int> selected;
    unordered_set<int> missing;
    selected.insert(0);
    
    for(int i = 1; i < V; i++)
    {
        missing.insert(i);
    }
    
    int conected = V - 1;
    float minCost;
    int selVertex;
    
    while (conected > 0)
    {
        minCost = INT_MAX;
        for(auto it1:selected)
        {
            for(auto it2 = adjList[it1].begin(); it2 != adjList[it1].end(); ++it2)
            {
                if(missing.find((*it2).first) != missing.end() && (*it2).second < minCost)
                {
                    minCost = (*it2).second;
                    selVertex = (*it2).first;
                }
            }
        }
        costMSTPrim += minCost;
        selected.insert(selVertex);
        missing.erase(selVertex);
        conected--;
    }
}


int main()
{ 
    int V;
    cin >> V;
    Graph g(V, V-1); 
    
    g.coordsToGraph();
  	g.primMST();
    cout << fixed << setprecision(2) << g.costMSTPrim << endl;  	
    return 0; 
} 

/*
3
1.0 1.0
2.0 2.0
2.0 4.0
*/