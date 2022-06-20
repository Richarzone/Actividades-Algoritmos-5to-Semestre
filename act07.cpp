//Ricardo Arriaga
//A01570553

#include <iostream>
#include <vector>

using namespace std;
//Complejidad: O(n*m)
int main()
{
    int n;
    cin >> n;
    vector<int> ans;

    for(int i = 0; i < n; i++)
    {
        string s1;
        string s2;

        cin >> s1;
        cin >> s2;

        int s1l = s1.length();
        int s2l = s2.length();

        int lcs[s1l][s2l];
        int max = 0;

        if(s1[0] == s2[0])
        {
            lcs[0][0] = 1;
        }
        else
        {
            lcs[0][0] = 0;
        }

        for(int i = 1; i < s1l; i++)
        {
            if(s1[i] == s2[0])
            {
                lcs[i][0] = 1;
            }
            else
            {
                lcs[i][0] = lcs[i-1][0];
            }
        }

        for(int i = 1; i < s2l; i++)
        {
            if(s2[i] == s1[0])
            {
                lcs[0][i] = 1;
            }
            else
            {
                lcs[0][i] = lcs[0][i-1];
            }
        }

        for(int i = 1; i < s1l; i++)
        {   
            for(int j = 1; j < s2l; j++)
            {
                if(s1[i] == s2[j])
                {
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                }
                else
                {
                    lcs[i][j] = lcs[i-1][j] > lcs[i][j-1] ? lcs[i-1][j] : lcs[i][j-1];
                }
            }
        }

        ans.push_back(lcs[s1l-1][s2l-1]);
    }
    
    for(int i = 0; i < n; i++)
    {
        cout << "Case " << i+1 << ": " << ans[i] << endl;
    }

    return 0;
}

/*
2
AAAAAAABBAAB
ABAABBAB
XMJYAUZ
MZJAWXU
*/