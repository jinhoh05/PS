#include <bits/stdc++.h>

using namespace std;

int n, ans;
vector<int> a, b;

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> n;

	int tmp;

	for(int i=1;i<=n;i++){
		cin >> tmp;
		a.push_back(tmp);
	}

	for(int i=1;i<=n;i++){
		cin >> tmp;
		b.push_back(tmp);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());

	for(int i=0;i<n;i++) ans += a[i] * b[i];

	cout << ans;

	return 0;
}
