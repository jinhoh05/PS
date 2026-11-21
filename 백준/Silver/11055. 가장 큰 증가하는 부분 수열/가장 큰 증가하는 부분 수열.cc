#include <bits/stdc++.h>

using namespace std;

int n, ans;
int a[1005], DP[1005];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=1;i<=n;i++){
        DP[i] = a[i];

        for(int j=1;j<i;j++){
            int val = DP[j] + a[i];
            if(a[j] < a[i] && DP[i] < val) DP[i] = val;
        }

        ans = max(ans, DP[i]);
    }

    cout << ans;

    return 0;
}
