#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 9;

int N, S;
int w[25];
int DP[25][1000005];

void dynamic()
{
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= S; j++)
            DP[i][j] = -INT_MAX;

    for(int i = 1; i <= N; i++) DP[i][w[i]] = 1;

    for(int i = 1; i <= N; i++)
    {
       for(int j = 0; j <= S; j++)
        {
            if(j < w[i]) DP[i][j] = DP[i - 1][j];
            else DP[i][j] = DP[i - 1][j] + DP[i][j - w[i]] + 1;

            DP[i][j] %= MOD;
        }
    }
}

int main()
{
    scanf("%d %d", &N, &S);

    for(int i = 1; i <= N; i++)
    {
        int q;

        scanf("%d %d", &w[i], &q);

        if(q == 1) S -= w[i];
    }

    sort(w + 1, w + N + 1);

    if(S < 0)
    {
        printf("0");
        return 0;
    }

    dynamic();

    printf("%d", DP[N][S] + 1);

    return 0;
}