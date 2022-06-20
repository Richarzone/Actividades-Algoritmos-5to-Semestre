// C++ implementation of Dinic's Algorithm
//Complejidad O(n^2)
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Edge{
    int v;   
    int flow;
    int C;   
    int rev ; 
};
 

class Graph
{
    int V; 
    int *level ; 
    vector< Edge > *adj;

    public:
    Graph(int V)
    {
        adj = new vector<Edge>[V];
        this->V = V;
        level = new int[V];
    }
 
    void addEdge(int u, int v, int C)
    {
        int tam = adj[v].size();
        Edge a{v, 0, C, tam};
        tam = adj[u].size();
        Edge b{u, 0, 0, tam};
        adj[u].push_back(a);
        adj[v].push_back(b); // reverse edge
    }
    
    bool BFS(int s, int t);
    int sendFlow(int s, int flow, int t, int ptr[]);
    int DinicMaxflow(int s, int t);
};

bool Graph::BFS(int s, int t){ //Revisa si es posible llegar desde el vertice inicial al final
    for (int i = 0 ; i < V ; i++)
        level[i] = -1;
    level[s] = 0;  
    queue< int > q;
    q.push(s);
 
    vector<Edge>::iterator i ;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (i = adj[u].begin(); i != adj[u].end(); i++){
            Edge &e = *i;
            if (level[e.v] < 0  && e.flow < e.C){
                // Level of current vertex is,
                // level of parent + 1
                level[e.v] = level[u] + 1;
                q.push(e.v);
            }
        }
    }
    return level[t] < 0 ? false : true ;
}
 
int Graph::sendFlow(int u, int flow, int t, int start[]){ //Se actulzia la variable de maFlow con temp_flow
    // Sink reached
    if (u == t){
        return flow;
    }
    for (  ; start[u] < adj[u].size(); start[u]++){
        Edge &e = adj[u][start[u]];                                    
        if (level[e.v] == level[u]+1 && e.flow < e.C){
            int curr_flow = min(flow, e.C - e.flow);
            int temp_flow = sendFlow(e.v, curr_flow, t, start);
            if (temp_flow > 0){
                e.flow += temp_flow;
                adj[e.v][e.rev].flow -= temp_flow;
                return temp_flow;
            }
        }
    }
    return 0;
}
 
int Graph::DinicMaxflow(int s, int t){
    // Corner case
    if (s == t)
        return -1;
 
    int total = 0;   
    while (BFS(s, t) == true){ // Si se alcanza el vertice final se actuasliza maxFlow
        int *start = new int[V+1] {0};
        while (int flow = sendFlow(s, INT_MAX, t, start)){
            total += flow;
        }
    }
    return total; //Se regresa el maxFlow
}
 
int main(){
    int n, m, s, t, a, b, c;
    cin >> n >> m;
    Graph g(n);
    for (int i=0; i<m; i++){
        cin >> a >> b >> c;
        g.addEdge(a-1, b-1, c);
    }
    cout << "The maximum speed is " << g.DinicMaxflow(0, n-1)<<".";
    return 0;
}

/*
4 5
1 2 3
2 4 2
1 3 4
3 4 5
4 1 3
*/