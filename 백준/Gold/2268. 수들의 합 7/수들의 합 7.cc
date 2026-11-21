#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
ll tree[4000005], a[1000005];

void update(ll x, ll val){
    for(;x<=n;x+=(x&-x)) tree[x] += val;
}

ll query(ll x){
    ll sum = 0;
    for(;x;x-=(x&-x)) sum += tree[x];
    return sum;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        ll x, b, c;
        cin >> x >> b >> c;

        if(x){        
            update(b, c - a[b]);
            a[b] = c;
        }
        
        else
        {
            if(b > c) swap(b, c);
            cout << query(c) - query(b - 1) << "\n";
        }
    }
    
    return 0;
}
