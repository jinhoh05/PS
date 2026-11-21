#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

int n, m;
int city[3005];
int vt[3005][3005];

vector<pii> v[3005];

struct st{
    ll node, cost, dist;
    bool operator<(const st &t)const{
        return dist > t.dist;
    }
};

ll dijkstra(){
    priority_queue<st> pq;
    pq.push({1, city[1], 0});

    while(!pq.empty()){
        st t = pq.top();
        pq.pop();

        ll x = t.node, c = t.cost, d = t.dist;

        if(vt[x][c]) continue;
        if(x == n) return d;

        vt[x][c] = 1;

        for(pii u : v[x]){
            pq.push({u.first, min(c, (ll)city[u.first]), c * u.second + d});
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for(int i=1;i<=n;i++) cin >> city[i];

    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    cout << dijkstra();

    return 0;
}
