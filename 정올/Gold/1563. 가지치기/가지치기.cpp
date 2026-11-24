#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, R;

int DP[1005], vt[1005];

vector<pii> tree[1005];

int dfs(int node, int cost)
{
    if(vt[node]) return 0;
    vt[node] = 1;;

    int val = 0;

    for(pii u : tree[node])
    {
        val += dfs(u.first, u.second);
    }

    if(val == 0 || cost < val) return cost;

    return val;
}

int main()
{
    while(1)
    {
        scanf("%d %d", &N, &R);
        
        if(N == 0 && R == 0) break;

        for(int i = 1; i < N; i++)
        {
            int Ui, Vi, Wi;
            scanf("%d %d %d", &Ui, &Vi, &Wi);

            tree[Ui].push_back({Vi, Wi});
            tree[Vi].push_back({Ui, Wi});
        }

        if(N == 1) printf("0\n");

        else printf("%d\n", dfs(R, 1e9));
        
        memset(tree, 0, sizeof(tree));
        memset(vt, 0, sizeof(vt));
    }

    return 0;
}