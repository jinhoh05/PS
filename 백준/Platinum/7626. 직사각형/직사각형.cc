#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll MAX = 4e5 + 5;

struct S{

    ll x, fin;
    pll y;

    bool operator<(const S &t)const{
        return x < t.x;
    }
};

int N;

ll tree[MAX * 4];
ll cnt[MAX * 4];

vector<S> v;
vector<ll> height;

void update(ll node, ll s, ll e, ll fs, ll fe, ll val)
{
    ll mid = (s + e) >> 1;

    if(e < fs || fe < s) return;

    if(fs <= s && e <= fe) cnt[node] += val;

    else
    {
        update(2 * node, s, mid, fs, fe, val);
        update(2 * node + 1, mid + 1, e, fs, fe, val);
    }

    if(cnt[node]) tree[node] = height[e] - height[s - 1];

    else
    {
        if(s == e) tree[node] = 0;
        else tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

void calc()
{
    ll ans = 0;

    for(ll i = 0; i < v.size(); i++)
    {
        if(i) ans += (tree[1] * (v[i].x - v[i - 1].x));

        ll s = lower_bound(height.begin(), height.end(), v[i].y.first) - height.begin();
        ll e = lower_bound(height.begin(), height.end(), v[i].y.second) - height.begin();

        update(1, 1, MAX, s + 1, e, v[i].fin);
    }

    printf("%lld", ans);
}

void sorting()
{
    sort(height.begin(), height.end());

    height.erase(unique(height.begin(), height.end()), height.end());

    sort(v.begin(), v.end());
}

void input()
{
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        ll a, b, c, d;

        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

        v.push_back({a, 1, {c + 1, d + 1}});
        v.push_back({b, -1, {c + 1, d + 1}});

        height.push_back(c + 1);
        height.push_back(d + 1);
    }
}

int main()
{
    input();

    sorting();

    calc();

    return 0;
}
