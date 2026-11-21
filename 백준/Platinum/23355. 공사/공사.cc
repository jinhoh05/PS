#include <bits/stdc++.h>

using namespace std;

int n, q;

vector<int> v[250005];

int parent[25][250005];
int depth[250005];

int LCA(int a, int b)
{
    if(depth[a] > depth[b]) swap(a, b);

    for(int i=20;i>=0;i--){
        if((1 << i) <= depth[b] - depth[a]) b = parent[i][b];
    }

    if(a == b) return a;

    for(int i=20;i>=0;i--){
        if(parent[i][a] != parent[i][b]){
            a = parent[i][a];
            b = parent[i][b];
        }
    }
    return parent[0][a];
}

void dfs(int p, int f)
{
    for(int u : v[p]){
        if(f == u) continue;

        depth[u] = depth[p] + 1;
        parent[0][u] = p;

        for(int j=1;j<21;j++){
            int q = parent[j - 1][u];
            parent[j][u] = parent[j - 1][q];
        }

        dfs(u, p);
    }
}

int find(int i, int j, int k)
{
    int lca1, lca2, lca3;

    lca1 = LCA(i, j), lca2 = LCA(j, k), lca3 = LCA(i, k);

    if (lca2 == k && lca3 == lca1) return 1;

    swap(lca2, lca3);

    if (lca2 == k && lca3 == lca1) return 1;

    return 0;
}

int main()
{
    scanf("%d", &n);

    for(int i = 0; i < n - 1; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1, 0);

    scanf("%d", &q);

    for(int p = 0; p < q; p++)
    {
        int a, i, j, k, l;

        scanf("%d %d %d", &a, &i, &j);

        if(a == 1)
        {
            scanf("%d", &k);

            if((i == k || j == k) || find(i, j, k)) printf("NO");
            else printf("YES");
        }

        else
        {
            scanf("%d %d", &k, &l);

            if(find(i, j, k) && find(i, j, l)) printf("NO");
            else printf("YES");
        }

        printf("\n");
    }

    return 0;
}
