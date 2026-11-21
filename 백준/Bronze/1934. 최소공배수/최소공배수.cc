#include <bits/stdc++.h>

using namespace std;

int t;

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> t;

	while(t--){
        int a, b;
		cin >> a >> b;

		int ans = gcd(a, b);

		ans = ans * (a / ans) * (b / ans);

		cout << ans << "\n";
	}

	return 0;
}
