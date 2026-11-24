#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, K, Q;

ll dist;
ll candy[2005][2005];

bool flag = false;

int main()
{
    scanf("%d %d %d", &N, &K, &Q);

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= K; j++)
            scanf("%lld", &candy[i][j]);

    int add = N;

    for(int i = 1; i <= N; i++) if(candy[1][i] != 1) add = 0;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= K; j++)
            dist += candy[i][j] >= i ? candy[i][j] - i : N - i + candy[i][j];

    printf("%d", (add + dist + N - 1) / N <= Q ? 1 : 0);

    return 0;
}