#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int MOD = 1e9 + 7;

int T, a, b;

ll DP[450][100000];

void dynamic()
{
    DP[1][0] = DP[1][1] = 1LL;

    for(int i = 2; i <= 446; i++)
    {
        for(int j = 0; j <= (i * (i + 1)) / 2; j++)
        {
            DP[i][j] = DP[i - 1][j];

            if(i <= j) DP[i][j] += DP[i - 1][j - i];

            DP[i][j] %= MOD;
        }
    }

    for(int i = 1; i <= 446; i++)
    {
        for(int j = 1; j <= (i * (i + 1)) / 2; j++)
        {
            DP[i][j] += DP[i][j - 1];
            DP[i][j] %= MOD;
        }
    }
}

ll calc()
{
    ll ans = 0LL;

    for(int i = 1; i <= 446; i++)
    {
        int sum = (i * (i + 1)) / 2;

        if(a + b < sum) break;

        ans += DP[i][min(a, sum)];

        if(sum - b - 1 >= 0) ans -= DP[i][sum - b - 1];

        ans = (ans + MOD) % MOD;
    }

    return ans;
}

int main()
{
    dynamic();

    scanf("%d", &T);

    while(T--)
    {
        scanf("%d %d", &a, &b);
        printf("%lld\n", calc());
    }

    return 0;
}
