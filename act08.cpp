#include <iostream>
#include <vector>

using namespace std;

//Complejidad: O(n^3)

void arcos(int mat[100][100], int p[100][100], int m)
{
    int a;
    int b;
    int c;

    for(int i = 0; i < 100; i++)
    {
        mat[i][i] = 0;
        p[i][i] = -1;
        for(int j = i+1; j < 100; j++)
        {
            mat[i][j] = mat[j][i] = INT_MAX;
            p[i][j] = p[j][i] = -1;
        }   
    }

    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        mat[a-1][b-1] = mat[b-1][a-1] = c;
    }
}

void floydAndQueries(int mat [100][100], int p[100][100], int n, int q, vector<vector<int>>& ans)
{
    int a;
    int b;
    vector<int> query;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                mat[j][k] = min(mat[j][k], max(mat[j][i], mat[i][k]));
            }
        }
    }

    for(int i = 0; i < q; i++)
    {
        cin >> a >> b;

        if(mat[a-1][b-1] == INT_MAX)
        {
            query.push_back(-1);
        }
        else
        {
            query.push_back(mat[a-1][b-1]);
        }
    }

    ans.push_back(query);
    query.clear();
}

int main()
{
    int t;
    int n;
    int m;
    int q;

    int mat[100][100];
    int p[100][100];
    vector<vector<int>> ans;

    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n >> m >> q;
        arcos(mat, p, m);
        floydAndQueries(mat, p, n, q, ans);
    }
    
    for(int i = 0; i < t; i++)
    {
        cout << "Case " << i+1 << ":" << endl;
        for(int j = 0; j < ans[i].size(); j++)
        {
            if(ans[i][j] == -1)
            {
                cout << "no path" << endl;
            }
            else
            {
                cout << ans[i][j] << endl;
            }
        }
    }

    return 0;
}

/*
2
7 9 3
1 2 50
1 3 60
2 4 120
2 5 90
3 6 50
4 6 80
4 7 70
5 7 40
6 7 140
1 7
2 6
6 2
7 6 3
1 2 50
1 3 60
2 4 120
3 6 50
4 6 80
5 7 40
7 5
1 7
2 4
*/