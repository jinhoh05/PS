#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
ll ans, MAX;
ll tree[1000005];

void binary(){
    ll l = 0, r = MAX;

    while(l <= r){
        ll mid = (l + r) / 2;
        ll hap = 0;

        for(int i=0;i<n;i++){
            if(mid < tree[i]) hap += tree[i] - mid;
        }

        if(hap >= m){
            ans = max(ans, mid);
            l = mid + 1;
        }

        else r = mid - 1;
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> tree[i];
        MAX = max(tree[i], MAX);
    }

    binary();

    cout << ans;

    return 0;
}
