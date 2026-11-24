#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, q;
int p, a;

ll pre[200005];

vector<int> idx[200005];
vector<ll> t_pre[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;
    for(int i=1; i<=n; i++){
        cin >> p >> a;
        pre[i] = pre[i-1] + p;
        idx[a].push_back(i);
        t_pre[a].push_back(p);
    }

    for(int i=1; i<=m; i++){
        vector<ll> prefix(1, 0);

        for(ll cost : t_pre[i]){
            prefix.push_back(prefix.back() + cost);
        }

        t_pre[i] = move(prefix);
    }
    
    for(int i=0; i<q; i++){
        int t, l, r;
        cin >> t >> l >> r;

        ll total = pre[r] - pre[l-1];

        int l_idx = lower_bound(idx[t].begin(), idx[t].end(), l) - idx[t].begin();
        int r_idx = upper_bound(idx[t].begin(), idx[t].end(), r) - idx[t].begin();  
        ll product = t_pre[t][r_idx] - t_pre[t][l_idx];
        
        cout << (total - product/2) << "\n";
    }

    return 0;
}