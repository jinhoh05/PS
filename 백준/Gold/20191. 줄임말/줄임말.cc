#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is[30];

vector<int> alpha[30];

string S, T;

int check()
{
    int lev = 1, x = 0, y = -1;

    while(x < S.size())
    {
        int num = S[x] - 'a';

        int p = upper_bound(alpha[num].begin(), alpha[num].end(), y) - alpha[num].begin();

        if(p == alpha[num].size())
        {
            lev++;
            y = -1;
        }

        else
        {
            x++;
            y = alpha[num][p];
        }
    }

    return lev;
}

bool wrong()
{
    for(char i : T) is[i - 'a'] = true;

    for(char i : S)
    {
        if(!is[i - 'a'])
        {
            cout << -1;
            return false;
        }
    }

    return true;
}

void input()
{
    cin >> S >> T;

    for(int i = 0; i < T.size(); i++)
    {
        alpha[T[i] - 'a'].push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();

    if(!wrong()) return 0;

    else cout << check();

    return 0;
}
