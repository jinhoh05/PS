#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Data
{
    ll p, br;
};

ll n, k, m, cnt;
ll a[300005], ans[500005];
ll l;

vector<int> v;
queue<Data> q;
unordered_map<ll, int> mp;

void push(ll p, int br)
{
    if (p < 0 || p > l) return;
    
    if (mp[p] == -1) return;

    if (!mp[p])
    {
        mp[p] = br;
        ans[br]++;
        cnt++;
        q.push({p, br});
    }

    else if (mp[p] > br)
    {
        ans[mp[p]]--;
        mp[p] = br;
        ans[br]++;
        q.push({p, br});
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> l >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]] = -1;
        q.push({a[i], 0});
    }

    ans[0] = cnt = n;
    while (!q.empty())
    {
        auto [p, br] = q.front();
        q.pop();

        if (cnt >= k) break;
        if (br == k) continue;
        
        push(p + 1, br + 1);
        push(p - 1, br + 1);
    }

    int i = 0;
    while (k > 0)
    {
        for (int j = 0; j < min(ans[i], k); j++) cout << i << "\n";
        k -= ans[i++];
    }

    return 0;
}