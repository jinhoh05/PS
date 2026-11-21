#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int t;
int n, m;

ll DP[35][35];

void dynamic()
{
    for(int i = 1; i <= 30; i++)
    {
        DP[i][i] = 1;
        DP[i][1] = i;
    }

    for(int i = 2; i <= 30; i++)
    {
        for(int j = 2; j <= i; j++)
        {
            DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
        }
    }
}

int main()
{
    dynamic();

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d", &n, &m);
        printf("%lld\n", DP[m][n]);
    }

    return 0;
}
