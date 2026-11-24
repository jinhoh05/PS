#include <bits/stdc++.h>

using namespace std;
int n,m,tree[400005];


const int INF=1234567899;
void update(int node, int s, int e, int idx, int t){
    if(idx < s || idx > e) return;
    if(s == e){
        tree[node]=t;
        return;
    }

    update(node*2, s, (s+e)/2, idx, t);
    update(node*2+1, (s+e)/2+1, e, idx, t);

    tree[node]=max(tree[node*2], tree[node*2+1]);
}

int query(int node, int s, int e, int fs, int fe){
    if(e < fs || fe < s) return -INF;
    if(fs <= s && e <= fe) return tree[node];
    return max(query(node*2, s, (s+e)/2, fs, fe), query(node*2+1, (s+e)/2+1, e, fs, fe));
}

int main()
{
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n*4;i++) tree[i]=-INF;

    for(int i=1;i<=m;i++){
        int a,b,c=-INF;
        scanf("%d %d",&a,&b);
        if(a != 3) scanf("%d",&c);

        if(a != 2) update(1,1,n,b,c);
        else{
            int ans=query(1,1,n,b,c);
            if(ans != -INF) printf("%d\n",ans);
        }
    }

    return 0;
}