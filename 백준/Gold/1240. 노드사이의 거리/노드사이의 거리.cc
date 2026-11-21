#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, M;
int s, e, ans;
int vt[1005];

vector<pii> v[1005];

bool dfs(int x, int dist)
{
    if(vt[x]) return false;
    vt[x] = 1;

    if(x == e)
    {
        ans = dist;
        return true;
    }

    for(pii u : v[x])
    {
        if(dfs(u.first, dist + u.second)) return true;
    }

    return false;
}

int main()
{
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N - 1; i++)
    {
        int dist;
        scanf("%d %d %d", &s, &e, &dist);

        v[s].push_back({e, dist});
        v[e].push_back({s, dist});
    }

    for(int i = 0; i < M; i++)
    {
        scanf("%d %d", &s, &e);

        dfs(s, 0);
        memset(vt, 0, sizeof(vt));

        printf("%d\n", ans);
    }

    return 0;
}
