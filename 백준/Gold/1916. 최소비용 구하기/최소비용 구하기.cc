#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int INF = 987654321;

int n, m;
int dist[1005];

vector<pii> v[100005];

priority_queue<pii> pq;

void dijkstra(int x){
	dist[x] = 0;

	pq.push({dist[x], x});

	while(!pq.empty()){
		int d = pq.top().first * -1;
		int fx = pq.top().second;
		pq.pop();

		if(dist[fx] < d) continue;

		for(pii u : v[fx]){
			int n_dist = d + u.second;

			if(n_dist < dist[u.first]) {
				dist[u.first] =n_dist;
				pq.push({n_dist * -1 , u.first});
			}
		}
	}
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for(int i=1;i<=n;i++) dist[i] = INF;

	int s, e, cost;

	for(int i=1;i<=m;i++){
		cin >> s >> e >> cost;
		v[s].push_back({e, cost});
	}

	cin >> s >> e;

	dijkstra(s);

	cout << dist[e];

	return 0;
}
