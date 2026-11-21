#include <bits/stdc++.h>

using namespace std;

int n;
int a[2005], b[2005];
int DP[2005][2005];

void dynamic(){
    for(int i=1;i<=n+1;i++) DP[0][i] = -1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1;j++){
            DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]);
            if(DP[i][j - 1] != -1 && a[i] > b[j - 1]){
                DP[i][j] = max(DP[i][j], DP[i][j - 1] + b[j - 1]);
            }
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];

    dynamic();

    int ans = 0;
    for(int i=1;i<=n+1;i++) ans = max(ans, DP[n][i]);

    cout << ans;

    return 0;
}
