#include <bits/stdc++.h>

using namespace std;
int n,m;
int dist[100010],vt[100010];
vector<pair<int,int>> adj[100010];
priority_queue<pair<int,int>> pq;
///first=거리
///second=장소

void dijkstra(){
    pq.push({0,1});
    while(!pq.empty()){
        int node,d=21e8;
        pair<int,int> t;
        t=pq.top();
        pq.pop();
        t.first*=-1;
        if(vt[t.second]) continue;

        if(t.second==n) return;

        vt[t.second]=1;
        for(pair<int,int> i:adj[t.second]){
            if(vt[i.second]==0 && dist[i.second] > t.first + i.first){
                dist[i.second] = t.first + i.first;
                pq.push({-dist[i.second],i.second});
            }

        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++){
        dist[i]=21e8;
    }

    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        adj[a].push_back({c,b});
    }

    dist[1]=0;
    dijkstra();

    printf("%d",dist[n]);

    return 0;
}