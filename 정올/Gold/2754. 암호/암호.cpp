#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 9;

int n, k;

ll ans = 1;
ll DP[1000005];

ll dynamic(){
	if(n == 5){
		for(int i=1;i<=n;i++) ans = (ans * k) % MOD;
		return ans - 2;
	}

	DP[0] = 1;

	for(int i=1;i<5;i++) DP[i] = DP[i - 1] * k;

	DP[5] = (DP[4] * k) - 2;
	DP[6] = ((DP[5] * k) - (2 * k)) % MOD;

	for(int i=7;i<=n;i++){
		DP[i] = (k * DP[i - 1]) - (2 * DP[i - 5]) + DP[i - 7];
		DP[i] %= MOD;

		if(DP[i] < 0) DP[i] += MOD;
 	}

 	return DP[n];
}

int main()
{
	scanf("%d %d", &n, &k);

	printf("%lld", dynamic());

    return 0;
}