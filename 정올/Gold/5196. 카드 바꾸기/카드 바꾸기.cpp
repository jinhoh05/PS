#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans;

ll x[505];
unordered_map<ll, int> mp;

vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    int k = 1;
    for (int i = 0; i < n; i++)
    {
        mp.clear();
        for (int j = i + 1; j < n; j++)
        {
            ll num = x[j] - x[i];
            ll denom = j - i;

            if (num % denom != 0) continue;

            ll d = num / denom;
            mp[d]++;

            ans = max(ans, mp[d] + 1);
        }
    }

    cout << n - ans;

    return 0;
}