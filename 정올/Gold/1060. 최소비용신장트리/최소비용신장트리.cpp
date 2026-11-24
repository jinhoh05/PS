#include <bits/stdc++.h>

using namespace std;
int n,an;
int G[105],network[105][105];

struct data{
    int s,e,cost;
    bool operator<(const data& t)const{
        return cost < t.cost;
    }
}adj[10005];

int get_p(int x){
    if(G[x] == x) return x;
    return G[x]=get_p(G[x]);
}

void union_p(int s,int e){
    s = get_p(s);
    e = get_p(e);
    if(s < e) G[e]=s;
    else G[s]=e;
}

int find_p(int s,int e){
    s = get_p(s);
    e = get_p(e);
    if(s == e) return 1;
    else return 0;
}

int Kruscal(){
    int i,j,s,e,ans=0;

    sort(adj+1,adj+1+an);

    for(i=1;i<=n;++i) G[i]=i;

    for(i=1;i<=an;++i){
        int s=adj[i].s,e=adj[i].e;

        if(!find_p(s,e)){
            ans+=adj[i].cost;
            union_p(s,e);
        }
    }

    return ans;
}

int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&network[i][j]);
            if(i < j){
                adj[++an].s=i,adj[an].e=j;
                adj[an].cost=network[i][j];
            }
        }
    }

    printf("%d",Kruscal());

    return 0;
}