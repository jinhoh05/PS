#include <bits/stdc++.h>
#include "gap.h"

using namespace std;
using ll = long long;

const ll MAXN = 1e18;

ll a[100005], k;

ll findGap(ll N){
    ll mn, mx;
    MinMax(1, MAXN, mn, mx);

    ll cur = (mx-mn+N-2) / (N-1);
    ll ans = cur, x, y, l=mn, i;

    for(i=mn; i+cur < mx; i += cur+1){
        MinMax(i, i+cur, x, y);

        if(x != -1){
            ans = max(ans, x-l);
            l=y;
        }
    }

    MinMax(i, mx, x, y);
    if(x != -1) ans=max(ans, x-l);
    return ans;
}
