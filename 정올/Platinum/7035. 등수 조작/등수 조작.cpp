#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, q, ans;
int a[100005];
int tree[400005];

vector<int> v;

void update(int node, int s, int e, int idx, int cnt)
{
    if (idx < s || idx > e) return;
    if (s == e){
        tree[node] += cnt;
        return;
    }

    int mid = (s + e) / 2;
    update(node * 2, s, mid, idx, cnt);
    update(node * 2 + 1, mid + 1, e, idx, cnt);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int s, int e, int fs, int fe)
{
    if (e < fs || s > fe) return 0;
    if (fs <= s && e <= fe) return tree[node];
    int mid = (s + e) / 2;
    return query(node * 2, s, mid, fs, fe) + query(node * 2 + 1, mid + 1, e, fs, fe);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(1, 1, 100000, a[i], 1);
    }

    while (q--)
    {
        int t, x, y;
        cin >> t;

        if (t == 1)
        {
            cin >> x;
            cout << query(1, 1, 100000, a[x] + 1, 100000) + 1 << "\n";
        }

        else
        {
            cin >> x >> y;
            
            update(1, 1, 100000, a[x], -1);
            a[x] = y;
            update(1, 1, 100000, a[x], 1);
        }
    }

    return 0;
}