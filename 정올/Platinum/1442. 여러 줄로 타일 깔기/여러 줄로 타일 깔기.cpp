#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
ll vt[1 << 12][1 << 12];
ll DP[13][1 << 12];

bool visit(int x, int y)
{
    if(x & y) return false;

    ll xy = x | y;

    for(int i = 0; i < m;)
    {
        if(xy & (1 << i)) i++;

        else
        {
            if(i == (m - 1) || (xy & (1 << (i + 1)))) return false;
            else i += 2;
        }
    }

    return true;
}

void init(){
    if(n < m) swap(n, m);

    for(int i = 0; i < (1 << m); i++)
        for(int j = 0; j < (1 << m); j++)
            if(visit(i, j)) vt[i][j] = 1;
}

ll dynamic()
{
    DP[0][0] = 1;

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < (1 << m); i++)
        {
            for(int j = 0; j < (1 << m); j++)
            {
                if(vt[i][j]) DP[k + 1][j] += DP[k][i];
            }
        }
    }

    return DP[n][0];
}

int main()
{
    scanf("%d %d", &n, &m);

    init();

    printf("%lld", dynamic());

    return 0;
}