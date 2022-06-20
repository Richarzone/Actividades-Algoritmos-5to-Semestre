#include <iostream>
#include <vector>

//Ricardo Arriaga 
//A01570553

using namespace std;

//Complejidad: O(n^2)
void triomino(int &n, vector<vector<int>> &mat, int rini, int rfin, int cini, int cfin, int x, int y)
{
    n++;

    int rmit = (rini + rfin) / 2;
    int cmit = (cini + cfin) / 2;

    if(rfin == rini + 1 && cfin == cini + 1)
    {   
        if(x <= rmit)
        {
            if(y <= cmit)
            {
                mat[rmit][cmit+1] = n;
                mat[rmit+1][cmit] = n;
                mat[rmit+1][cmit+1] = n;
            }
            else
            {
                mat[rmit][cmit] = n;
                mat[rmit+1][cmit] = n;
                mat[rmit+1][cmit+1] = n;
            }
        }
        else
        {
            if(y <= cmit)
            {
                mat[rmit][cmit] = n;
                mat[rmit][cmit+1] = n;
                mat[rmit+1][cmit+1] = n;
            }
            else
            {
                mat[rmit][cmit] = n;
                mat[rmit][cmit+1] = n;
                mat[rmit+1][cmit] = n;
            }
        }
        return;
    }

    if(x <= rmit)
    {
        if(y <= cmit)
        {
            mat[rmit][cmit+1] = n;
            mat[rmit+1][cmit] = n;
            mat[rmit+1][cmit+1] = n;

            triomino(n, mat, rini, rmit, cini, cmit, x, y);
            triomino(n, mat, rini, rmit, cmit+1, cfin, rmit, cmit+1);
            triomino(n, mat, rmit+1, rfin, cini, cmit, rmit+1, cmit);
            triomino(n, mat, rmit+1, rfin, cmit+1, cfin, rmit+1, cmit+1);
        }
        else
        {
            mat[rmit][cmit] = n;
            mat[rmit+1][cmit] = n;
            mat[rmit+1][cmit+1] = n;

            triomino(n, mat, rini, rmit, cini, cmit, rmit, cmit);
            triomino(n, mat, rini, rmit, cmit+1, cfin, x, y);
            triomino(n, mat, rmit+1, rfin, cini, cmit, rmit+1, cmit);
            triomino(n, mat, rmit+1, rfin, cmit+1, cfin, rmit+1, cmit+1);
        }
    }
    else
    {
        if(y <= cmit)
        {
            mat[rmit][cmit] = n;
            mat[rmit][cmit+1] = n;
            mat[rmit+1][cmit+1] = n;

            triomino(n, mat, rini, rmit, cini, cmit, rmit, cmit);
            triomino(n, mat, rini, rmit, cmit+1, cfin, rmit, cmit+1);
            triomino(n, mat, rmit+1, rfin, cini, cmit, x, y);
            triomino(n, mat, rmit+1, rfin, cmit+1, cfin, rmit+1, cmit+1);
        }
        else
        {
            mat[rmit][cmit] = n;
            mat[rmit][cmit+1] = n;
            mat[rmit+1][cmit] = n;

            triomino(n, mat, rini, rmit, cini, cmit, rmit, cmit);
            triomino(n, mat, rini, rmit, cmit+1, cfin, rmit, cmit+1);
            triomino(n, mat, rmit+1, rfin, cini, cmit, rmit+1, cmit);
            triomino(n, mat, rmit+1, rfin, cmit+1, cfin, x, y);
        }
    }
}

void printMatrix(int n, vector<vector<int>> mat)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    int i = 0;
    int x;
    int y;

    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cin >> x >> y;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            matrix[i][j] = 1;
        }
    }

    matrix[x][y] = 0;

    triomino(i, matrix, 0, n-1, 0, n-1, x, y);
    cout << endl;
    printMatrix(n, matrix);
}