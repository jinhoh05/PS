#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;

ll ans;

vector<int> v;

void check(ll a, ll b){
    ans = LLONG_MAX;

    for(ll i=0; (b >> i) > 0; i++){
        ll cur = 0;
        ll px2 = b >> i;
        ll px1 = a;

        while(px1 > px2){
            if(px1%2 == 1){
                px1++, cur++;
            }

            px1 /= 2;
            cur++;
        }

        cur += px2 - px1;
        cur += i;
        cur += __builtin_popcount(b & ((1 << i) - 1));

        ans = min(ans, cur);
    }
}

int main(){
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        ll a, b;
        scanf("%lld %lld", &a, &b);

        check(a, b);

        printf("%lld\n", ans);
    }

    return 0;
}
