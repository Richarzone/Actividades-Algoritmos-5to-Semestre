// Ricardo Andres Arriaga Quezada
// A01570553

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    string number;
    vector<char> ones;
    vector<char> zeros;
    int oneSize;
    int zeroSize;

    cin >> n;
    cin >> number;

    // Complejidad: O(n)
    for(int i = 0; i < n; i++)
    {
        if(number[i] == '1')
        {
            ones.push_back(number[i]);
        }
        else
        {
            zeros.push_back(number[i]);
        }
    }

    zeroSize = zeros.size();
    oneSize = ones.size();

    if(oneSize > zeroSize)
    {
        cout << oneSize - zeroSize;
    }
    else
    {
        cout << zeroSize - oneSize;
    }
}