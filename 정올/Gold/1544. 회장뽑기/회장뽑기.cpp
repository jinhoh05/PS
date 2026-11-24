#include <bits/stdc++.h>

using namespace std;
int n,ans=100;;
int score[55],vt[55];

vector<int> e[55],a;
queue<pair<int,int>> que;

int bfs(){

    for(int i=1;i<=n;i++){
        que.push({i,0});
        vt[i]=i;
        while(!que.empty()){
            int u = que.front().first;
            int l = que.front().second;
            que.pop();
            score[i]=max(score[i],l);
            for(int v : e[u]){
                if(vt[v] != i){
                    vt[v]=i;
                    que.push({v,l+1});
                }
            }
        }
    }

    for(int i=1;i<=n;i++) ans=min(ans,score[i]);
    for(int i=1;i<=n;i++) if(score[i]==ans) a.push_back(i);

    return 0;
}

int main(){

    scanf("%d",&n);

    while(1){
        int v,u;
        scanf("%d%d",&u,&v);
        if(u==-1) break;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    bfs();

    printf("%d %d\n",ans,a.size());
    for(int i : a) printf("%d ",i);

    return 0;
}