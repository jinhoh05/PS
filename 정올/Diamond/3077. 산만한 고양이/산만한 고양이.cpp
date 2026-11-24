#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 300005;

ll ans;
int n, m;
int dfs_tree[MAX], dfs_back[MAX];
int f_in[MAX], l_in[MAX];

vector<vector<int>> graph, v;

void dfs(int x, int p){
	for(int u : v[x]){
		if(u == p) continue;

		if(!dfs_tree[u]){
			graph[x].push_back(u);

			dfs_tree[u] = dfs_tree[x] + 1;

			int val = f_in[x];
			dfs(u, x);

			dfs_back[u] = f_in[x] - val;
			f_in[x] += f_in[u];
			l_in[x] += l_in[u];
		}

		else if(dfs_tree[u] < dfs_tree[x]){
			f_in[u]++;
			l_in[x]++;
		}
	}
}

int main()
{
    scanf("%d %d", &n, &m);

    v.resize(n + 1);
	graph.resize(n + 1);

	for(int i=1;i<=m;i++){
		int s, e;
		scanf("%d %d", &s, &e);

		v[s].push_back(e);
		v[e].push_back(s);
	}

	dfs_tree[1] = 1;
    dfs(1, 0);

	for(int i=1;i<=n;i++){
		bool flag = false;

		for(int x : graph[i]){
			if(l_in[x] - dfs_back[x] > 1 || f_in[x]){
                flag = true;
                break;
			}
		}

		if(flag || m - n + 1 - l_in[i] != 0) continue;
		ans += i;
	}

	printf("%lld", ans);
}