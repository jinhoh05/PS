#include <bits/stdc++.h>

using namespace std;
int n,m;
pair<int, int> tree[400005];
const int INF=1234567899;

void update(int node, int s, int e, int idx, int t){
    if(idx < s || idx > e) return;
    if(s == e){
        tree[node]={t,idx};
        return;
    }

    update(node*2, s, (s+e)/2, idx, t);
    update(node*2+1, (s+e)/2+1, e, idx, t);

    tree[node]=min(tree[node*2],tree[node*2+1]);
}

pair<int,int> query(int node, int s, int e, int fs, int fe){
    if(e < fs || fe < s) return make_pair(INF,0);
    if(fs <= s && e <= fe) return tree[node];
    return min(query(node*2, s, (s+e)/2, fs, fe), query(node*2+1, (s+e)/2+1, e, fs, fe));
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n*4;i++) tree[i].first=INF;

    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);

        if(a == 1) update(1,1,n,b,c);
        else{
            pair<int,int> ans=query(1,1,n,b,c);
            if(ans.first != INF)
            {
                if(a==2) printf("%d\n",ans.second);
                else update(1,1,n,ans.second,INF);

            }
        }
    }

    return 0;
}