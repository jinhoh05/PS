#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll n, m, ans;
ll a[4005], b[4005], c[4005], d[4005];

vector<int> sum1, sum2;
vector<pii> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum1.push_back(a[i] + b[j]);
            sum2.push_back(c[i] + d[j]);
        }
    }

    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());

    v.push_back({sum1[0], 1});
    for (int i = 1; i < sum1.size(); i++)
    {
        if (v.back().first == sum1[i]) v.back().second++;
        else v.push_back({sum1[i], 1});
    }

    for (auto [cur, cnt] : v)
    {
        auto l = lower_bound(sum2.begin(), sum2.end(), -cur);
        auto r = upper_bound(sum2.begin(), sum2.end(), -cur);
        ans += cnt * (r - l);
    }

    cout << ans;

    return 0;
}