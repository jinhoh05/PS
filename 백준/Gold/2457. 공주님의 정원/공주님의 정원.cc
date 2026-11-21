#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int n;

vector<pii> v;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        pii a, b;
        cin >> a.first >> a.second >> b.first >> b.second;

        v.push_back({a.first * 100 + a.second, b.first * 100 + b.second});
    }

    sort(v.begin(), v.end());

    int idx = -1, temp = 0, ans = 0;

    for(int i = 301; i <= 1130 && idx < n; i = temp)
    {
        bool flag = false;
        idx++;

        for(int j = idx; j < v.size(); j++)
        {
            if(v[j].first > i) break;

            if(temp < v[j].second)
            {
                temp = v[j].second;
                idx = j;
                flag = true;
            }
        }

        if(flag) ans++;

        else
        {
            cout << 0;
            return 0;
        }
    }

    cout << ans;
}
