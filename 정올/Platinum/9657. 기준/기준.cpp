#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int n, m, ans;

ll tree[800005];

pll arr[200005];
vector<pii> v, q;

void update(int node, int s, int e, int idx, int val)
{
    if (idx < s || idx > e) return;
    if (s == e)
    {
        tree[node] += val;
        return;
    }

    int mid = (s + e) / 2;
    if (idx <= mid) update(node * 2, s, mid, idx, val);
    else update(node * 2 + 1, mid + 1, e, idx, val);
    
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int s, int e, ll p)
{
    if (s == e) return s;

    int mid = (s + e) / 2;
    if (tree[node * 2] >= p) return query(node * 2, s, mid, p);   
    return query(node * 2 + 1, mid + 1, e, p - tree[node * 2]);   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        q.push_back({a, b});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        arr[i] = v[i];
    }

    ll p = 0;
    for (int i = 0; i < n; i++)
    {   
        int idx = lower_bound(v.begin(), v.end(), q[i]) - v.begin() + 1;
        update(1, 1, n, idx, q[i].second);
        
        p += q[i].second;
        cout << arr[query(1, 1, n, (p + 1) / 2) - 1].first << "\n";
    }

    return 0;
}