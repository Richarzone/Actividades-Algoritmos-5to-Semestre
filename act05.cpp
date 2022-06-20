#include <iostream>
#include <vector>

using namespace std;
//Ricardo Arriaga
//A01570553

//Complejidad: O(n*m)
int main()
{
    int n1;
    int n2;
    int p;
    int cont;
    vector<string> ans;

    cin >> n1 >> n2;

    while (n1 != 0 && n2 !=0)
    {
        vector<vector<bool>> vec( n1+1 , vector<bool> (n2+1));
        vector<int> t1(n1+1);
        vector<int> t2(n2+1);
        vector<int> c(n1+n2+1);

        t1[0] = 0;
        t2[0] = 0;
        c[0] = 0;
        vec[0][0] = true;


        for(int i = 1; i <= n1; i++)
        {
            cin >> p;
            t1[i] = p;
        }
        
        for(int i = 1; i <= n2; i++)
        {
            cin >> p;
            t2[i] = p;
        }

        for(int i = 1; i <= (n1+n2); i++)
        {
            cin >> p;
            c[i] = p;
        }

        for(int i = 1; i <= n1; i++)
        {
            vec[i][0] = ((c[i] == t1[i]) && (vec[i-1][0]));
        }
        
        for(int i = 1; i <= n2; i++)
        {
            vec[0][i] = ((c[i] == t2[i]) && (vec[0][i-1]));
        }

        
        for(int i = 1; i <= n1; i++)
        {
            for(int j = 1; j <= n2; j++)
            {
                vec[i][j] = ((c[i+j] == t1[i]) && (vec[i-1][j])) || ((c[i+j] == t2[j]) && (vec[i][j-1]));
            }

        }

        if(vec[n1][n2])
        {
            ans.push_back("possible");
        }
        else
        {
            ans.push_back("not possible");
        }

        cin >> n1 >> n2;
    }
    
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}

/*
3 3
1 2 1
2 1 1
1 2 1 1 2 1
3 3
1 2 1
2 1 2
1 1 1 2 2 2
0 0 
*/