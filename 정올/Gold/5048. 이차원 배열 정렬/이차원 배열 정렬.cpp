#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll n, m, k, ans;

vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    ll l = 1, r = k;
    while (l <= r)
    {
        ll mid = (l + r) / 2, cnt = 0;
        for (int i = 1; i <= n; i++) cnt += min(n, mid / i);

        if (cnt < k) l = mid + 1;
        else
        {
            r = mid - 1;
            ans = mid;
        }
    }

    cout << ans;

    return 0;
}