#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, c;

ll ans;
ll t[100005];

int check(ll mid){
    int bus=1, p=0;
    for(int i=1; i<n; i++){
        if(i - p + 1 > c || t[i] - t[p] > mid){
            bus++;
            p = i;
        }
    }
    return bus <= m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> c;
    for(int i=0; i<n; i++){
        cin >> t[i];
    }

    sort(t, t+n);

    ll l = 0, r = t[n-1]-t[0];
    ans = r;

    while(l <= r){
        ll mid = (l+r) / 2;

        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid+1;

    }

    cout << ans;

    return 0;
}