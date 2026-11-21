#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int n, ans;
int DP[1005][15];

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=0;i<10;i++) DP[1][i] = 1;

    for(int i=2;i<=n;i++){
        for(int j=0;j<10;j++){
            for(int k=j;k<10;k++){
                DP[i][j] = (DP[i][j] + DP[i - 1][k]) % MOD;
            }
        }
    }

    for(int i=0;i<10;i++) ans = (ans + DP[n][i]) % MOD;

    cout << ans;

    return 0;
}
