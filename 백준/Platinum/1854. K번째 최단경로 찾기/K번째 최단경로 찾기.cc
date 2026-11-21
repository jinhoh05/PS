#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int n, m, k;

vector<pii> v[1005];

priority_queue<int> ans[1005];

void dijkstra(){
    priority_queue<pii, vector<pii>> pq;

    pq.push({0, 1});

    ans[1].push(0);

    while(!pq.empty()){
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        for(pii u : v[now]){
            int n_cost = cost + u.second;

            if(ans[u.first].size() < k){
                ans[u.first].push(n_cost);
                pq.push({-n_cost, u.first});
            }

            else if(ans[u.first].top() > n_cost){
                ans[u.first].pop();
                ans[u.first].push(n_cost);
                pq.push({-n_cost, u.first});
            }
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;

    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    dijkstra();

    for(int i=1;i<=n;i++){
        if(ans[i].size() != k) cout << "-1\n";
        else cout << ans[i].top() << "\n";
    }

    return 0;
}
