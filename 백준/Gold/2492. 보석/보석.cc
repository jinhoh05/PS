#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;
using pii = pair<int, int>;

int n, m, t, k;
vector<pii> v;

int f(int x, int y){
	int ret = 0;
	for(auto i : v){
		if(x <= i.x && i.x <= x + k && y <= i.y && i.y <= y+k) ret++;
	}
	return ret;
}

int main(){
	cin >> n >> m >> t >> k; v.resize(t);
	for(auto &i : v) cin >> i.x >> i.y;

	int mx = 0;
	int x, y;
	for(int i=0; i<t; i++){
		for(int j=0; j<t; j++){
			int xx, yy;
			if(v[i].x+k > n) xx = n - k;
			else xx = v[i].x;
			if(v[j].y+k > m) yy = m - k;
			else yy = v[j].y;
			int now = f(xx, yy);
			if(mx < now){
				mx = now;
				x = xx, y = yy+k;
			}
		}
	}

	cout << x << " " << y << "\n";
	cout << mx;
    
    return 0;
}