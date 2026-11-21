#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;

ll seq[100005], sum[100005];
ll DP[5][100005];

void init()
{
    sum[1] = seq[1];

    for(int i = 1; i <= N; i++)
    {
        sum[i] = sum[i - 1] + seq[i];
    }
}

ll dynamic()
{
    int cost = sum[N] / 4;

    if(cost * 4 != sum[N]) return 0;

    DP[0][0] = 1;

    for(int k = 1; k <= 4; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            DP[k - 1][i] += DP[k - 1][i - 1];
        }

        for(int i = 1; i <= N; i++)
        {
            if(sum[i] != sum[N] / 4 * k) continue;
            DP[k][i] = DP[k - 1][i - 1];
        }
    }

    return DP[4][N];
}

int main()
{
    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
    {
        scanf("%lld", &seq[i]);
    }

    init();

    printf("%lld", dynamic());

    return 0;
}
