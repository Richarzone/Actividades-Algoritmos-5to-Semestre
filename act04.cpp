#include <iostream>
#include <vector>

using namespace std;

//Ricardo Arriaga 
//A01570553

// Complejidad: O(n * m)
int main()
{
    int x;
    int y;
    int n;

    cin >> x;
    cin >> y;

    int matrixCost[x][y];
    int matrixResults[x][y];

    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            cin >> n;
            matrixCost[i][j] = n;
        }
    }

    matrixResults[0][0] = matrixCost[0][0];

    for(int i = 1; i < x; i++)
    {
        matrixResults[i][0] = matrixResults[i-1][0] + matrixCost[i][0];
    }

    for(int i = 1; i < y; i++)
    {
        matrixResults[0][i] = matrixResults[0][i-1] + matrixCost[0][i];
    }

    for(int i = 1; i < x; i++)
    {
        for(int j = 1; j < y; j++)
        {
            matrixResults[i][j] = min(matrixResults[i-1][j], matrixResults[i][j-1]) + matrixCost[i][j];
        }
    }

    cout << matrixResults[x-1][y-1];
}