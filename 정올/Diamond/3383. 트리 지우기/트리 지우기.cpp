#include <bits/stdc++.h>

using namespace std;

int n, m;
int p[100005], con[100005];
int canRoot[100005];

vector<int> v[100005];
vector<int> in[100005], out[100005];
vector<int> node;

bool can[100005];

void dfs(int x, int P){
    if(out[x].size() > 0) return;

    canRoot[x]=1;
    for(int u=0; u<v[x].size(); u++){
        if(v[x][u] != P) dfs(v[x][u], x);
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    int a, b;
    for(int i=1; i<n; i++){
        scanf("%d %d", &a, &b);
        a--, b--;

        v[a].push_back(b);
        v[b].push_back(a);

        p[a]++, p[b]++;
    }

    for(int i=1; i<=m; i++){
        scanf("%d %d", &a, &b);
        a--, b--;

        in[b].push_back(a);
        out[a].push_back(b);

        con[b]++;
    }

    for(int i=0; i<n; i++){
        if(p[i] <= 1 && con[i] == 0){
            node.push_back(i);
            can[i] = 1;
        }
    }

    for(int i=0; i<n-1; i++){
        if(i == node.size()){
            for(int j=0; j<n; j++) printf("0\n");
            return 0;
        }

        int cur = node[i];
        for(int j=0; j<v[cur].size(); j++){
            int u = v[cur][j];
            p[u]--;

            if(p[u] <= 1 && con[u] == 0 && !can[u]){
                node.push_back(u);
                can[u] = 1;
            }
        }

        for(int j=0; j<out[cur].size(); j++){
            int u = out[cur][j];
            con[u]--;

            if(p[u] <= 1 && con[u] == 0 && !can[u]){
                node.push_back(u);
                can[u] = 1;
            }
        }
    }

    int root = node[n-1];
    dfs(root, -1);

    for(int i=0; i<n; i++){
        printf("%d\n", canRoot[i]);
    }


    return 0;
}
