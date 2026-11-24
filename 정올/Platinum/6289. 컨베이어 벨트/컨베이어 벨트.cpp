#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans;
int arr[150005], tree[600005];

vector<int> v;

void update(int node, int s, int e, int idx, int val)
{
    if (idx < s || idx > e) return;
    if (s == e)
    {
        tree[node] = val;
        return;
    }

    int mid = (s + e) / 2;
    update(node * 2, s, mid, idx, val);
    update(node * 2 + 1, mid + 1, e, idx, val);

    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int s, int e, int val)
{
    if (tree[node] < val) return -1;
    if (s == e) return s;

    int mid = (s + e) / 2;
    if (tree[node * 2] >= val)
    {
        return query(node * 2, s, mid, val);
    }
    return query(node * 2 + 1, mid + 1, e, val);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        update(1, 1, n, i, arr[i]);
    }

    while (m--)
    {
        int x;
        cin >> x;

        int idx = query(1, 1, n, x);
        if (idx == -1) cout << "0 ";
        else 
        {
            cout << idx << " ";
            arr[idx] -= x; 
            update(1, 1, n, idx, arr[idx]); 
        }
    }


    return 0;
}