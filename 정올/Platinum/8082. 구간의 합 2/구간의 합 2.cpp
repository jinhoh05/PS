#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, q, m, ans;
ll arr[1000005];
ll tree[4000005], lazy[4000005];

vector<int> v;

void propagate(int node, int l, int r)
{
    if (!lazy[node]) return;
    tree[node] += lazy[node] * (r - l + 1);

    if (l != r)
    {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }

    lazy[node] = 0;
}

void update(int node, int l, int r, int fl, int fr, ll val)
{
    propagate(node, l, r);  

    if (fr < l || fl > r) return;
    if (fl <= l && r <= fr)
    {
        lazy[node] += val;
        propagate(node, l, r);
        return;
    }

    int mid = (l + r) / 2;
    update(node * 2, l, mid, fl, fr, val);
    update(node * 2 + 1, mid + 1, r, fl, fr, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int l, int r, int fl, int fr){
    propagate(node, l, r);

    if (fr < l || fl > r) return 0;
    if (fl <= l && r <= fr) return tree[node];
    ll mid = (l + r) / 2;
    return query(node * 2, l, mid, fl, fr) + query(node * 2 + 1, mid + 1, r, fl, fr);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        update(1, 1, n, i, i, arr[i]);
    }

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int num, f, r, x;
        cin >> num >> f >> r;
        
        if (num == 1) 
        {
            cin >> x;
            update(1, 1, n, f, r, x);
        }

        else 
        {
            cout << query(1, 1, n, f, r) << "\n";
        }
    }

    return 0;
}