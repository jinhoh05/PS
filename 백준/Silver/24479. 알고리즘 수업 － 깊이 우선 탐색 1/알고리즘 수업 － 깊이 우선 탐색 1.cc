#include <bits/stdc++.h>

using namespace std;

int N, M, R, cnt = 1;
int vt[100005];

set<int> V[100005];

void dfs(int x)
{
    if(vt[x]) return;
    vt[x] = cnt++;

    for(auto u : V[x])
    {
        dfs(u);
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &R);

    for(int i = 0; i < M; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        V[u].insert(v);
        V[v].insert(u);
    }

    dfs(R);

    for(int i = 1; i <= N; i++)
    {
        if(vt[i]) printf("%d\n", vt[i]);
        else printf("0\n");
    }

    return 0;
}
