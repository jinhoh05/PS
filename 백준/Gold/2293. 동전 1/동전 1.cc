#include <bits/stdc++.h>

using namespace std;

int n, k;
int coin[105], DP[10005];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    for(int i=1;i<=n;i++) cin >> coin[i];

    DP[0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(j >= coin[i]) DP[j] += DP[j - coin[i]];
        }
    }

    cout << DP[k];

    return 0;
}
