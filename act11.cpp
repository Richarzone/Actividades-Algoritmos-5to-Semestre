// Ricardo Andres Arriaga Quezada
// A01570553

#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define MAX 21

using namespace std; 

struct Nodo
{
    int nivel;
    int costoAcum;
    int costoPos;
    int verticeAnterior;
    int verticeActual;
    bool visitados[MAX];
    bool operator < (const Nodo &otro) const 
    {
        return costoPos >= otro.costoPos;
    }
};

void iniciarMatriz(int matAdj[MAX][MAX])
{
    for(int i = 0; i < MAX; i++)
    {
        matAdj[i][i] = 0;
        for(int j = i+1; j < MAX; j++)
        {
            matAdj[i][j] = matAdj[j][i] = INT_MAX;
        }
    }
}

void leerArcos(int matAdj[MAX][MAX], int m)
{
    int c;
    char a, b;

    while(m--) 
    {
        cin >> a >> b >> c;

        matAdj[a-'A'][b-'A'] = c;
        matAdj[b-'A'][a-'A'] = c;

        cout << m << endl;
    }
}

void calcularCostoPosible(Nodo &nodoActual, int matAdj[MAX][MAX], int n)
{
    nodoActual.costoPos = nodoActual.costoAcum;
    int costoObtenido;
    for(int i = 1; i <= n; i++)
    {
        costoObtenido = INT_MAX;
        if(!nodoActual.visitados[i] || i == nodoActual.verticeActual)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i != j && (!nodoActual.visitados[j] || j == 1))
                {
                    costoObtenido = min(costoObtenido, matAdj[i][j]);
                }
            }
        }
        else
        {
            for(int j = 1; j <= n; j++)
            {
                if(!nodoActual.visitados[j])
                {
                    costoObtenido = min(costoObtenido, matAdj[i][j]);
                }
            }
        }
        nodoActual.costoPos += costoObtenido;
    }
}

int tsp(int matAdj[MAX][MAX], int n)
{
    int costoOpt = INT_MAX;
    Nodo primero;
    primero.nivel = 0;
    primero.costoAcum = 0;
    primero.verticeActual = 1;
    primero.visitados[1] = true;
    calcularCostoPosible(primero, matAdj, n);
    priority_queue<Nodo> pq;
    pq.push(primero);

    while (!pq.empty())
    {
        if(pq.top().costoPos < costoOpt)
        {
            
        }
    }
}

int main()
{
    int n; //n = vertex
    int m; //m = edges
    cin >> n >> m;
    int matAdj[MAX][MAX];
    iniciarMatriz(matAdj);
    leerArcos(matAdj, m);
    
    cout << tsp(matAdj, n) << endl;

    return 0;
}

/*
4 5
A B 5
A C 10
A D 8
B C 2
C D 1
*/

/*
5 7
A B 4
A C 8
A D 2
B C 7
B D 2
C D 1
D E 3
*/

/*
7 11
A B 2
A C 4
A D 6
B C 2
B E 6
C D 1
C E 3
D E 2
D F 3
E G 5
F G 4
*/

/*
5 10
A B 4
A C 8
A D 5
A E 3
B C 7
B D 2
B E 2
C D 1
C E 4
D E 3
*/

/*
5 8
A B 48
A C 17
B E 40
B C 50
B D 80
E C 55
E D 15
C D 18
*/