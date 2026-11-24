#include <bits/stdc++.h>

using namespace std;

/// __builtin_popcount()

const int MOD = 1e4;

int n;
int DP[1 << 16];
int table[20][20];

int dynamic()
{
	for(int i = 0; i < (1 << n); i++) DP[i] = 1;

	for(int i = 1; i < (1 << n); i++)
	{
		int bit = __builtin_popcount(i);
		int temp = 0;

		for(int j = 0; j < n; j++)
		{
			if(i & (1 << j))
			{
				temp += DP[i ^ (1 << j)] * table[bit][j] % MOD;
			}
		}

		DP[i] = temp % MOD;
	}

	return DP[(1 << n) - 1];
}

void input(){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &table[i][j]);
}

int main()
{
	input();

	printf("%d", dynamic());

    return 0;
}