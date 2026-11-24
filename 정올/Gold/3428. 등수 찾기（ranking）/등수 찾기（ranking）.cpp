#include <bits/stdc++.h>

using namespace std;
int n,m,p;
vector<int> up[100010],down[100010];
int x,y;
bool vt[100010];
int big,small;

void dfs_up(int u){
    vt[u]=1;
    big++;
    for(int v:up[u]) if(!vt[v]) dfs_up(v);
}

void dfs_down(int u){
    vt[u]=1;
    small++;
    for(int v:down[u]) if(!vt[v]) dfs_down(v);
}

int main()
{

    scanf("%d %d %d",&n,&m,&p);

    for(int i=1;i<=m;i++){
        scanf("%d %d",&x,&y);
        up[y].push_back(x);
        down[x].push_back(y);
    }

    dfs_up(p);
    memset(vt,0,sizeof(vt));
    dfs_down(p);

    printf("%d %d",big,n-small+1);

    return 0;
}