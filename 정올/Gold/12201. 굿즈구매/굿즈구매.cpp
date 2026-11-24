#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;

ll m;
vector<ll> v, sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    v.resize(n);
    sum.resize(n+1);
    
    ll p = LLONG_MAX;

    for(int i=0; i<n; i++){
        ll x, y;
        cin >> x >> y;

        v[i] = x;
        p = min(p, x + y);
    }

    sort(v.begin(), v.end());

    for (int i=0; i<n; i++) {
        sum[i + 1] = sum[i] + v[i];
    }

    ll ans = 0;
    for(int i=0; i<=n; i++){
        if(sum[i] > m) break;

        ll rem = m - sum[i];
        ll pairs = rem / p;

        ans = max(ans, i + pairs * 2);
    }

    cout << ans << '\n';

    return 0;
}