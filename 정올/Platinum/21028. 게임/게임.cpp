#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll INF = LLONG_MAX;

struct Data{
    int cur;
    ll k;
};

int n, m, q, ans;
int a[200005], vt[200005];

ll win[200005], pass[200005];
// win  : 현재 방에서 승리할 수 있을때 얻는 최대 k
// pass : 확정된 방으로 연결된 통로 수

vector<Data> graph[200005];

priority_queue<pair<ll, int>> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i]) pq.push({INF, i});
    }

    for (int i = 0; i < m; ++i) 
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    while (!pq.empty())
    {
        auto [k, cur] = pq.top();
        pq.pop();
        
        if (win[cur]) continue;
        win[cur] = k;

        for (const auto &[next, c] : graph[cur])
        {
            if (win[next]) continue;

            pass[next] += c;

            ll pos = min(pass[next], k);
            pq.push({pos, next});
        }
    }


    while (q--) 
    {
        int s;
        ll k;
        cin >> s >> k;

        if (k <= win[s]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}