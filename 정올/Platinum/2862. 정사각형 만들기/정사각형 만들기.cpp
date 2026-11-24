#include <bits/stdc++.h>

using namespace std;

int n, m;
int DP[10005][105];

int dynamic(){
    if(n == m) return 1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
			DP[i][j] = 1 << 20;

			if(i == j) DP[i][j] = 1;

			else if(i >= j * 3) DP[i][j] = DP[i - j][j] + 1;

			else{
				for(int k=1;k<=j/2;k++){
					DP[i][j] = min(DP[i][j], DP[i][k] + DP[i][j - k]);
				}

				for(int k=1;k<=i/2;k++){
					DP[i][j] = min(DP[i][j], DP[k][j] + DP[i - k][j]);
				}
			}
		}
    }

    return DP[n][m];
}

int main()
{
    scanf("%d %d", &n, &m);

    if(n < m) swap(n, m);

    printf("%d", dynamic());

    return 0;
}