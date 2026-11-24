#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;

ll m, ans;
vector<ll> l, r;
vector<ll> l_sum, r_sum;

void hap(const vector<ll> &v, int idx, ll sum, vector<ll> &v_sum)
{
    if (idx == v.size())
    {
        v_sum.push_back(sum);
        return;
    }

    hap(v, idx + 1, sum, v_sum);
    hap(v, idx + 1, sum + v[idx], v_sum);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;

        if (i < n / 2) l.push_back(x);
        else r.push_back(x);
    }

    hap(l, 0, 0, l_sum);
    hap(r, 0, 0, r_sum);

    sort(r_sum.begin(), r_sum.end());

    for(ll val : l_sum)
    {
        ll rem = m - val;
        
        auto idx1 = lower_bound(r_sum.begin(), r_sum.end(), rem);
        auto idx2 = upper_bound(r_sum.begin(), r_sum.end(), rem);

        ans += idx2 - idx1;
    }

    if (!m) ans--;
    cout << ans;

    return 0;
}