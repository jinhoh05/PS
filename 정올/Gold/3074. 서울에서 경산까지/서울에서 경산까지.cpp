#include <bits/stdc++.h>

using namespace std;

int N, K;
int ans;
int DP[105][100005];

struct data{

    int time, cost;

};

data walk[105], bike[105];

void dynamic()
{
    DP[1][walk[1].time] = walk[1].cost;
    DP[1][bike[1].time] = bike[1].cost;

    for(int i = 2; i <= N; i++)
    {
        for(int j = 1; j <= K; j++)
        {
            if(walk[i].time < j)
            {
                DP[i][j] = max(DP[i][j], DP[i - 1][j - walk[i].time] + walk[i].cost);
            }

            if(bike[i].time < j)
            {
                DP[i][j] = max(DP[i][j], DP[i - 1][j - bike[i].time] + bike[i].cost);
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &K);

    for(int i = 1; i <= N; i++)
    {
        scanf("%d %d", &walk[i].time, &walk[i].cost);
        scanf("%d %d", &bike[i].time, &bike[i].cost);
    }

    dynamic();

    for(int i = 1; i <= K; i++)
    {
        ans = max(ans, DP[N][i]);
    }

    printf("%d", ans);

    return 0;
}