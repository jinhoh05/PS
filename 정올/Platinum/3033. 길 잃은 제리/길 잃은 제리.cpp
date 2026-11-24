#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int INF = 1e9;
int n, m, x, ans = INF;
int temper[10005];
int d[10005][3][205];

struct data{
    int e, cost;
};

struct st{
    int a, b, c, d;

    bool operator<(const st &t)const{
        if(a == t.a && b == t.b && c == t.c) return d > t.d;
        if(a == t.a && b == t.b) return c > t.c;
        if(a == t.a) return b > t.b;
        return a > t.a;
    }
};

vector<data> v[10005];
priority_queue<st> q;

pii push(st t, data u){
    if(temper[u.e] == 0){
		if(t.c == 2 && t.d + u.cost < x) return make_pair(-1, -1);
		else return make_pair(0, 0);
	}

	else if(temper[u.e] == 1){
		int dist = min(x, t.d + u.cost);
		return make_pair(t.c, dist);
	}

	else{
		if(t.c == 0 && t.d + u.cost < x) return make_pair(-1, -1);
		else return make_pair(2, 0);
	}

}

void dijkstra(){
    for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<201;k++){
				d[i][j][k] = INF;
			}
		}
	}

	d[0][0][0] = 0;
	q.push({0, 0, 0, 0});

	while(!q.empty()){
        st t = q.top();
        q.pop();

        if(d[t.b][t.c / 2][t.d] < t.a) continue;

        for(data u : v[t.b]){
            pii p = push(t, u);
            if(p == make_pair(-1, -1)) continue;
			int dist = t.a + u.cost;
			int e = u.e;
			if(d[e][p.first / 2][p.second] <= dist) continue;
			d[e][p.first / 2][p.second] = dist;
			q.push({dist, e, p.first, p.second});
        }
	}
}

void output(){
    for(int i=0;i<2;i++){
		for(int j=0;j<=x;j++){
			ans = min(ans, d[n - 1][i][j]);
		}
	}

    cout << ans;
}

void input(){
    cin >> n >> m >> x;

    for(int i=0;i<n;i++){
        cin >> temper[i];
    }

    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;

        a--, b--;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    input();

    dijkstra();

    output();

    return 0;
}