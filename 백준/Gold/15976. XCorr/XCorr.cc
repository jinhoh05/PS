#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 300005;

int n, m;
ll a[MAX], ai[MAX];
ll b[MAX], bi[MAX];
ll ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) cin >> ai[i] >> a[i];

    cin >> m;
    for(int i=0;i<m;i++) cin >> bi[i] >> b[i];

    for(int i=1;i<m;i++) b[i] += b[i - 1];

    int x, y;
    cin >> x >> y;

    for(int i=0;i<n;i++){
        ll s = lower_bound(bi, bi + m, ai[i] + x) - bi - 1;
        ll e = upper_bound(bi, bi + m, ai[i] + y) - bi - 1;
        ans += a[i] * (b[e] - b[s]);
    }

    cout << ans;

    return 0;
}
