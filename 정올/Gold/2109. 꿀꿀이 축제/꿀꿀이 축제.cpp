#include <bits/stdc++.h>

using namespace std;
int n,m,x;
int adj[1005][1005],dist[1005],vt[1005];
int ans[1005];

int dijkstra(){
    for(int i=1;i<=n;i++){
        int node,d=21e8;
        for(int j=1;j<=n;j++){
            if(vt[j]==0 && d>dist[j]){
                node=j,d=dist[j];
            }
        }
        vt[node]=1;
        for(int j=1;j<=n;j++){
            if(dist[j] > d + adj[node][j]){
                dist[j] = d + adj[node][j];
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d %d %d",&n,&m,&x);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            adj[i][j]=1e9;
        }
        dist[i]=1e9;
    }

    for(int i=1;i<=m;i++){
        int st,fin,d;
        scanf("%d %d %d",&st,&fin,&d);
        adj[st][fin]=d;
    }

    dist[x]=0;
    dijkstra();

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            swap(adj[i][j],adj[j][i]);
        }
        ans[i]=dist[i];
        dist[i]=1e9;
    }

    memset(vt,0,sizeof(vt));
    dist[x]=0;
    dijkstra();

    int answer=0;
    for(int i=1;i<=n;i++){
        answer=max(answer,ans[i]+dist[i]);
    }

    printf("%d",answer);
    return 0;
}