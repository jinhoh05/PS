#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pil = pair<int, ll>;

int N, M;
int st, ed;
int vt[100010];

ll d[100010];

vector<pil> adj[100010];

struct Da{

    ll start, c, len;

    bool operator<(const Da& t)const{
        return c > t.c;
    }
};

void dijkstra(int start) {
    for(int i=1; i<=N; i++) d[i] = 1e18, vt[i] = 0;
    d[start] = 0;
	priority_queue<Da> pq;
	pq.push({start, 0, 0});

	while(!pq.empty()) {
		int cur = pq.top().start;
		ll dist = pq.top().c;
		ll len = pq.top().len;
		pq.pop();

		int i;
		for(i = vt[cur]; i < adj[cur].size(); i++) {
			int next = adj[cur][i].second;
			ll next_dist = dist + adj[cur][i].first;

			if(adj[cur][i].first <= len) break;

			d[next] = min(d[next], next_dist);
            pq.push({next, next_dist, adj[cur][i].first});
		}

		vt[cur] = i;
	}
}

int main()
{
    scanf("%d %d", &N, &M);

    for(int i=1; i<=M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    scanf("%d %d", &st, &ed);

    for(int i=1; i<=N; i++) {
        sort(adj[i].begin(), adj[i].end(), [&](pil& l, pil& r){ return l.first > r.first; });
    }

    dijkstra(st);

    if(d[ed] >= 1e18) printf("DIGESTA");
    else printf("%lld", d[ed]);

    return 0;
}
