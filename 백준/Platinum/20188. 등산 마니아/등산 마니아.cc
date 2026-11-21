#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;

ll S[300005], D[300005], P[300005];
ll sum;

vector<int> v[300005];

int dfs(int x, int val)
{
    S[x] = 1, P[x] = val;

    for(int u : v[x])
    {
        if(u != val)
        {
            D[u] = D[x] + 1;
            S[x] += dfs(u, x);
        }
    }

    return S[x];
}

int main()
{
    scanf("%d", &N);

    for(int i = 1; i < N; i++)
    {
        int s, e;
        scanf("%d %d", &s, &e);

        v[s].push_back(e);
        v[e].push_back(s);
    }

    dfs(1, -1);

    for(int i = 1; i <= N; i++) sum += S[i] * (N - S[i]);

    for(int i = 1; i <= N; i++)
    {
        ll cost = (S[i] * (S[i] - 1) / 2);

        for(int u : v[i])
        {
            if(u != P[i])
            {
                cost -= (S[u] * (S[u] - 1) / 2);
            }
        }

        sum += cost * D[i];
    }

    printf("%lld", sum);

    return 0;
}
