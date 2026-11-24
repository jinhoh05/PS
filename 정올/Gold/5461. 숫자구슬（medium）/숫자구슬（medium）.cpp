#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m;
ll bead[100005];
ll l, r;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> bead[i];
        l = max(l, bead[i]);
        r += bead[i];
    }

    while(l < r){
        ll mid = (l+r) / 2;
        ll sum = 0, cnt = 1;

        for(int i=0; i<n; i++){
            if(sum + bead[i] > mid){
                sum = 0;
                cnt++;
            }
            sum += bead[i];
        }

        if(cnt <= m) r = mid;
        else l = mid+1;
    }

    cout << l;
}