#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000000;

int n, k;
int DP[205][205];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    for(int i=0;i<=n;i++) DP[1][i] = 1;
    for(int i=0;i<=k;i++) DP[i][0] = 1;

    for(int i=2;i<=k;i++){
        for(int j=1;j<=n;j++){
            DP[i][j] = (DP[i][j - 1] + DP[i - 1][j]) % MOD;
        }
    }

    cout << DP[k][n];

    return 0;
}
