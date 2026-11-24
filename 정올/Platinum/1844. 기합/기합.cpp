#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = 1e9;

int n, m, ans;
int arr[200005], pos[200005];

vector<int> v;

struct Node {
    int mn, mx;
} tree[800005];

Node combine(const Node &a, const Node &b)
{
    return {min(a.mn, b.mn), max(a.mx, b.mx)};
}

void update(int node, int s, int e, int idx, int val)
{
    if (idx < s || idx > e) return;
    if (s == e)
    {
        tree[node] = {val, val};
        return;
    }

    int mid = (s + e) / 2;
    update(node * 2, s, mid, idx, val);
    update(node * 2 + 1, mid + 1, e, idx, val);

    tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
}

Node query(int node, int s, int e, int fs, int fe)
{
    if (e < fs || s > fe) return {INF, -INF};
    if (fs <= s && e <= fe) return tree[node];

    int mid = (s + e) / 2;
    return combine(query(node * 2, s, mid, fs, fe), query(node * 2 + 1, mid + 1, e, fs, fe));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pos[arr[i]] = i;
        update(1, 1, n, arr[i], i);
    }

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 2)
        {
            Node t = query(1, 1, n, b, c);
            if (t.mx - t.mn == c - b) cout << "YES\n";
            else cout << "NO\n";  
        }

        else
        {
            int pos_b = arr[b], pos_c = arr[c];
            swap(arr[b], arr[c]);

            pos[pos_b] = c;
            pos[pos_c] = b;
            update(1, 1, n, pos_b, c);
            update(1, 1, n, pos_c, b);
        }
        
    }


    return 0;
}
