#include <bits/stdc++.h>

using namespace std;

int n, ans, DP[505][505];

int main()
{
	scanf("%d", &n);

	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			scanf("%d", &DP[i][j]);

            if(j == 1) DP[i][j] = DP[i - 1][j] + DP[i][j];
			else if(j == i) DP[i][j] = DP[i - 1][j - 1] + DP[i][j];
			else DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]) + DP[i][j];

			ans = max(ans, DP[i][j]);
		}
    }

	printf("%d", ans);
}
