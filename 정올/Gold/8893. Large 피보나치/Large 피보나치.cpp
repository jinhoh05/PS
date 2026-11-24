#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

ll n;

struct mt{
    ll a, b, c, d;
};

mt mult(mt &x, mt &y){
    return {
        (x.a * y.a + x.b * y.c) % mod,
        (x.a * y.b + x.b * y.d) % mod,
        (x.c * y.a + x.d * y.c) % mod,
        (x.c * y.b + x.d * y.d) % mod   
    };
}

mt matrix(mt m, ll ex){
    mt res = {1, 0, 0, 1};

    while(ex > 0){
        if(ex % 2 == 1) res = mult(res, m);
        m = mult(m, m);
        ex /= 2;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    while(cin >> n && n != -1){
        mt m = {1, 1, 1, 0};
        m = matrix(m, n);
        cout << m.b << '\n';
    }
    

    return 0;
}