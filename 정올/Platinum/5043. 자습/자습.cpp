#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll n, m, ans;

ll l, r = 1LL << 60;

vector<int> v;
vector<ll> a, b;

int check(ll x){
    ll day = 0;

    for(ll i=0; i<n; i++){
        if(x <= a[i] * m) day += (x + a[i] - 1) / a[i];
        else day += m + (x - (a[i] * m) + b[i] - 1) / b[i];

        if(day > n*m) return 0;
    }

    return 1;
}

int main(){
    scanf("%lld %lld", &n, &m);
    for(ll i=0; i<n; i++){
        ll x;
        scanf("%lld", &x);
        a.push_back(x);
    }
    for(ll i=0; i<n; i++){
        ll x;
        scanf("%lld", &x);
        b.push_back(x);
    }

    for(ll i=0; i<n; i++) a[i] = max(a[i], b[i]);

    while(r - l > 1){
        ll mid = (l + r) / 2;

        if(check(mid)) l = mid;
        else r = mid;
    }

    printf("%lld", l);

    return 0;
}
