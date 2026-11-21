#include <bits/stdc++.h>

using namespace std;

vector<int> v[10005], r_v[10005], ans[10005];
int vt[10005];

stack<int> stk;

void dfs(int x){
    vt[x] = 1;

    for(int u : v[x]){
        if(!vt[u]) dfs(u);
    }

    stk.push(x);
}

void r_dfs(int x, int cnt){
    vt[x] = 1;

    ans[cnt].push_back(x);

    for(int u : r_v[x]){
        if(!vt[u]) r_dfs(u, cnt);
    }
}

void output(int cnt){
    cout << cnt << "\n";

    vector<pair<int, int>> vec;
    for(int i=0;i<cnt;i++){
        sort(ans[i].begin(), ans[i].end());
        vec.push_back({ans[i][0], i});
    }

    sort(vec.begin(), vec.end());
    for(auto u : vec){
        for(auto x : ans[u.second]) cout << x << " ";
        cout << -1 << "\n";
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        r_v[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(!vt[i]) dfs(i);
    }

    memset(vt, 0, sizeof(vt));

    int cnt = 0;
    while(!stk.empty()){
        int t = stk.top();
        stk.pop();

        if(vt[t]) continue;

        r_dfs(t, cnt);
        cnt++;
    }

    output(cnt);

    return 0;
}
