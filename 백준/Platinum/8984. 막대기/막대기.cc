#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

int n, l;

ll up_DP[100005], down_DP[100005];

pii stick[100005];

vector<int> up, down;

void sorting(){
	sort(stick, stick + n);
	sort(up.begin(), up.end());
	sort(down.begin(), down.end());

	up.erase(unique(up.begin(), up.end()), up.end());
	down.erase(unique(down.begin(), down.end()), down.end());
}

ll zigzag(){
	ll ans = 0;

	for(int i=0;i<n;i++){
		int up_x = lower_bound(up.begin(), up.end(), stick[i].first) - up.begin();
		int down_y = lower_bound(down.begin(), down.end(), stick[i].second) - down.begin();
		int len = l + (abs(stick[i].first - stick[i].second));

		ll x = up_DP[up_x], y = down_DP[down_y];

		up_DP[up_x] = max(x, y + len);
		down_DP[down_y] = max(y, x + len);

		ans = max({ans, (ll)up_DP[up_x], (ll)down_DP[down_y]});
	}

	return ans;
}

void input(){
	scanf("%d %d", &n, &l);

	for(int i=0;i<n;i++){
		scanf("%d %d", &stick[i].first, &stick[i].second);

		up.push_back(stick[i].first);
		down.push_back(stick[i].second);
	}
}

int main()
{
	input();

	sorting();

    printf("%lld", zigzag());

    return 0;
}
