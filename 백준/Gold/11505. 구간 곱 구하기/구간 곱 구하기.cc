#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int divide = 1e9 + 7;

int n, m, k;
ll tree[4000005];

ll update(int node, int s, int e, int idx, int t){
    if(idx < s || idx > e) return tree[node];

    if(s == e) return tree[node] = t;

    int mid = (s + e) / 2;
    ll l = update(node * 2, s, mid, idx, t);
    ll r = update(node * 2 + 1, mid + 1, e, idx, t);

    return tree[node] = l * r % divide;
}

ll query(int node, int s, int e, int fs, int fe){
    if(s > fe || e < fs) return 1;

    else if(fs <= s && e <= fe) return tree[node];

    int mid = (s + e) / 2;

    ll l = query(node * 2, s, mid, fs, fe);
    ll r = query(node * 2 + 1, mid + 1, e, fs, fe);

    return l * r % divide;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;

    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        update(1, 1, n, i, a);
    }

    for(int i=1;i<=m+k;i++){
        int a, b, c;
        cin >> a >> b >> c;

        if(a == 1) update(1, 1, n, b, c);

        else cout << query(1, 1, n, b, c) << "\n";
    }

    return 0;
}
