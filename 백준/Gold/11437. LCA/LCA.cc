#include <bits/stdc++.h>

using namespace std;

int n, q;

vector<int> v[250005];

int parent[250005][17];
int depth[250005];

void dfs(int x)
{
	for(int u : v[x])
    {
		if(depth[u] == -1)
		{
			parent[u][0] = x;
			depth[u] = depth[x] + 1;
			dfs(u);
		}
	}

	return;
}

void connect()
{
	for(int i = 1; i < 17; i++)
    {
		for(int j = 1; j <= n; j++)
        {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
}

int LCA(int u, int x, int k, int l)
{
    if(depth[u] < depth[x]) swap(u, x);

	int d = depth[u] - depth[x];

	for(int i = 0; d != 0; i++)
    {
		if(d % 2 == 1) u = parent[u][i];

		d /= 2;
	}

	if(u != x)
    {
		for(int i = 16; i >= 0; i--)
		{
			if(parent[u][i] != -1 && parent[u][i] != parent[x][i])
			{
				u = parent[u][i];
				x = parent[x][i];
			}
		}

		u = parent[u][0];
	}

	return u;
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

    memset(depth, -1, sizeof(depth));
    memset(parent, -1, sizeof(parent));

    depth[1] = 0;

    dfs(1);
    connect();


    scanf("%d", &q);

    for(int i = 1; i <= q; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        printf("%d\n", LCA(x, y, 0, 0));
    }

    /*
    for(int p = 0; p < q; p++)
    {
        int a, i, j, k, l;

        scanf("%d", &a);

        if(a == 1)
        {
            scanf("%d %d %d", &i, &j, &k);

            if(LCA(i, j, k, 0)) printf("YES\n");
            else printf("NO\n");
        }

        else
        {
            scanf("%d %d %d %d", &i, &j, &k, &l);

            if(LCA(i, j, k, l)) printf("YES\n");
            else printf("NO\n");
        }
    }
    */

    return 0;
}
