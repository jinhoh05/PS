#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int n, s, sum, ans;

vector<int> d, dd;
vector<pii> v;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> s;

    v.resize(n + 1), d.resize(n + 1), dd.resize(n + 1);

    for(int i = 1; i <= n; i++) cin >> v[i].first >> v[i].second;

    sort(v.begin() + 1, v.end());

    for(int i = 1; i <= n; i++)
    {
        for(dd[i] = dd[i - 1] + 1; dd[i] < i; dd[i]++)
        {
            if(v[i].first - v[dd[i]].first < s) break;
        }

        dd[i]--;
    }

    for(int i = 1; i <= n; i++)
    {
        d[i] = d[dd[i]] + v[i].second;
        d[i] = max(d[i], d[i - 1]);
    }

    cout << d[n];

    return 0;
}
