#include <bits/stdc++.h>

using namespace std;

int n, t;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> t;

    while(t--){
        int DP[2][100005], a[2][100005];

        cin >> n;

        for(int i=0;i<=1;i++){
            for(int j=0;j<n;j++){
                cin >> a[i][j];
            }
        }

        DP[0][0] = a[0][0];
        DP[1][0] = a[1][0];
        DP[0][1] = a[0][1] + DP[1][0];
        DP[1][1] = a[1][1] + DP[0][0];

        for(int i=2;i<n;i++){
            DP[0][i] = a[0][i] + max(DP[1][i - 1], DP[1][i - 2]);
            DP[1][i] = a[1][i] + max(DP[0][i - 1], DP[0][i - 2]);
        }

        cout << max(DP[0][n - 1], DP[1][n - 1]) << "\n";
    }

    return 0;
}
