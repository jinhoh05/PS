#include <bits/stdc++.h>

using namespace std;

int n, ans;
int DP[20], t[20], p[20];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=n;i++) cin >> t[i] >> p[i];


    for(int i=1;i<=n+1;i++){
        for(int j=1;j<i;j++){
            DP[i] = max(DP[i], DP[j]);

            if(j + t[j] == i) DP[i] = max(DP[i], DP[j] + p[j]);
        }

        ans = max(ans, DP[i]);
    }

    cout << ans;

    return 0;
}
