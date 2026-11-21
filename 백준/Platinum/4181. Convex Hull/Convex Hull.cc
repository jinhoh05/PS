#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll x, y;
char c;
vector<pair<ll, ll>> pos, hull, res;

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	return (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
}

bool compAscXAscY(pair<ll, ll>& a, pair<ll, ll>& b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

bool comp(pair<ll, ll>& a, pair<ll, ll>& b) {
	ll res = ccw(pos[0].first, pos[0].second, a.first, a.second, b.first, b.second);
	if (res == 0) {
		if (a.first == b.first) return a.second > b.second;
		else {
			if (a.second == b.second) return a.first < b.first;
			else return a.second > b.second;
		}
	}
	else {
		return res > 0;
	}
}

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld %c", &x, &y, &c);
		if (c == 'Y') pos.push_back({ x, y });
	}

	sort(pos.begin(), pos.end(), compAscXAscY);
	sort(pos.begin() + 1, pos.end(), comp);

	hull.push_back(pos[0]);
	hull.push_back(pos[1]);

	for (int i = 2; i < pos.size(); i++) {
		while (hull.size() >= 2) {
			pair<ll, ll> a = hull.back();
			hull.pop_back();
			pair<ll, ll> b = hull.back();
			ll res = ccw(pos[i].first, pos[i].second, a.first, a.second, b.first, b.second);
			if (res <= 0) {
				hull.push_back(a);
				break;
			}
		}
		hull.push_back(pos[i]);
	}

	printf("%d\n", hull.size());
	for (int i = 0; i < hull.size(); i++) {
		printf("%lld %lld\n", hull[i].first, hull[i].second);
	}
    
    return 0;
}