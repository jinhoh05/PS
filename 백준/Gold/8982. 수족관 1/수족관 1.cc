#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int n, k, ans, water;
int a, b, c;
int h[2505];

pii arr[2505], d[2505];


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    n = (n - 1) >> 1;

    cin >> a >> b;

    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        arr[i] = {a, c};
        d[i] = {b, 0};
        cin >> c;
    }

    cin >> a >> b;

    cin >> k;

    while(k--){
        cin >> a >> b >> c >> b;
        int idx = lower_bound(arr, arr + n, pii(a, c)) - arr;
        h[idx] = 1;
    }

    for(int i=n-1;i>=0;i--){
        if(h[i]) water = d[i].first;
        else water = max(min(water, d[i].first), d[i].second);

        d[i].second = water;
    }

    water = 0;

    for(int i=0;i<n;i++){
        if(h[i]) water = d[i].first;
        else water = max(min(water, d[i].first), d[i].second);

        d[i].second = water;
    }

    for(int i=0;i<n;i++){
        ans += (arr[i].second - arr[i].first) * (d[i].first - d[i].second);
    }

    cout << ans;

    return 0;
}
