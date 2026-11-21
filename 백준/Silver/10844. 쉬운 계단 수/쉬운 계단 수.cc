#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1000000000;

int n;
ll ans;
ll DP[105][15];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=9;i++) DP[1][i] = 1;

    for(int i=2;i<=n;i++){
        DP[i][0] = DP[i - 1][1];
        for(int j=1;j<=9;j++){
            DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % MOD;
        }
    }

    for(int i=0;i<=9;i++) ans += DP[n][i];

    cout << ans % MOD;

    return 0;
}
