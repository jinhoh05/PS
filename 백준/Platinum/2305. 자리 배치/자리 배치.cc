#include <bits/stdc++.h>

using namespace std;

int n, k;
int fibo[50], fibo_sum[50];
int DP[50];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

	fibo[0] = fibo[1] = fibo_sum[0] = 1;
	fibo_sum[1] = 2;

	for(int i=2;i<=n;i++){
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo_sum[i] = fibo_sum[i - 1] + fibo[i];
	}

	DP[0] = DP[1] = 1;
	DP[2] = 2;

	for(int i=3;i<=n;i++){
		DP[i] = DP[i - 1] + DP[i - 2] + fibo_sum[i - 2] + fibo_sum[i - 3];
	}

	cout << (DP[n - k + 1] * fibo[k - 1]) + (DP[k] * fibo[n - k]) - (fibo[k - 1] * fibo[n - k]);

    return 0;
}
