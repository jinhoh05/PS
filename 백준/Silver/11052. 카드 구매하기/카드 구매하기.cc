#include <bits/stdc++.h>

using namespace std;

int n;
int p[1005], DP[1005];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=n;i++) cin >> p[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            DP[i] = max(DP[i], DP[i - j] + p[j]);
        }
    }

    cout << DP[n];

    return 0;
}
