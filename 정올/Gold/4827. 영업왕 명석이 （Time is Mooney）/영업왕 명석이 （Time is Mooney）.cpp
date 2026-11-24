#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

int a, b;

ll n, m, c;
ll cost[1005];
ll DP[2][1005];

vector<pii> v;

int main()
{
    scanf("%lld %lld %lld", &n, &m, &c);

    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &cost[i]);
    }

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        v.push_back(make_pair(a, b));
    }

    ll ans = 0;

    memset(DP, -1, sizeof(DP));

    DP[0][1] = 0;

    for(int i = 1; i < 1005; i++)
    {
        int val = i % 2;

        for(auto& u : v)
        {
            a = u.first;
            b = u.second;

            if(DP[1 - val][a] >= 0)
            {
                DP[val][b] = max(DP[val][b], DP[1 - val][a] + cost[b]);
            }
        }

        ans = max(ans, DP[val][1] - c * i * i);
    }

    printf("%lld", ans);

    return 0;
}
