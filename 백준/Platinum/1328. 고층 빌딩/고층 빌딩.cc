#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
ll DP[105][105][105];

int n, l, r;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

	cin >> n >> l >> r;

	DP[1][1][1] = 1;

	for(int i=2;i<=n;i++){
		for(int j=1;j<=l;j++){
			for(int k=1;k<=r;k++){
				DP[i][j][k] = DP[i - 1][j][k] * (i - 2) + DP[i - 1][j - 1][k] + DP[i - 1][j][k - 1];
				DP[i][j][k] %= MOD;
			}
		}
	}

	cout << DP[n][l][r];

	return 0;
}
