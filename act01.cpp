// Ricardo Andres Arriaga Quezada
// A01570553

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n;
    int k = 0;
    int posS1;
    int posS2;

    char s1;
    char s2;
    char temp;

    string name;
    vector<char> alphabetV {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    map<char, char> alphabetMap 
    {
        {'a', NULL}, 
        {'b', NULL},
        {'c', NULL},
        {'d', NULL},
        {'e', NULL},
        {'f', NULL},
        {'g', NULL},
        {'h', NULL},
        {'i', NULL},
        {'j', NULL},
        {'k', NULL},
        {'l', NULL},
        {'m', NULL},
        {'n', NULL},
        {'o', NULL},
        {'p', NULL},
        {'q', NULL},
        {'r', NULL},
        {'s', NULL},
        {'t', NULL},
        {'u', NULL},
        {'v', NULL},
        {'w', NULL},
        {'x', NULL},
        {'y', NULL},
        {'z', NULL}
    };

    cin >> n;
    cin >> name;

    for(int i = 0; i < n; i++)
    {
        cin >> s1 >> s2;

        for(int j = 0; j < alphabetV.size(); j++)
        {
            if(alphabetV[j] == s1)
            {
                posS1 = j;
            }
            
            if (alphabetV[j] == s2)
            {
                posS2 = j;
            }
        }

        temp = alphabetV[posS1];
        alphabetV[posS1] = alphabetV[posS2];
        alphabetV[posS2] = temp;
    }

    for(auto &i : alphabetMap)
    {
        i.second = alphabetV[k];
        k++;
    }

    // Complejidad: O(n)
    for(int i = 0; i < name.size(); i++)
    {
        cout << alphabetMap[name[i]];
    }

    return 0;
}