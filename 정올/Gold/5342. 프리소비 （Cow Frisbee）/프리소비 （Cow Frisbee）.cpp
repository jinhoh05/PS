#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;

ll ans;

vector<ll> h;

void check(){
    vector<ll> v(n+1);
    for(int i=0; i<n; i++) v[h[i]] = i;

    set<int> st;
    for(int i=n; i; i--){
        auto p = st.insert(v[i]).first;
        if(next(p) != end(st)) ans += *next(p)-*p+1;
    }
}

int main(){
    //cin.tie(0)->ios_base::sync_with_stdio(false);

    scanf("%d", &n);

    h.resize(n);
    for(ll& i : h){
        scanf("%lld", &i);
    }

    check();
    reverse(h.begin(), h.end());
    check();

    printf("%lld", ans);

    return 0;
}
