#include <bits/stdc++.h>

using namespace std;

int n, m, x, y;
int inc[3005];
int DP[3005][3005];

void init()
{
    inc[1] = x, inc[2] = y;

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            DP[i][j] = 1e9;
        }
    }

    DP[1][2] = 0;
}

void bitonic()
{
    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(DP[i][j] == 1e9) continue;

            int nxt = max(i, j) + 1;
            int d1 = abs(inc[nxt] - inc[i]);
            int d2 = abs(inc[nxt] - inc[j]);

            DP[nxt][j] = min(DP[nxt][j], DP[i][j] + d1);
            DP[i][nxt] = min(DP[i][nxt], DP[i][j] + d2);
        }
    }
}

void output()
{
    int ans = 1e9;

    for(int i = 1; i <= m; i++)
    {
        ans = min({ans, DP[i][m], DP[m][i]});
    }

    printf("%d", ans);
}

void input()
{
    scanf("%d %d %d %d", &n, &x, &y, &m);

    m += 2;

    for(int i = 3; i <= m; i++)
    {
        scanf("%d", &inc[i]);
    }
}

int main()
{
    input();

    init();

    bitonic();

    output();

    return 0;
}