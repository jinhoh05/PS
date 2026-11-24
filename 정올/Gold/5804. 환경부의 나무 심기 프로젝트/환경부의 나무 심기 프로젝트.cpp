#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, k;
ll loc[200005];
ll l=1, r, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> loc[i];
    }

    sort(loc, loc+n);

    r = loc[n-1] - loc[0];
    while(l <= r){
        ll mid = (l+r) / 2;
        ll cur = loc[0], cnt = 1;

        for(int i=1; i<n; i++){
            if(loc[i] - cur >= mid){
                cur = loc[i];
                cnt++;
            }
        }

        if(cnt >= k){ 
            l = mid+1;
            ans = mid;
        }
        else r = mid-1;
    }

    cout << ans;
}