// Ricardo Andres Arriaga Quezada
// A01570553

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct objeto
{
    int valor;
    int peso;
    float valpeso;
};

//Complejidad: O(2^n)

bool my_copm(const objeto& a, const objeto& b)
{
    return a.valpeso > b.valpeso;
}

int calcularVP(vector<objeto>& datos, int i, int vpAux, int wAux, int N, int W)
{
    int k=1+1;
    while(k < N && wAux + datos[k].peso <= W)
    {
        vpAux += datos[k].valor;
        wAux += datos[k].peso;
        k++;
    }
    if(k < N)
    {
        vpAux += ((W - wAux) * datos[k].valpeso);
    }

    return vpAux;
}

void bt_Helper(vector<objeto>& datos, int i, int va, int pa, int vp, int N, int W, int &valOp)
{
    if(i < N && pa <= W && vp > valOp)
    {
        if(va > valOp)
        {
            valOp = va;
        }

        bt_Helper(datos, i+1, va + datos[i+1].valor, pa + datos[i+1].peso, vp, N, W, valOp);
        int vpAux = calcularVP(datos, i+1, va, pa, N, W);
        bt_Helper(datos, i+1, va, pa, vpAux, N, W, valOp);
    }
}

int mochila(vector<objeto>& datos, int N, int W)
{
    int vpAux = calcularVP(datos, -1, 0, 0, N, W);
    int valOptimo = 0;
    bt_Helper(datos, -1, 0, 0, vpAux, N, W, valOptimo);
    return valOptimo;
}

int main()
{
    int n;
    int v;
    int p;
    int objs;
    int weight;
    int persons;
    int ans;
    float vp;
    vector<objeto> datos;
    vector<int> results;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> objs;
        for(int j = 0; j < objs; j++)
        {
            cin >> v >> p;

            vp = v * 1.0 / p;
            objeto dato;
            dato.valor = v;
            dato.peso = p;
            dato.valpeso = vp;
            datos.push_back(dato);
        }

        sort(datos.begin(), datos.end(), my_copm);

        cin >> persons;

        for(int k = 0; k < persons; k++)
        {
            cin >> weight;
            ans += mochila(datos, objs, weight);
        }

        results.push_back(ans);
        ans = 0;
        datos.clear();
    }

    for(int i = 0; i < results.size(); i++)
    {
        cout << results[i] << endl;
    }

    return 0;
}

/*
2
3
72 17
44 23
31 24
1
26
6
64 26
85 22
52 4
99 18
39 13
54 9
4
23
20
20
26
*/