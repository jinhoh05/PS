#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int V, ans, node;
int vt[100005];
vector<pair<int, int>> v[100005];

void dfs(int x, int cost){
    if(vt[x]) return;
    vt[x] = 1;

    if(ans < cost){
        ans = cost;
        node = x;
    }

    for(pii u : v[x]) dfs(u.first, u.second + cost);
}

void input(){
    cin >> V;

    while(V--){
        int x;
        cin >> x;

        while(1){
             int x2, cost;
             cin >> x2;

             if(x2 == -1) break;

             cin >> cost;
             v[x].push_back({x2, cost});
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    input();

    dfs(1, 0);

    memset(vt, 0, sizeof(vt));
    ans = 0;

    dfs(node, 0);

    cout << ans;

    return 0;
}
