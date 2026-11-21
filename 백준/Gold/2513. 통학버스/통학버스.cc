#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int n, s, k, ans;

vector<pii> v;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k >> s;

    v.resize(n);

    for(int i=0;i<n;i++) cin >> v[i].first >> v[i].second;

    v.push_back({s, 0});

    sort(v.begin(), v.end());

    int idx = lower_bound(v.begin(), v.end(), make_pair(s, 0)) - v.begin();

    for(int i=0;i<idx;i++){
        int d = 0, j;

        for(j=i;j<idx;j++){
            d += v[j].second;

            if(d > k){
                v[j].second = d - k;
                break;
            }
        }

        ans += (s - v[i].first) * 2;
        i = --j;
    }

    for(int i=n;i>idx;i--){
        int d = 0, j;

        for(j=i;j>idx;j--){
            d += v[j].second;

            if(d > k){
                v[j].second = d - k;
                break;
            }
        }

        ans += (v[i].first - s) * 2;
        i = ++j;
    }

    cout << ans;

    return 0;
}
