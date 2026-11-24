#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, s;
ll mirror[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;
    for(int i=0; i<n; i++){
        cin >> mirror[i];
    }

    ll l=0, r=0;
    for(int i=0; i<n/2; i++) l += mirror[i];
    for(int i=n/2; i<n; i++) r += mirror[i];

    ll ans = 2*r - 2*l;
    ans = n%2 ? ans - s : ans + s;

    cout << ans;
}