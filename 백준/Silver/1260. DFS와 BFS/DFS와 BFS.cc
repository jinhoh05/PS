#include <bits/stdc++.h>

using namespace std;
int n, m, k;
int vt[1005];
vector<int> v[1005];
queue<int> q;

void dfs(int x){
    printf("%d ",x);
    vt[x] = 1;

    for(int u : v[x]){
        if(!vt[u]) dfs(u);
    }
}

void push(int x){
    printf("%d ",x);

    for(int u : v[x]){
        if(!vt[u]){
            q.push(u);
            vt[u] = 1;
        }
    }
}

void bfs(int x){
    vt[x] = 1;
    q.push(x);

    while(!q.empty()){
        x = q.front();
        q.pop();

        push(x);
    }
}

void input(){
    scanf("%d %d %d",&n, &m, &k);

    for(int i=1;i<=m;i++){
        int a, b;
        scanf("%d %d",&a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=1;i<=n;i++) sort(v[i].begin(), v[i].end());

}

int main()
{
    input();

    dfs(k);
    memset(vt, 0, sizeof(vt));
    printf("\n");

    bfs(k);

    return 0;
}
