#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;

const int INF = 987654321;

int n, m;
int path[805];

vector<pii> v[805];

vi dijkstra(int x, int End){
    vi d(End, INF);
    d[x] = 0;

    priority_queue<pii, vector<pii>> pq;
    pq.push({0, x});

    while(!pq.empty()){
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d[u] < cost) continue;

        for(pii i : v[u]){
            int dist = cost + i.second;

            if(d[i.first] > dist){
                d[i.first] = dist;
                path[i.first] = u;
                pq.push({dist, i.first});
            }
        }
    }

    return d;
}

void input(){
    cin >> n >> m;

    n++;

    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    input();

    int s, e;

    cin >> s >> e;

    vi a = dijkstra(1, n);
    vi b = dijkstra(s, n);
    vi c = dijkstra(e, n);

    int ans = min(a[s] + b[e] + c[n - 1], a[e] + c[s] + b[n - 1]);

    if(ans >= INF || ans < 0) cout << -1;
    else cout << ans;

    return 0;
}
