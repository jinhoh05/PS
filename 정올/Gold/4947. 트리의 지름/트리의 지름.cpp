#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans, leaf;
int vt[100005];

vector<int> v[100005];

void dfs(int x, int lev, int k)
{
    if (vt[x] == k) return;
    vt[x] = k;

    if (ans < lev)
    {
        ans = lev;
        leaf = x;
    }

    for (int u : v[x])
    {
        dfs(u, lev + 1, k);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1, 0, 1);
    dfs(leaf, 0, 2);

    cout << ans;

    return 0;
}