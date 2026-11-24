#include <bits/stdc++.h>

using namespace std;
vector<int> graph[100010];

bool vt[100010];

void dfs(int u){
    printf("%d ",u);
    vt[u]=1;
    for(int v:graph[u]) if(!vt[v]) dfs(v);
}

int main()
{
    int n,m;

    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int s,e;
        scanf("%d %d",&s,&e);
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    for(int i=1;i<=n;i++){
        sort(graph[i].begin(),graph[i].end());
    }

    dfs(1);

    return 0;
}