#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int cost[550];
int DP[550][60005];

int main()
{
    scanf("%d %d %d", &N, &M, &K);

    for(int i = 1; i <= N; i++)
        scanf("%d", &cost[i]);

    for(int i = 0; i <= N; i++)
        for(int j = 0; j <= 60000; j++)
            DP[i][j] = -1e9;

    DP[0][K] = 0;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j <= 60000; j++)
        {
            if(DP[i - 1][j] == -1e9) continue;

            if(j >= cost[i])
            {
                DP[i][j - cost[i]] = max(DP[i][j - cost[i]], DP[i - 1][j] + cost[i]);
            }

            int c = min(60000, j + M);
            DP[i][c] = max(DP[i][c], DP[i - 1][j]);
        }
    }

    int ans = 0;
    for(int j = 0; j <= 60000; j++)
        ans = max(ans, DP[N][j]);

    printf("%d", ans);

    return 0;
}