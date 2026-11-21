#include <bits/stdc++.h>

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())

using namespace std;
using ll = long long;
using p = pair<ll, ll>;

const ll mod = 1e9+7;

int n;
vector<p> g[101010];
ll ans;

ll f(int v, int b)
{
    ll now = 1;
    for(auto i : g[v]) if(i.x != b){
        ll t = f(i.x, v) * i.y % mod;
        ans += now * t % mod; ans %= mod;
        now += t; now %= mod;
    }
    return now;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
   
    cin >> n;
    
    for(int i=1; i<n; i++){
        int s, e, x; cin >> s >> e >> x;
        g[s].emplace_back(e, x);
        g[e].emplace_back(s, x);
    }
    
    f(1, 0);
    
    cout << ans;
    
    return 0;
}