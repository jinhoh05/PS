#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;


signed main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll t; cin >> t;
	while (t--)
	{
		ld n, m, k, d; cin >> n >> m >> k >> d;
		ld t = n * m * (k * (m - 1) + m * (n - 1));
		t = (2 * d) / t;
		ll b = t;
		ll ans = (n * m * (m - 1) / 2 * b * k + n * (n - 1) / 2 * m * m * b);
		cout << (ans <= 0 ? -1 : ans) << '\n';
	}
}