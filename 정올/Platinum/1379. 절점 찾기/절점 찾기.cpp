#include <bits/stdc++.h>

using namespace std;

const int MAX = 300005;

int n, m, cnt, tree_cnt;
int dfs_tree[MAX], dfs_back[MAX];

vector<int> v[MAX];

int dfs(int x){
    int MIN, num;

    dfs_tree[x] = MIN = ++cnt;

    for(int u : v[x]){
        if(x == 1 && !dfs_tree[u]) tree_cnt++;

        if(!dfs_tree[u]){
            num = dfs(u);
            MIN = min(MIN, num);

            if(num >= dfs_tree[x] && x != 1) dfs_back[x] = 1;
        }

        else MIN = min(MIN, dfs_tree[u]);
    }

    return MIN;
}

void network(){
    dfs(1);

    if(tree_cnt > 1) dfs_back[1] = 1;

    int not_exist = 0;

    for(int i=1;i<=n;i++){
        if(dfs_back[i]) printf("%d ", i);
        else not_exist++;
    }

    if(not_exist == n) printf("-1");
}

int main()
{
    scanf("%d %d", &n, &m);

    for(int i=1;i<=m;i++){
        int U, V;
        scanf("%d %d", &U, &V);

        v[U].push_back(V);
        v[V].push_back(U);
    }

    network();

    return 0;
}