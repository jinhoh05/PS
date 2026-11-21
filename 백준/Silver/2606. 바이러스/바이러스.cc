#include <bits/stdc++.h>

using namespace std;

vector<int> v[105];
int vt[105];
int com, n, s, e, ans;

void dfs(int x){
    ans++;
    vt[x] = 1;

    for(int u : v[x]){
        if(!vt[u]) dfs(u);
    }

    return;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> com >> n;

    for(int i=1;i<=n;i++){
        cin >> s >> e;
        v[s].push_back(e);
        v[e].push_back(s);
    }

    dfs(1);

    cout << ans - 1;

    return 0;
}
