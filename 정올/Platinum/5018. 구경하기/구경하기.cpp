#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, p, q;
int DP[2005][2005];

ll event[2005];

bool dynamic(ll w){
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            DP[i][j] = 1e9;

    DP[0][0] = 0;

    for(int i=1; i<=n; i++){
        int P = lower_bound(event + 1, event + 1 + n, event[i] - w + 1) - event - 1;
        int Q = lower_bound(event + 1, event + 1 + n, event[i] - (2*w) + 1) - event - 1;

        for(int j=0; j<=p; j++){
            if(j) DP[i][j] = min(DP[i][j], DP[P][j-1]);
            DP[i][j] = min(DP[i][j], DP[Q][j] + 1);
        }
    }

    for(int i=0; i<=p; i++){
        if(DP[n][i] <= q) return true;
    }

    return false;
}

int main()
{
    scanf("%d %d %d", &n, &p, &q);

    for(int i=1; i<=n; i++){
        scanf("%lld", &event[i]);
    }

    sort(event + 1, event + 1 + n);

    p = min(p, n), q = min(q, n);

    ll l = 1, r = 1e9 + 10;
    while(l < r){
        ll mid = (l + r) / 2;

        if(dynamic(mid)) r = mid;
        else l = mid + 1;
    }

    printf("%lld", r);

    return 0;
}
