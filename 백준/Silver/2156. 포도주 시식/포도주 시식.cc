#include <bits/stdc++.h>

using namespace std;

int n, ans;
int grape[10005], DP[10005];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=3;i<n+3;i++) cin >> grape[i];

    for(int i=3;i<n+3;i++){
        DP[i] = max({DP[i - 3] + grape[i - 1] + grape[i], DP[i - 2] + grape[i], DP[i - 1]});
        ans = max(DP[i], ans);
    }

    cout << ans;

    return 0;
}
