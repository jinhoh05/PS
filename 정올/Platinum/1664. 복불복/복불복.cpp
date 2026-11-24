#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

/// 1번 돌렸을때 i개 가져갈때 가능한 경우의 수 : C_i
/// C_0 + C_1*x + C_2*x^2 + ... + C_k*x^k

/// n번 돌렸을 때
/// (C_0 + C_1*x + C_2*x^2 + ... + C_k*x^k) ^ n
/// A_0 + A_1*x + A_2*x + ... + A_k*x
/// A_i = C_nk*x^(nk)

const int MOD = 42043;

ll n, m;
ll k, t;

vector<ll> calc(vector<ll> &a, vector<ll> &b){
    vector<ll> v;
    for(int i=0; i<min((ll)a.size(), k+3); i++){
        for(int j=0; j<min((ll)b.size(), k+3); j++){
            while(v.size() <= i+j) v.push_back(0);
            a[i] %= MOD;
            b[j] %= MOD;
            v[i+j] = (v[i+j] + (a[i]*b[j]%MOD)) % MOD;
        }
    }

    return v;
}

vector<ll> check(vector<ll> &x, int y){
    vector<ll> v={1};

    while(y > 0){
        if(y % 2) v = calc(v, x);
        x = calc(x, x);
        y /= 2;
    }

    return v;
}

int main(){

    scanf("%lld %lld %lld", &n, &k, &t);

    vector<ll> rock(k+2);
    for(int i=0; i<t; i++){
        int num;
        scanf("%d", &num);
        if(num <= k) rock[num]++;
    }

    vector<ll> ans = check(rock, n);

    ll p=0;
    for(int i=0; i<=k; i++){
        p = (p+ans[i]) % MOD;
    }

    printf("%lld", p);

    return 0;
}