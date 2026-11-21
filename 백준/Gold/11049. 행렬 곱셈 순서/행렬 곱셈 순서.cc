#include <bits/stdc++.h>

using namespace std;

int n;
int a[510][2];
int DP[510][510];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=n;i++) cin >> a[i][0] >> a[i][1];

    for(int i=1;i<n;i++) DP[i][i + 1] = a[i][0] * a[i][1] * a[i + 1][1];

    for(int i=2;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            int k = i + j;
            for(int h=j;h<k;h++){
                int tmp = DP[j][h] + DP[h + 1][k] + a[j][0] * a[h][1] * a[k][1];
                if(!DP[j][k] || DP[j][k] > tmp) DP[j][k] = tmp;
            }
        }
    }

    cout << DP[1][n];

    return 0;
}
