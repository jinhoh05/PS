#include <bits/stdc++.h>

using namespace std;

int N, M, R, cnt = 1;
int vt[100005];

queue<int> q;

set<int> V[100005];

void bfs()
{
    while(!q.empty())
    {
        int t = q.front();
        q.pop();

        if(vt[t]) continue;
        vt[t] = cnt++;

        for(auto u : V[t])
        {
            if(vt[u]) continue;
            q.push(u);
        }
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

    q.push(R);

    bfs();

    for(int i = 1; i <= N; i++)
    {
        if(vt[i]) printf("%d\n", vt[i]);
        else printf("0\n");
    }

    return 0;
}
