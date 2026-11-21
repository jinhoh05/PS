#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll arr[110], Time[110], prefix[110];
ll A[110], B[110];
vector<ll> v;

ll solve(ll x);

int main()
{
	ll d, n;
	cin >> d >> n;
	for (ll i = 1; i <= n + 1; i++) {
		cin >> arr[i];
		prefix[i] = prefix[i - 1] + arr[i];
		A[i] = (ll)10e9;
	}
	for (ll i = 1; i <= n; i++) {
		cin >> Time[i];
	}
	for (ll i = 1; i <= n + 1; i++)
		if (prefix[i] <= d)
			A[i] = Time[i];
	for (ll i = 1; i <= n + 1; i++) {
		for (ll j = 1; j < i; j++)
		{
			if (prefix[i] - prefix[j] <= d && A[i] > A[j] + Time[i]) {
				B[i] = j;
				A[i] = A[j] + Time[i];
			}
		}
	}
	ll r = solve(n + 1);
	cout << A[n + 1] << "\n" << v.size() << "\n";
	for (ll u : v)
		cout << u << " ";
	return 0;
}
ll solve(ll x)
{
	if (B[x] == 0)return x;
	ll ret = solve(B[x]);
	v.push_back(ret);
	return x;
}