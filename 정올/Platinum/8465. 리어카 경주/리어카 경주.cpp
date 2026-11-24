#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9;

int n, m, ans;
int p[10005], vt[10005], arrive[10005];
int DP[10005];

vector<int> v[10005], graph[10005];
queue<int> q;

void dfs(int node)
{
    arrive[node] = 1;

    for (int u : v[node])
    {
        if (!arrive[u]) dfs(u);
    }
}

void dag()
{
    for (int node = 1; node <= n; node++)
    {
        if (!arrive[node]) continue;
        
        for (int u : v[node])
        {
            if (arrive[u]) p[u]++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    dfs(1);

    if (!arrive[2]){
        cout << "0";
        return 0;
    }

    vt[1] = 1;
    dag();

    for (int i = 1; i <= n; i++)
    {
        if (!p[i] && arrive[i]) q.push(i);
    }

    DP[1] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int u : v[node])
        {
            if (!arrive[u]) continue;
            
            DP[u] = (DP[u] + DP[node]) % MOD;
            if (!(--p[u])) q.push(u);
        }
    }

    if (p[2] > 0) 
    {
        cout << "inf";
        return 0;
    }

    cout << DP[2];

    return 0;
}