#include <bits/stdc++.h>

using namespace std;
int n,m,ans;
int G[50005], R[200005];

int get_p(int x){
    if(G[x] == x) return x;
    return G[x]=get_p(G[x]);
}

void union_p(int s, int e){
    s = get_p(s);
    e = get_p(e);

    if(s == e) return;

    if(R[s] > R[e]) swap(s, e);
    G[s] = e;

    if(R[s] == R[e]) R[e]++;
}

int find_p(int s,int e){
    s = get_p(s);
    e = get_p(e);

    if(s == e) return 1;
    else return 0;
}

int main()
{
    scanf("%d %d",&n,&m);

    int s,e,ans=n;
    for(int i=1;i<=n;++i) G[i]=i;

    for(int i=1;i<=m;i++){
        scanf("%d %d",&s,&e);
        if(!find_p(s,e)){
            ans--;
            union_p(s,e);
        }
    }

    printf("%d",ans);

    return 0;
}