#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans;
int vt[1005];

vector<int> p[1005], c[1005], tree[1005];

int root(int x, int lev)
{
    if (p[x].empty()) return lev;
    return root(p[x].front(), lev + 1);
}   

int child(int x, int lev)
{
    if (c[x].empty())
    {
        ans = max(ans, lev);
        return 1;
    }

    int cnt = 1;
    for (int u : c[x])
    {
        cnt += child(u, lev + 1);
    }

    return cnt;
}

void longest(int x, int lev)
{
    if (vt[x]) return;
    vt[x] = 1;

    ans = max(ans, lev);

    for (int u : tree[x]) 
        longest(u, lev + 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        p[a].push_back(b);
        c[b].push_back(a);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int x;
    cin >> x;

    cout << root(x, 0) << "\n";
    cout << child(x, 0) << "\n";
    cout << ans << "\n";
    
    ans = 0;
    longest(x, 0);
    cout << ans << "\n";

    return 0;
}