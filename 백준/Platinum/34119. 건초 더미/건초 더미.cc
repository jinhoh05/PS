#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Data
{
    ll ord, p, idx;

    bool operator<(const Data &t)const{
        if (ord == t.ord) return p < t.p;
        return ord < t.ord;
    }
};

struct Out
{
    ll ans, idx;

    bool operator<(const Out &t)const{
        return idx < t.idx;
    }
};

ll n, m, ans, q;
ll arr[300005];

Data arrow[300005];
vector<Out> v;
vector<ll> def;

ll sum_tree[300005];
ll cnt_tree[300005];

ll sum, cnt;

void update(int x, ll val)
{
    for (; x <= def.size(); x += (x & -x))
    {
        sum_tree[x] += val;
        cnt_tree[x]++;
    }    
}

ll sum_query(int x)
{
    ll sum = 0;
    for (; x; x -= (x & -x)) sum += sum_tree[x];
    return sum;
}

ll cnt_query(int x)
{
    ll sum = 0;
    for (; x; x -= (x & -x)) sum += cnt_tree[x];
    return sum;
}

ll query(ll p)
{
    if (sum < p) return -1;
    
    int l = 1;
    int r = def.size();

    while (l < r)
    {
        int mid = (l + r) / 2;
        if (sum_query(mid) >= p) r = mid;
        else l = mid + 1;
    }

    ll pre_sum = sum_query(l - 1);
    ll pre_cnt = cnt_query(l - 1);
    ll val = def[def.size() - l];

    ll need = (p - pre_sum + val - 1) / val;
    return pre_cnt + need;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        def.push_back(arr[i]);
    }

    for (int i = 0; i < q; i++)
    {
        cin >> arrow[i].ord >> arrow[i].p;
        arrow[i].idx = i; 
    }

    sort(arrow, arrow + q);
    sort(def.begin(), def.end());
    def.erase(unique(def.begin(), def.end()), def.end());

    int cur = 0;
    for (int i = 0; i < q; i++)
    {
        while (cur < arrow[i].ord)
        {
            int idx = lower_bound(def.begin(), def.end(), arr[cur]) - def.begin();
            idx = def.size() - idx;

            update(idx, arr[cur]);

            sum += arr[cur];
            cnt++;
            cur++;
        }

        v.push_back({query(arrow[i].p), arrow[i].idx});    
    }

    sort(v.begin(), v.end());

    for (auto [ans, idx] : v)
    {
        cout << ans << "\n";
    }

    return 0;
}