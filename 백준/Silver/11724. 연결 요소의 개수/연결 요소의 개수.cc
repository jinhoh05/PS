#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
vector<int> v[1005];
int vt[1005];

void dfs(int x){
    vt[x] = 1;
    for(int u : v[x]){
        if(!vt[u]) dfs(u);
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    while(m--){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(!vt[i]){
            dfs(i);
            ans++;
        }
    }

    cout << ans;

    return 0;
}
